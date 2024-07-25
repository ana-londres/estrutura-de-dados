#!/bin/bash

# Compila o programa
g++ -o main main.cpp selection-sort.cpp insertion-sort.cpp

# Limpa os arquivos de log
> selection_sort_log.txt
> insertion_sort_log.txt
> comparison_log.txt

# Executa os testes
for algorithm in selection insertion; do
    for file in instancias-num/*.in; do
        echo "Testando $algorithm sort com o arquivo de entrada $file"
        ./main $algorithm $file
        echo
    done
done

# Cria um arquivo de comparação e compara os tempos de execução
echo "Tempos de execução (selection-sort vs insertion-sort)" > comparison_log.txt

for file in instancias-num/*.in; do
    selection_time=$(grep "$file" selection_sort_log.txt | awk -F '; ' '{print $3}' | awk '{print $4}')
    insertion_time=$(grep "$file" insertion_sort_log.txt | awk -F '; ' '{print $3}' | awk '{print $4}')
    echo "Instancia: $file; Selection: $selection_time segundos; Insertion: $insertion_time segundos" >> comparison_log.txt
done

echo "Comparação dos tempos de execução completa."