import sys # interação com a linha de comando

class Grafo:
    def __init__(self, matriz_dist):  # inicia o grafo com matriz de distâncias
        self.num_vertc = len(matriz_dist) # numero de vertices
        self.matriz_dist = matriz_dist # matriz de distâncias
        self.matriz_adj = self.criar_matriz_adj(matriz_dist) # distâncias -> adjacência

    def criar_matriz_adj(self, matriz_dist):
        matriz_adj = []

        for i in range(self.num_vertc):
            aux = []
            for j in range(self.num_vertc): # verifica conexões
                if matriz_dist[i][j] != 0:
                    aux.append((j, matriz_dist[i][j])) # se som, add à lista
            aux.sort()  # ordena pelo índice do vértice (crescente)
            matriz_adj.append(aux)

        return matriz_adj

    def BFS(self, inicio, fim):  # busca em largura
        status = [0] * self.num_vertc  # todos os vértices não visitados
        parent = [-1] * self.num_vertc # vertices pai
        fila = [inicio]
        status[inicio] = 1  # vértice inicial como visitado

        while fila:
            vertice_atual = fila.pop(0)  # remove o 1 vertice da fila

            for adj in self.matriz_adj[vertice_atual]:  # itera sobre os adj
                if status[adj[0]] == 0:  # se não foi visitado
                    status[adj[0]] = 1
                    parent[adj[0]] = vertice_atual
                    fila.append(adj[0])
                    if adj[0] == fim:  # se o adj é o destino
                        return parent
                    
        return parent  # se não achar caminho

    def encontrar_caminho(self, parent, inicio, fim):  # a partir da lista de parents (bfs)
        if parent[fim] == -1: # se o final não tiver parent
            print(f"Não foi encontrado caminho entre o vértice {inicio} e o vértice {fim}")
            return []
        
        caminho = []

        while fim != inicio:
            caminho.insert(0, fim) # insere no início
            fim = parent[fim] # atualiza o fim

        caminho.insert(0, inicio) # add o inicial no início

        return caminho

    def DFS(self):  # busca em profundidade
        status = [0] * self.num_vertc  # todos os vértices não visitados
        pilha = []
        floresta = []

        for i in range(self.num_vertc):
            if status[i] == 0:  # se não foi visitado
                arvore = []
                pilha.append(i) # add na pilha

                while pilha: 
                    vertice_atual = pilha.pop()  # remove o do topo

                    if status[vertice_atual] == 0:  # se não foi visitado
                        status[vertice_atual] = 1
                        arvore.append(vertice_atual)  # adiciona na árvore

                        # add adjacentes
                        for adj in sorted(self.matriz_adj[vertice_atual], key=lambda x: x[0], reverse=True):
                            if status[adj[0]] == 0: # se não foi visitado
                                pilha.append(adj[0])

                floresta.append(arvore) # add a árvore na floresta
        
        return floresta


def ler_instancia(arquivo):  # lê a instância do arquivo
    with open(arquivo, 'r') as f:
        linhas = f.readlines()
        matriz_dist = []
        
        for i, linha in enumerate(linhas):
            if i == 0:  # ignora a primeira linha (tamanho da matriz)
                continue

            matriz_dist.append(list(map(int, linha.split())))  # linha -> lista de inteiros

        return matriz_dist

def imprime_matriz_dist(matriz_dist):
    print("Matriz de distâncias:")
    for linha in matriz_dist:
        print(" ".join(map(str, linha)))

def imprime_matriz_adj(matriz_adj):
    print("Matriz de adjacência:")
    for i, adj in enumerate(matriz_adj):
        adj_str = " ".join(f"({v}, {peso})" for v, peso in adj)
        print(f"Vértice [{i}]: {adj_str}")

def main():
    if len(sys.argv) < 2:
        print("Uso: python main.py [nome_do_arquivo]")
        return

    arquivo = 'instncias_grafo/' + sys.argv[1] # caminho do arquivo

    matriz_dist = ler_instancia(arquivo)
    grafo = Grafo(matriz_dist)

    imprime_matriz_dist(matriz_dist)

    imprime_matriz_adj(grafo.matriz_adj)

    inicio = int(input("Insira o primeiro vértice: "))
    fim = int(input("Insira o segundo vértice: "))

    # busca em largura
    parent = grafo.BFS(inicio, fim)
    caminho = grafo.encontrar_caminho(parent, inicio, fim)
    print(f"Rota: {' -> '.join(map(str, caminho))}")

    # busca em profundidade
    floresta = grafo.DFS()
    print(f"Floresta: {floresta}")

if __name__ == "__main__":
    main()