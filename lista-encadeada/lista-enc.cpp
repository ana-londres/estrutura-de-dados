#include <iostream>
#include "lista-enc.h"

using namespace std;

ListaEncadeada::ListaEncadeada() : head(nullptr), tamanho(0) {}

ListaEncadeada::~ListaEncadeada() {
    node* atual = head;
    while (atual != nullptr) {
        node* prox = atual->prox;
        delete atual;
        atual = prox;
    }
}

bool ListaEncadeada::vazia() const {
    return tamanho == 0;
}

int ListaEncadeada::obterTam() const {
    return tamanho;
}

int ListaEncadeada::obterPos(int posicao) const {
    if (posicao < 1 || posicao > tamanho) {
        return -1; 
    }

    node* atual = head;
    for (int i = 1; i < posicao; ++i) {
        atual = atual->prox;
    }
    return atual->dado;
}

void ListaEncadeada::modificaPos(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho) {
        cout << "Posicao inexistente" << endl;
        return;
    }

    node* atual = head;
    for (int i = 1; i < posicao; ++i) {
        atual = atual->prox;
    }
    atual->dado = valor;
}

void ListaEncadeada::inserir(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho + 1) {
        cout << "Posicao inexistente" << endl;
        return;
    }

    node* novoNode = new node(valor);
    if (posicao == 1) {
        novoNode->prox = head;
        head = novoNode;
    } else {
        node* atual = head;
        for (int i = 1; i < posicao - 1; ++i) {
            atual = atual->prox;
        }
        novoNode->prox = atual->prox;
        atual->prox = novoNode;
    }
    ++tamanho;
}

void ListaEncadeada::remover(int posicao) {
    if (posicao < 1 || posicao > tamanho) {
        cout << "Posicao inexistente" << endl;
        return;
    }

    node* atual = head;
    if (posicao == 1) {
        head = head->prox;
    } else {
        node* anterior = nullptr;
        for (int i = 1; i < posicao; ++i) {
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = atual->prox;
    }
    delete atual;
    --tamanho;
}

void ListaEncadeada::imprimir() const {
    node* atual = head;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}
