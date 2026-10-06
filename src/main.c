#include <stdio.h>
#include "produtos.h"

int main(void) {

    Produto produtos[MAX_PRODUTOS];

    int quantidade = 0;
    int proximo_id = 1;
    int opcao;

    carregarProdutos(
        produtos,
        &quantidade,
        &proximo_id
    );

    do {

        printf("\n===== SISTEMA DE CONTROLE DE ESTOQUE =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Alterar produto\n");
        printf("5 - Excluir produto\n");
        printf("6 - Registrar entrada\n");
        printf("7 - Registrar saida\n");
        printf("8 - Produtos com estoque baixo\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");

        opcao = lerInteiroNaoNegativo();

        switch (opcao) {

            case 1:
                cadastrarProduto(
                    produtos,
                    &quantidade,
                    &proximo_id
                );
                break;

            case 2:
                listarProdutos(
                    produtos,
                    quantidade
                );
                break;

            case 3:
                buscarProduto(
                    produtos,
                    quantidade
                );
                break;

            case 4:
                alterarProduto(
                    produtos,
                    quantidade
                );
                break;

            case 5:
                excluirProduto(
                    produtos,
                    &quantidade
                );
                break;

            case 6:
                registrarEntrada(
                    produtos,
                    quantidade
                );
                break;

            case 7:
                registrarSaida(
                    produtos,
                    quantidade
                );
                break;

            case 8:
                produtosEstoqueBaixo(
                    produtos,
                    quantidade
                );
                break;

            case 0:

                salvarProdutos(
                    produtos,
                    quantidade
                );

                printf("\nDados salvos com sucesso!\n");
                printf("Encerrando o sistema...\n");

                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
