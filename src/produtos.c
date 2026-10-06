#include <stdio.h>
#include <string.h>
#include "produtos.h"

void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

int lerInteiroNaoNegativo(void) {
    int valor;
    int resultado;

    while (1) {
        resultado = scanf("%d", &valor);

        if (resultado == 1 && valor >= 0) {
            limparBuffer();
            return valor;
        }

        printf("Digite um numero inteiro valido: ");
        limparBuffer();
    }
}

float lerPrecoValido(void) {
    float preco;
    int resultado;

    while (1) {
        resultado = scanf("%f", &preco);

        if (resultado == 1 && preco >= 0) {
            limparBuffer();
            return preco;
        }

        printf("Digite um preco valido: ");
        limparBuffer();
    }
}

void cadastrarProduto(
    Produto produtos[],
    int *quantidade,
    int *proximo_id
) {
    Produto novo;

    if (*quantidade >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido!\n");
        return;
    }

    novo.id = *proximo_id;

    printf("\n===== CADASTRAR PRODUTO =====\n");

    printf("Nome do produto: ");
    fgets(novo.nome, TAM_NOME, stdin);

    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    if (strlen(novo.nome) == 0) {
        printf("\nO nome do produto nao pode ficar vazio.\n");
        return;
    }

    printf("Quantidade inicial: ");
    novo.quantidade = lerInteiroNaoNegativo();

    printf("Preco: ");
    novo.preco = lerPrecoValido();

    printf("Estoque minimo: ");
    novo.estoque_minimo = lerInteiroNaoNegativo();

    produtos[*quantidade] = novo;

    (*quantidade)++;
    (*proximo_id)++;

    printf("\nProduto cadastrado com sucesso!\n");
    printf("ID do produto: %d\n", novo.id);
}

