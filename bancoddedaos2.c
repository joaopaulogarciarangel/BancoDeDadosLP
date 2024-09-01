#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[100];
    double preco;
    int estoque;
};

int main() {
    struct Produto produtos[100]; // Array de structs para armazenar até 100 produtos
    int num_produtos = 0;         // Contador para o número de produtos adicionados

    while (1) {
        int opcao;
        printf("=== Menu de Opções ===\n1. Inserir produto\n2. Listar todos os produtos\n3. Buscar produto por nome\n4. Excluir produto por nome\n5. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: {
                // Inserir um novo produto
                struct Produto novo_produto;
                printf("Digite o código do produto: ");
                scanf("%d", &novo_produto.codigo);
                getchar(); 
                int codigo_existe = 0;
                for (int i = 0; i < num_produtos; i++) {
                    if (novo_produto.codigo == produtos[i].codigo) {
                        printf("Não pode inserir dois produtos com mesmo código!\n");
                        codigo_existe = 1;
                        break;
                    }
                }
                if (codigo_existe == 1) {
                    break;
                }
                if(novo_produto.codigo<0){
                    printf("Impossibilidade de inserir código com número negativo!\n");
                    break;
                }

                printf("Digite o nome do produto: ");
                fgets(novo_produto.nome, sizeof(novo_produto.nome), stdin);
                novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0'; 
                printf("Digite o preço do produto: ");
                scanf("%lf", &novo_produto.preco);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &novo_produto.estoque);
                printf("Produto inserido com sucesso!\n\n");

                produtos[num_produtos] = novo_produto; // Adiciona o produto ao array
                num_produtos++;
                break;
            }
            case 2: {
                // Listar todos os produtos não excluídos
                for (int i = 0; i < num_produtos; i++) {
                    if (produtos[i].codigo != -8) { // Ignora produtos excluídos
                        printf("Código: %d,Nome: %s,Preço: %.2lf,Estoque: %d\n\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                    }
                }
                break;
            }
            case 3: {
                // Buscar produto por nome
                char nome_busca[100];
                printf("Digite o nome do produto: ");
                fgets(nome_busca, sizeof(nome_busca), stdin);
                nome_busca[strcspn(nome_busca, "\n")] = '\0'; 
                int produto_encontrado = 0;
                for (int i = 0; i < num_produtos; i++) {
                    if (strcmp(nome_busca, produtos[i].nome) == 0 && produtos[i].codigo != -8) { // Ignorar produtos excluídos
                        printf("Código: %d\nNome: %s\nPreço: %.2lf\nEstoque: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                        produto_encontrado = 1;
                        break;
                    }
                }

                if (produto_encontrado == 0) {
                    printf("Produto não encontrado.\n");
                }

                break;
            }
            case 4: {
                // Excluir produto por nome
                char nome_busca[100];
                printf("Digite o nome do produto: ");
                fgets(nome_busca, sizeof(nome_busca), stdin);
                nome_busca[strcspn(nome_busca, "\n")] = '\0'; 
                
                int produto_encontrado = 0;
                for (int i = 0; i < num_produtos; i++) {
                    if (strcmp(nome_busca, produtos[i].nome) == 0 && produtos[i].codigo != -8) {
                        produtos[i].codigo = -8;
                        strcpy(produtos[i].nome, "Excluído");
                        produtos[i].preco = -8.0;
                        produtos[i].estoque = -8;
                        produto_encontrado = 1;
                        printf("Produto excluído com sucesso.\n");
                        break;
                    }
                }

                if (produto_encontrado == 0) {
                    printf("Produto não encontrado.\n");
                }

                break;
            }
            case 5:
                // Sair do programa
                printf("Saindo do programa...");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}
