#include <iostream>
#include <climits>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define inf 99999999
using namespace std;

// DEFININDO A CLASSE GRAPH QUE FALTAVA
class Graph {
public:
    int V; // número de vértices
    int A; // número de arestas
    int **adj; // matriz de adjacência
    int **dist; // matriz de distâncias
    
    // Definindo vertex como int para compatibilidade
    typedef int vertex;
    
    // Construtor
    Graph() {
        V = 0;
        A = 0;
        adj = nullptr;
        dist = nullptr;
    }
    
    // Destrutor 
    ~Graph() {
        // Liberar memória das matrizes
        if (adj != nullptr) {
            for (int i = 0; i < V; i++) {
                delete[] adj[i];
            }
            delete[] adj;
        }
        if (dist != nullptr) {
            for (int i = 0; i < V; i++) {
                delete[] dist[i];
            }
            delete[] dist;
        }
    }
    
    // Método para alocar matriz
    int** Aloca_MatrizInt(int l, int c) {
        int **m = new int*[l];
        for (int i = 0; i < l; i++) {
            m[i] = new int[c];
            for (int j = 0; j < c; j++) {
                m[i][j] = 0;
            }
        }
        return m;
    }
    
    // Método para criar grafo vazio
    void Criar_Grafo(int numVertices) {
        V = numVertices;
        adj = Aloca_MatrizInt(V, V);
        A = 0;
        cout << "Grafo criado com " << V << " vertices!" << endl;
    }
    
    // Método para inserir aresta
    void Inserir_Aresta(int u, int v, int peso) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = peso;
            adj[v][u] = peso; // Grafo não direcionado
            A++;
            cout << "Aresta " << u << " - " << v << " com peso " << peso << " inserida!" << endl;
        } else {
            cout << "Vertices invalidos!" << endl;
        }
    }
    
    // Método para mostrar matriz de adjacência
    void Mostrar_Matriz_Adj() {
        if (adj == nullptr) {
            cout << "Grafo vazio!" << endl;
            return;
        }
        
        cout << "\nMatriz de Adjacencia:" << endl;
        cout << "    ";
        for (int j = 0; j < V; j++) {
            cout << j << "\t";
        }
        cout << endl;
        
        for (int i = 0; i < V; i++) {
            cout << i << " | ";
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
    // Método para mostrar matriz de distâncias do Floyd-Warshall
    void Mostrar_Matriz_Dist() {
        if (dist == nullptr) {
            cout << "Execute Floyd-Warshall primeiro!" << endl;
            return;
        }
        
        cout << "\nMatriz de Distancias (Floyd-Warshall):" << endl;
        cout << "    ";
        for (int j = 0; j < V; j++) {
            cout << j << "\t";
        }
        cout << endl;
        
        for (int i = 0; i < V; i++) {
            cout << i << " | ";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX / 2) {
                    cout << "INF\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
};

// FUNÇÃO FLOYD-WARSHALL ORIGINAL
void floydWarshall(Graph &G) { 
    if (G.V == 0) {
        cout << "Grafo vazio! Crie um grafo primeiro." << endl;
        return;
    }
    
    int numVertices = G.V;
    
    // Se a matriz dist não existir, criar
    if (G.dist == nullptr) {
        G.dist = G.Aloca_MatrizInt(numVertices, numVertices);
    }
    
    // Preenche a matriz com valores iniciais
    for (int i = 0; i < numVertices; i++) {   
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                G.dist[i][j] = 0;
            } else if (G.adj[i][j] != 0) {
                G.dist[i][j] = G.adj[i][j];
            } else {
                G.dist[i][j] = INT_MAX / 2;
            }
        }
    }

    // Aplicando o algoritmo de Floyd-Warshall
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (G.dist[i][k] != INT_MAX / 2 && G.dist[k][j] != INT_MAX / 2) {
                    int distanciaPassandoPorK = G.dist[i][k] + G.dist[k][j];
                    if (distanciaPassandoPorK < G.dist[i][j]) {
                        G.dist[i][j] = distanciaPassandoPorK;
                    }
                }
            }
        }
    }
    
    cout << "Floyd-Warshall executado com sucesso!" << endl;
}

// FUNÇÃO PARA MOSTRAR MENOR CAMINHO ENTRE DOIS VÉRTICES
void mostrarMenorCaminho(Graph &G, int origem, int destino) {
    if (G.dist == nullptr) {
        cout << "Execute Floyd-Warshall primeiro!" << endl;
        return;
    }
    
    if (origem < 0 || origem >= G.V || destino < 0 || destino >= G.V) {
        cout << "Vertices invalidos!" << endl;
        return;
    }
    
    if (G.dist[origem][destino] == INT_MAX / 2) {
        cout << "Nao existe caminho entre " << origem << " e " << destino << endl;
    } else {
        cout << "Menor distancia entre " << origem << " e " << destino << ": " << G.dist[origem][destino] << endl;
    }
}

// FUNÇÃO PARA LIMPAR TELA (compatível com Windows e Linux)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// FUNÇÃO PRINCIPAL COM MENU INTERATIVO
int main() {
    Graph G;
    int opcao, numVertices, u, v, peso, origem, destino;
    
    do {
        limparTela();
        cout << "=============================================" << endl;
        cout << "          ALGORITMO DE FLOYD-WARSHALL" << endl;
        cout << "=============================================" << endl;
        cout << " [1] Criar novo grafo" << endl;
        cout << " [2] Inserir aresta" << endl;
        cout << " [3] Mostrar matriz de adjacencia" << endl;
        cout << " [4] Executar Floyd-Warshall" << endl;
        cout << " [5] Mostrar matriz de distancias" << endl;
        cout << " [6] Consultar menor caminho" << endl;
        cout << " [7] Informacoes do grafo" << endl;
        cout << " [0] Sair" << endl;
        cout << "=============================================" << endl;
        cout << " Opcao -> ";
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                cout << "\nNumero de vertices: ";
                cin >> numVertices;
                if (numVertices > 0) {
                    G.Criar_Grafo(numVertices);
                } else {
                    cout << "Numero de vertices deve ser maior que 0!" << endl;
                }
                break;
                
            case 2:
                if (G.V == 0) {
                    cout << "Crie um grafo primeiro!" << endl;
                } else {
                    cout << "\nVertice de origem (0 a " << G.V-1 << "): ";
                    cin >> u;
                    cout << "Vertice de destino (0 a " << G.V-1 << "): ";
                    cin >> v;
                    cout << "Peso da aresta: ";
                    cin >> peso;
                    G.Inserir_Aresta(u, v, peso);
                }
                break;
                
            case 3:
                G.Mostrar_Matriz_Adj();
                break;
                
            case 4:
                floydWarshall(G);
                break;
                
            case 5:
                G.Mostrar_Matriz_Dist();
                break;
                
            case 6:
                if (G.dist == nullptr) {
                    cout << "Execute Floyd-Warshall primeiro!" << endl;
                } else {
                    cout << "\nVertice de origem (0 a " << G.V-1 << "): ";
                    cin >> origem;
                    cout << "Vertice de destino (0 a " << G.V-1 << "): ";
                    cin >> destino;
                    mostrarMenorCaminho(G, origem, destino);
                }
                break;
                
            case 7:
                cout << "\nInformacoes do Grafo:" << endl;
                cout << "Numero de vertices: " << G.V << endl;
                cout << "Numero de arestas: " << G.A << endl;
                break;
                
            case 0:
                cout << "Saindo..." << endl;
                break;
                
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
        
        if (opcao != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcao != 0);
    
    return 0;
}