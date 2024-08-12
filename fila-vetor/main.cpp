#include "fila_vetor.h"
#include <iostream>

using namespace std;

int main() {
    FilaVetor fila(4);

    cout << "Inserindo elementos..." << endl;
    fila.inserirFim(1);
    fila.inserirFim(2);
    fila.inserirFim(3);
    fila.inserirFim(4);

    cout << "Elemento no inicio da fila: " << fila.consultarInicio() << endl;

    cout << "Inserindo novo elemento na fila..." << endl;
    fila.inserirFim(5);

    cout << "Fila esta cheia? " << (fila.estaCheia() ? "Sim" : "Nao") << endl;

    fila.removerInicio();
    cout << "Elemento removido. Novo elemento no inicio da fila: " << fila.consultarInicio() << endl;

    cout << "Inserindo elementos..." << endl;
    fila.inserirFim(6);

    cout << "Fila esta cheia? " << (fila.estaCheia() ? "Sim" : "Nao") << endl;

    while (!fila.estaVazia()) {
        cout << "Removendo: " << fila.removerInicio() << endl;
    }

    cout << "Fila esta vazia? " << (fila.estaVazia() ? "Sim" : "Não") << endl;

    return 0;
}