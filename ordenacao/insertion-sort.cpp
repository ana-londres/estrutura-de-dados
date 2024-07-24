#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
    int tamanho, aux, i, j;

    tamanho = arr.size();
    for (i = 1; i < tamanho; i++) {
        aux = arr[i]; // 
        j = i - 1;
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
}

void print_array(vector<int>& arr) {
    for (const int& num : arr)
        cout << num << " ";
    cout << endl;
}
