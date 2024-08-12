#include "fila_vetor.h"
#include <stdexcept>

using namespace std;

// construtor
FilaVetor::FilaVetor(int tamanho) {
    arr = new int[tamanho];
    capacidade = tamanho;
    inicio = 0;
    fim = -1;
    quant = 0;
}

// destrutor
FilaVetor::~FilaVetor() {
    delete[] arr;
}

// inserir no fim da fila
void FilaVetor::inserirFim(int valor) {
    if (estaCheia()) {
        cout << "Erro: Fila cheia" << endl;
        return;
    }

    fim = (fim + 1) % capacidade;
    arr[fim] = valor;
    quant++;
}

// remover no inicio da fila
int FilaVetor::removerInicio() {
    if (estaVazia()) {
        cout << "Erro: Fila vazia" << endl;
        return -1;
    }

    int valorRemov = arr[inicio];
    inicio = (inicio + 1) % capacidade;
    quant--;
    return valorRemov;
}

// consultar o inicio da fila
int FilaVetor::consultarInicio() {
    if (estaVazia()) {
        cout << "Erro: Fila vazia" << endl;
        return -1;
    }
    return arr[inicio];
}

// tamanho atual da fila
int FilaVetor::tamanho() {
    return quant;
}

// verifica se a fila está vazia
bool FilaVetor::estaVazia() {
    return (quant == 0);
}

// verifica se a fila está cheia
bool FilaVetor::estaCheia() {
    return (quant == capacidade);
}