#include <iostream>
#include "lista-seq.h"

using namespace std;

int main() {
    ListaSeq lista;

    cout << "Lista está vazia? " << (lista.vazia() ? "Sim" : "Nao") << endl;

    lista.insere(1, 100);
    lista.insere(2, 200);
    lista.insere(3, 300);
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;

    lista.modifica(2, 250);
    cout << "Novo valor do elemento na posicao 2: " << lista.elemento(2) << endl;

    cout << "Posição do elemento 200: " << lista.posicao(200) << endl;

    cout << "Removendo elemento na posicao 2: " << lista.remove(2) << endl;
    cout << "Novo elemento na posicao 2: " << lista.elemento(2) << endl;

    cout << "A lista está cheia? " << (lista.cheia() ? "Sim" : "Nao") << endl;

    cout << "Tamanho da lista: " << lista.tamanho() << endl;

    return 0;
}
