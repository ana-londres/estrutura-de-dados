#ifndef LISTASEQ_H
#define LISTASEQ_H

class ListaSeq {
private:
    int dados[100];
    int tamAtual;
    int tamMax;

public:
    ListaSeq();
    bool vazia();
    bool cheia();
    int tamanho();
    int elemento(int pos);
    bool modifica(int pos, int novoDado);
    int posicao(int dado);
    bool insere(int pos, int dado);
    int remove(int pos);
};

#endif 