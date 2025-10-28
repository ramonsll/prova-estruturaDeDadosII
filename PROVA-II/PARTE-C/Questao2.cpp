#include <iostream>
#include <climits>  // para usar INT_MAX
using namespace std;

// ... aqui acima deve estar toda a classe Graph e os metodos que malu vai fzr na questão 1 ...

// Função que calcula as menores distâncias entre todos os pares de vértices
void floydWarshall(Graph &G){ // 
    int numVertices = G.V; // pega o numero total de vertices do grafo
    // agr cria uma nova matriz apenas para as distancias 
    G.dist = new int*[numVertices]; 

    for(int i = 0; i < numVertices; i++){   // Preenche a matriz com valores iniciais
        G.dist[i] = new int[numVertices];  // Cria uma linha da matriz para o vértice i
        for(int j = 0; j < numVertices; j++){
            if(i==j) { // se os vertices forem iguais, significa que a distancia para eles eh zero
                G.dist[i][j] = 0;
            }else if(G.adj[i][j] != 0){ // se houver alguma aresta entre eles
                G.dist[i][j] = G.adj[i][j];
            }
            else{ // se NAO houver nenhuma aresta entre i e j
                G.dist[i][j] = INT_MAX/2; // atribui infinito
            }
        }
    }

    // agora, aplicando o algoritmo de Floyd-Warshall de fato

    for(int k=0; k < numVertices; k++){ // k eh o vertice intermediario entre i e j
        for(int i=0; i<numVertices; i++){ // i eh o vertice de origem
            for(int j=0; j<numVertices; j++){ // j eh o vertice de destino

                int distanciaPassandoPorK = G.dist[i][k] + G.dist[k][j];
                int distanciaAtual = G.dist[i][j];

                if(distanciaPassandoPorK < distanciaAtual){ // se a distancia passando por k for menor, atualiza a distancia
                    G.dist[i][j] = distanciaPassandoPorK;
                }
                // se nao for, mantem a distancia atual
            }
        }
        // agora testamos o próximo vértice como possível intermediário
    }
}