#ifndef LISTAENC_H
#define LISTAENC_H

#include "node.h"

class ListaEncadeada {
private:
        node* head;  // ponteiro para o 1 nó da lista
    int tamanho; // 

public:
    ListaEncadeada();     // construtor
    ~ListaEncadeada();    // destrutor

    bool vazia() const;            
    int obterTam() const;          
    int obterPos(int posicao) const;      
    void modificaPos(int posicao, int valor); 
    void inserir(int posicao, int valor);
    void remover(int posicao);    
    void imprimir() const; 
};

#endif // LISTAENC_H