void listarProdutos(
    Produto produtos[],
    int quantidade
) {
    int i;

    printf("\n===== LISTA DE PRODUTOS =====\n");

    if (quantidade == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {

        printf("\nID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Estoque minimo: %d\n", produtos[i].estoque_minimo);

        if (produtos[i].quantidade <= produtos[i].estoque_minimo) {
            printf("STATUS: ESTOQUE BAIXO!\n");
        } else {
            printf("STATUS: Estoque normal.\n");
        }
    }
}

void buscarProduto(
    Produto produtos[],
    int quantidade
) {
    int id;
    int i;
    int encontrado = 0;

    printf("\n===== BUSCAR PRODUTO =====\n");

    printf("Digite o ID do produto: ");
    id = lerInteiroNaoNegativo();

    for (i = 0; i < quantidade; i++) {

        if (produtos[i].id == id) {

            printf("\nProduto encontrado!\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            printf("Estoque minimo: %d\n", produtos[i].estoque_minimo);

            if (produtos[i].quantidade <= produtos[i].estoque_minimo) {
                printf("STATUS: ESTOQUE BAIXO!\n");
            } else {
                printf("STATUS: Estoque normal.\n");
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }
}

void alterarProduto(
    Produto produtos[],
    int quantidade
) {
    int id;
    int i;
    int encontrado = 0;

    printf("\n===== ALTERAR PRODUTO =====\n");

    printf("Digite o ID do produto: ");
    id = lerInteiroNaoNegativo();

    for (i = 0; i < quantidade; i++) {

        if (produtos[i].id == id) {

            printf("\nProduto encontrado!\n");

            printf("Novo nome: ");
            fgets(produtos[i].nome, TAM_NOME, stdin);

            produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

            if (strlen(produtos[i].nome) == 0) {
                printf("\nO nome do produto nao pode ficar vazio.\n");
                return;
            }

            printf("Nova quantidade: ");
            produtos[i].quantidade = lerInteiroNaoNegativo();

            printf("Novo preco: ");
            produtos[i].preco = lerPrecoValido();

            printf("Novo estoque minimo: ");
            produtos[i].estoque_minimo = lerInteiroNaoNegativo();

            printf("\nProduto alterado com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }
}

void excluirProduto(
    Produto produtos[],
    int *quantidade
) {
    int id;
    int i;
    int j;
    int encontrado = 0;

    printf("\n===== EXCLUIR PRODUTO =====\n");

    printf("Digite o ID do produto: ");
    id = lerInteiroNaoNegativo();

    for (i = 0; i < *quantidade; i++) {

        if (produtos[i].id == id) {

            for (j = i; j < *quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];
            }

            (*quantidade)--;

            printf("\nProduto excluido com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }
}

void registrarEntrada(
    Produto produtos[],
    int quantidade
) {
    int id;
    int quantidade_entrada;
    int i;
    int encontrado = 0;

    printf("\n===== REGISTRAR ENTRADA =====\n");

    printf("Digite o ID do produto: ");
    id = lerInteiroNaoNegativo();

    for (i = 0; i < quantidade; i++) {

        if (produtos[i].id == id) {

            printf("Quantidade de entrada: ");
            quantidade_entrada = lerInteiroNaoNegativo();

            if (quantidade_entrada == 0) {
                printf("\nA quantidade deve ser maior que zero.\n");
                return;
            }

            produtos[i].quantidade += quantidade_entrada;

            printf("\nEntrada registrada com sucesso!\n");
            printf("Novo estoque: %d\n", produtos[i].quantidade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }
}

void registrarSaida(
    Produto produtos[],
    int quantidade
) {
    int id;
    int quantidade_saida;
    int i;
    int encontrado = 0;

    printf("\n===== REGISTRAR SAIDA =====\n");

    printf("Digite o ID do produto: ");
    id = lerInteiroNaoNegativo();

    for (i = 0; i < quantidade; i++) {

        if (produtos[i].id == id) {

            printf("Quantidade de saida: ");
            quantidade_saida = lerInteiroNaoNegativo();

            if (quantidade_saida == 0) {
                printf("\nA quantidade deve ser maior que zero.\n");
                return;
            }

            if (quantidade_saida > produtos[i].quantidade) {
                printf("\nEstoque insuficiente!\n");
                printf("Estoque atual: %d\n", produtos[i].quantidade);
                return;
            }

            produtos[i].quantidade -= quantidade_saida;

            printf("\nSaida registrada com sucesso!\n");
            printf("Novo estoque: %d\n", produtos[i].quantidade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }
}

void produtosEstoqueBaixo(
    Produto produtos[],
    int quantidade
) {
    int i;
    int encontrados = 0;

    printf("\n===== PRODUTOS COM ESTOQUE BAIXO =====\n");

    for (i = 0; i < quantidade; i++) {

        if (produtos[i].quantidade <= produtos[i].estoque_minimo) {

            printf("\nID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade atual: %d\n", produtos[i].quantidade);
            printf("Estoque minimo: %d\n", produtos[i].estoque_minimo);

            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum produto com estoque baixo.\n");
    }
}

void salvarProdutos(
    Produto produtos[],
    int quantidade
) {
    FILE *arquivo;

    arquivo = fopen(NOME_ARQUIVO, "wb");

    if (arquivo == NULL) {
        printf("\nErro ao salvar os produtos.\n");
        return;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);
    fwrite(produtos, sizeof(Produto), quantidade, arquivo);

    fclose(arquivo);
}

void carregarProdutos(
    Produto produtos[],
    int *quantidade,
    int *proximo_id
) {
    FILE *arquivo;
    int i;
    int maior_id = 0;

    arquivo = fopen(NOME_ARQUIVO, "rb");

    if (arquivo == NULL) {
        *quantidade = 0;
        *proximo_id = 1;
        return;
    }

    fread(quantidade, sizeof(int), 1, arquivo);
    fread(produtos, sizeof(Produto), *quantidade, arquivo);

    fclose(arquivo);

    for (i = 0; i < *quantidade; i++) {

        if (produtos[i].id > maior_id) {
            maior_id = produtos[i].id;
        }
    }

    *proximo_id = maior_id + 1;
}
