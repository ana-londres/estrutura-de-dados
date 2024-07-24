#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& arr) {
    int tamanho, i, j, indiceMenor, aux;

    tamanho = arr.size();
    for (i = 0; i < tamanho-1; i++) { 
        indiceMenor = i;
        for (j = i+1; j < tamanho; j++) {
            if (arr[j] < arr[indiceMenor])
                indiceMenor = j; 
        }
        aux = arr[i];
        arr[i] = arr[indiceMenor];
        arr[indiceMenor] = aux;
    }
}

void print_array(vector<int>& arr) {
    for (const int& num : arr)
        cout << num << " ";
    cout << endl;
}
