#ifndef FILA_VETOR_H
#define FILA_VETOR_H

#include <iostream>

class FilaVetor {
private:
    int* arr;
    int capacidade;
    int inicio;
    int fim;
    int quant;

public:
    FilaVetor(int tamanho);
    ~FilaVetor();

    void inserirFim(int valor);
    int removerInicio();
    int consultarInicio();
    int tamanho();
    bool estaVazia();
    bool estaCheia();
};

#endif