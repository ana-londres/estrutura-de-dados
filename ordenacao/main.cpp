#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void selection_sort(vector<int>& arr);
void insertion_sort(vector<int>& arr);
extern void print_array(std::vector<int>& arr);

void ler_arquivo(string& nome_arq, vector<int>& arr) {
    ifstream arquivo(nome_arq);

    if (!arquivo) {
        cout << "Não foi possível abrir o arquivo " << nome_arq << endl;
        return;
    }

    int tamanho;
    arquivo >> tamanho;
    arr.resize(tamanho);
    for (int i = 0; i < tamanho; i++) {
        arquivo >> arr[i];
    }
}

void marca_tempo_exec(string& algoritmo, string& nome_arq, double tempo_exec) {
    ofstream arquivo_log(algoritmo + "_sort_log.txt", ios::app); // Abre um arquivo de saída em modo de "appfim"
    arquivo_log << "Algoritmo: " << algoritmo << "; Instancia: " << nome_arq << "; Tempo de execução: " << tempo_exec << " segundos" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) { 
        cout << "Uso incorreto do algoritmo: " << argv[0] << " <algoritmo> <arquivo_de_entrada>" << endl;
        return 1;
    }

    string algoritmo = argv[1];
    string arquivo_entrada = argv[2];
    vector<int> arr;

    ler_arquivo(arquivo_entrada, arr);

    clock_t inicio, fim;
    double cpu_tempo_exec;

    if (algoritmo == "selection") {
        inicio = clock(); // Marca o tempo
        selection_sort(arr);
        fim = clock();
    } else if (algoritmo == "insertion") {
        inicio = clock();
        insertion_sort(arr);
        fim = clock();
    } else {
        cout << "Algoritmo não reconhecido: " << algoritmo << endl;
        return 1;
    }

    cpu_tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo utilizado para rodar
    cout << "Resultado do array ordenado: " << endl;
    print_array(arr);
    cout << "Tempo de execução do " << algoritmo << " sort: " << cpu_tempo_exec << " segundos" << endl;

    // Marca o empo de execução no arquivo de log
    marca_tempo_exec(algoritmo, arquivo_entrada, cpu_tempo_exec);

    return 0;
}