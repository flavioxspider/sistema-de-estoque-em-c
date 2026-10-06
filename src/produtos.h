#ifndef PRODUTOS_H
#define PRODUTOS_H

#define MAX_PRODUTOS 100
#define TAM_NOME 100
#define NOME_ARQUIVO "produtos.dat"

typedef struct {
    int id;
    char nome[TAM_NOME];
    int quantidade;
    float preco;
    int estoque_minimo;
} Produto;

void limparBuffer(void);

int lerInteiroNaoNegativo(void);

float lerPrecoValido(void);

void cadastrarProduto(
    Produto produtos[],
    int *quantidade,
    int *proximo_id
);

void listarProdutos(
    Produto produtos[],
    int quantidade
);

void buscarProduto(
    Produto produtos[],
    int quantidade
);

void alterarProduto(
    Produto produtos[],
    int quantidade
);

void excluirProduto(
    Produto produtos[],
    int *quantidade
);

void registrarEntrada(
    Produto produtos[],
    int quantidade
);

void registrarSaida(
    Produto produtos[],
    int quantidade
);

void produtosEstoqueBaixo(
    Produto produtos[],
    int quantidade
);

void salvarProdutos(
    Produto produtos[],
    int quantidade
);

void carregarProdutos(
    Produto produtos[],
    int *quantidade,
    int *proximo_id
);

#endif
