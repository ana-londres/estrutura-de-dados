#!/bin/bash

make clean
make

for algorithm in selection insertion; do
    for file in instancias-num/*.in; do
        echo "Testando o $algorithm sort com o arquivo de entrada $file"
        ./main $algorithm $file
        echo
    done
done