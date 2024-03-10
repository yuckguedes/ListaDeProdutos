#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da lista
typedef struct Produto {
    char nome[50];
    float preco;
    struct Produto *prox;
} Produto;

// Função para inserir um produto no final da lista
Produto* inserirProduto(Produto *head, char nome[], float preco) {
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->preco = preco;
    novoProduto->prox = NULL;

    if (head == NULL) {
        return novoProduto;
    }

    Produto *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novoProduto;

    return head;
}

// Função para remover um produto da lista
Produto* removerProduto(Produto *head, char nome[]) {
    Produto *anterior = NULL;
    Produto *atual = head;

    // Procurando o produto na lista
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o produto não foi encontrado
    if (atual == NULL) {
        printf("Produto nao encontrado na lista.\n");
        return head;
    }

    // Removendo o produto da lista
    if (anterior == NULL) {
        head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Produto removido com sucesso.\n");

    return head;
}

// Função para exibir todos os produtos da lista
void exibirProdutos(Produto *head) {
    Produto *atual = head;

    while (atual != NULL) {
        printf("Nome: %s\nPreco: R$ %.2f\n\n", atual->nome, atual->preco);
        atual = atual->prox;
    }
}

int main() {
    Produto *listaProdutos = NULL;

    // Inserindo produtos na lista
    listaProdutos = inserirProduto(listaProdutos, "Leite", 5.99);
    listaProdutos = inserirProduto(listaProdutos, "Macarrao", 6.49);
    
     // Exibindo os produtos da lista
     exibirProdutos(listaProdutos);

     // Removendo um produto da lista
     listaProdutos = removerProduto(listaProdutos, "Leite");

     // Exibindo os produtos da lista após a remoção
     exibirProdutos(listaProdutos);

     return 0;
}