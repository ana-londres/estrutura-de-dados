#include <iostream>
#include "lista-enc.h"

using namespace std;

int main() {
    ListaEncadeada lista;

    cout << "A lista está vazia? " << (lista.vazia() ? "Sim" : "Não") << endl;


    lista.inserir(1, 10);
    lista.inserir(2, 15);
    lista.inserir(3, 20);
    cout << "Lista atual: ";
    lista.imprimir();

    cout << "Tamanho atual da lista: " << lista.obterTam() << endl;
    cout << "A lista está vazia? " << (lista.vazia() ? "Sim" : "Não") << endl;

    cout << "Elemento na posição 1: " << lista.obterPos(1) << endl; 
    cout << "Elemento na posição 2: " << lista.obterPos(2) << endl;
    cout << "Elemento na posição 3: " << lista.obterPos(3) << endl; 

    lista.modificaPos(2, 50);
    cout << "Elemento na posição 2 após modificação: " << lista.obterPos(2) << endl; 
    cout << "Lista após modificação: ";
    lista.imprimir();

    lista.remover(2);
    cout << "Lista após remoção da posição 2: ";
    lista.imprimir();

    lista.remover(1);
    cout << "Lista após remoção da posição 1: ";
    lista.imprimir();

    // alterar para se estiver vazia imprimir alguma msg
    lista.remover(1);
    cout << "Lista após remoção da última posição: ";
    lista.imprimir();

    cout << "Tamanho da lista: " << lista.obterTam() << endl; 
    cout << "A lista está vazia? " << (lista.vazia() ? "Sim" : "Não") << endl;

    return 0;
}
