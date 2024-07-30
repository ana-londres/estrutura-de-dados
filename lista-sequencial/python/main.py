class ListaSequencial:
    def criar_lista(self, capacidade):
        self.capacidade = capacidade
        self.tamanho = 0
        self.array = [None] * capacidade
    
    def __init__(self, capacidade):
        self.criar_lista(capacidade)

    def vazia(self):
        return self.tamanho == 0

    def cheia(self):
        return self.tamanho == self.capacidade

    def obter_tamanho(self):
        return self.tamanho

    def obter_elemento(self, posicao):
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posicao nao existe/fora do limite.")
        return self.array[posicao - 1]

    def modificar_elemento(self, posicao, valor):
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posicao nao existe/fora do limite.")
        self.array[posicao - 1] = valor

    def inserir(self, posicao, valor):
        if self.cheia():
            raise OverflowError("Lista esta cheia.")
        if posicao < 1 or posicao > self.tamanho + 1:
            raise IndexError("Posicao nao existe/fora do limite.")
        for i in range(self.tamanho, posicao - 1, -1):
            self.array[i] = self.array[i - 1]
        self.array[posicao - 1] = valor
        self.tamanho += 1

    def remover(self, posicao):
        if self.vazia():
            raise ValueError("List is empty")
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posicao nao existe/fora do limite.")
        for i in range(posicao - 1, self.tamanho - 1):
            self.array[i] = self.array[i + 1]
        self.array[self.tamanho - 1] = None
        self.tamanho -= 1


# Testando
if __name__ == "__main__":
    lista_seq = ListaSequencial(5)
    lista_seq.inserir(1, 10)
    lista_seq.inserir(2, 20)
    print(lista_seq.obter_elemento(1))  # 10
    print(lista_seq.obter_elemento(2))  # 20
    lista_seq.modificar_elemento(1, 15)
    print(lista_seq.obter_elemento(1))  # 15
    lista_seq.remover(1)
    print(lista_seq.obter_tamanho())  # 1
    print(lista_seq.vazia())  # False
    print(lista_seq.cheia())  # False