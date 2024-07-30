#include "lista-seq.h"

ListaSeq::ListaSeq() {
    tamMax = 100;
    tamAtual = 0;
}

bool ListaSeq::vazia() {
    return tamAtual == 0;
}

bool ListaSeq::cheia() {
    return tamAtual == tamMax;
}

int ListaSeq::tamanho() {
    return tamAtual;
}

int ListaSeq::elemento(int pos) {
    if (pos > tamAtual || pos <= 0)
        return -1;
    return dados[pos - 1];
}

bool ListaSeq::modifica(int pos, int novoDado) {
    if (pos > tamAtual || pos <= 0)
        return false;
    dados[pos - 1] = novoDado;
    return true;
}

int ListaSeq::posicao(int dado) {
    for (int i = 0; i < tamAtual; i++) {
        if (dados[i] == dado) {
            return i + 1;
        }
    }
    return -1;
}

bool ListaSeq::insere(int pos, int dado) {
    if (cheia() || pos > tamAtual + 1 || pos <= 0) {
        return false;
    }
    for (int i = tamAtual; i >= pos; i--) {
        dados[i] = dados[i - 1];    // Teste 7: Obter o tamanho da lista

    }
    dados[pos - 1] = dado;
    tamAtual++;
    return true;
}

int ListaSeq::remove(int pos) {
    if (pos > tamAtual || pos < 1) {
        return -1;
    }
    int dado = dados[pos - 1];
    for (int i = pos - 1; i < tamAtual - 1; i++) {
        dados[i] = dados[i + 1];
    }
    tamAtual--;
    return dado;
}
