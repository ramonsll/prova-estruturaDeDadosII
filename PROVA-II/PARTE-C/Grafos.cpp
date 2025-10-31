#include "Grafos.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define inf 99999999
using namespace std;

// MÉTODO CONSTRUTOR DA CLASSE GRAPH

Graph::Graph(){
	V = 0;
	A = 0;
	cout <<"Grafos G(V,A) instanciado!"<<endl;
}

// MÉTODO DESTRUTOR DA CLASSE GRAPH

Graph::~Graph(){
	cout<<"Grafos G(V,A) desalocado da memória!"<<endl;
}

// MÉTODO GERADOR DE MATRIZ DE ADJACENCIA DO GRAFO

void Graph::Gera_Matriz_Adj(int l, int c, int **Md){
	adj=Aloca_MatrizInt(l,c,Md);
	for (vertex i = 0; i < 1; i++)
		for(vertex j = 0; j < c; j++){
			if(Md[i][j]>0)
				adj[i][j] = 1;
			else adj[i][j] = 0;
		}
}

// MÉTODO CONTADOR DE ARESTAS DO GRAFO

void Graph::NArestas(int l, int c){
	int i, j, Na = 0;
		for(i = 0; i < 1; i++)
			for(j = 0; j < c; j++)
				if((i<j)&&(adj[i][j]==1)) Na++;
    A=Na;
}

// MÉTODO PARA INSERIR ARCO NO GRAFO

void Graph::Insere_Arco(vertex v, vertex w, int peso){
	if(adj[v][w] == 0){
		adj[v][w] = 1;
		adj[w][v] = 1;
		dist[v][w] = peso;
		dist[w][v] = peso;
		A++;
	}
}

// MÉTODO PARA REMOVER ARCO NO GRAFO

void Graph::Remove_Arco(vertex v, vertex w){
	if(adj[v][w] == 1){
		adj[v][w] = 0;
		adj[w][v] = 0;
		dist[v][w] = inf;
		dist[w][v] = inf;
		A--;
	}
}

// MÉTODO PARA EXIBIR O GRAFOS

void Graph::Mostra_Grafo(){
	cout<<"\t Grafos G(V, A)"<<endl;
	cout<<"\t Numero de Vertices: "<<V<<endl;
	cout<<"\t Numero de Arestas: "<<A<<endl;
	cout<<"\t ---------------------------------------------"<<endl;
	cout<<"\t | VERTICE |                   ARESTAS      |" <<endl;
	cout<<"\t ---------------------------------------------"<<endl;
	for(vertex v = 0; v < V; ++v){
		cout<<"\t |    "<<v<<"    |";
		 for(vertex w = 0; w < V; ++w)
		 	if((adj[v][w] == 1) && (v<w))
		 		cout<<"  "<<v<<" - "<<w <<",";
		 	cout<<endl;
	}
	system("pause");
}

// MÉTODO IMPRIMIR  MATRIZ REPRESENTATIVA DO GRAFO

void Graph::Imprime_Matriz(int n, int tipo){
	int i, j;
	if(tipo == 1){
		cout<<"\t ---------------------------------------------"<<endl;
		cout<<"\t    	 Matriz de Distancias de G(v,A)        "<<endl;
		cout<<"\t ---------------------------------------------"<<endl;
		for(i = 0; i < n; i++){
            if(i != 0) cout << endl;
			for(j = 0; j < n; j++)
				cout<<"\t"<<adj[i][j];
		}
		cout<<endl;
	}
	
		else{
		cout<<"\t ---------------------------------------------"<<endl;
		cout<<"\t    	 Matriz de Adjacencia de G(v,A)        "<<endl;
		cout<<"\t ---------------------------------------------"<<endl;	
		for(i = 0; i < n; i++){
            if(i != 0) cout << endl;
			for(j = 0; j < n; j++)
				cout<<"\t"<<adj[i][j];
		}
		cout<<endl;
	}
	system("pause");
}

// MÉTODO LER UM GRAFO (MATRIZ DE DISTANCIA) DO ARQUIVO

int Graph::Ent_Grafo(int **Md, char Arq[30]){
	int C, L, nv, Peso = 0;
	FILE *arquivo;
	arquivo = fopen (Arq, "r");
	if(!arquivo){
		printf("O arquivo %s nao pode ser aberto", Arq);
		getchar();
		exit(1);
	}
	
	else{
		L = 0;
		C = 0;
		fscanf(arquivo, "%d", &nv);
		Md=Aloca_MatrizInt(nv, nv, Md);
		while(!feof(arquivo)){
			fscanf(arquivo, "%d", &Peso);
			 if(Peso!=-1) //marca o fim do arquivo
			 {
			 	Md[L][C] = Peso;
			 }
			 if(Peso == -1){ //marca o fim da linha
			 	L++;
	 	 		C = 0;
			 }
			 else
			 	C++;
		}//fim do arquivo
	}
	fclose(arquivo); //fechando arquivo
	dist = Md;
	V = nv;
}//fim da função Ent_Grafo


// MÉTODO PARA CALCULAR E EXIBIR O GRAU DOS VERTICES DO GRAFO

void Graph::GrauG(int n){
	int i, j;
	for(i=0; i < n; i++)
		grau[i] = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(adj[i][j]==1) grau[i]++;
}

void Graph::MostraGrauG(int n){
	int i;
	//exibindo o grau dos vertices de G(V, A)
	
	cout<<"\t ---------------------------------------------"<<endl;
	cout<<"\t    	   Grau dos Vértices de G(v,A)         "<<endl;
	cout<<"\t ---------------------------------------------"<<endl;	
	for(i = 0; i < n; i++)
		cout<<"\tV["<<i<<"]="<<grau[i]<<endl;
}

int Graph::Menu_Grafo() {
    int opcao;
    int v1, v2, peso;
    char nomeArq[30];
    int n;

    do {
        system("cls"); // limpa tela (Windows)
        cout << "\n\t=============================================";
        cout << "\n\t               MENU DO GRAFO";
        cout << "\n\t=============================================";
        cout << "\n\t [1] Ler grafo de arquivo";
        cout << "\n\t [2] Gerar matriz de adjacencia";
        cout << "\n\t [3] Mostrar grafo (arestas)";
        cout << "\n\t [4] Imprimir matriz de adjacencia";
        cout << "\n\t [5] Imprimir matriz de distancias";
        cout << "\n\t [6] Inserir aresta";
        cout << "\n\t [7] Remover aresta";
        cout << "\n\t [8] Calcular grau dos vertices";
        cout << "\n\t [9] Mostrar grau dos vertices";
        cout << "\n\t [0] Sair";
        cout << "\n\t=============================================";
        cout << "\n\t Opcao -> ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "\n\tInforme o nome do arquivo: ";
                cin >> nomeArq;
                Ent_Grafo(dist, nomeArq);
                cout << "\n\tGrafo lido com sucesso!\n";
                system("pause");
                break;

            case 2:
                Gera_Matriz_Adj(V, V, dist);
                NArestas(V, V);
                cout << "\n\tMatriz de adjacencia gerada!\n";
                system("pause");
                break;

            case 3:
                Mostra_Grafo();
                break;

            case 4:
                Imprime_Matriz(V, 0);
                break;

            case 5:
                Imprime_Matriz(V, 1);
                break;

            case 6:
                cout << "\n\tInforme os vertices (v1 v2) e o peso: ";
                cin >> v1 >> v2 >> peso;
                Insere_Arco(v1, v2, peso);
                cout << "\n\tAresta inserida!\n";
                system("pause");
                break;

            case 7:
                cout << "\n\tInforme os vertices (v1 v2) a remover: ";
                cin >> v1 >> v2;
                Remove_Arco(v1, v2);
                cout << "\n\tAresta removida!\n";
                system("pause");
                break;

            case 8:
                GrauG(V);
                cout << "\n\tGraus calculados!\n";
                system("pause");
                break;

            case 9:
                MostraGrauG(V);
                system("pause");
                break;

            case 0:
                cout << "\n\tEncerrando menu do grafo...\n";
                break;

            default:
                cout << "\n\tOpcao invalida! Tente novamente.\n";
                system("pause");
                break;
        }

    } while(opcao != 0);

    return 0;
}

//FUNÇÃO AUXILIAR: ALOCAÇÃO DE UMA MATRIZ DE INTEIROS

int **Aloca_MatrizInt(int l, int c) {
    int **m = new int*[l];
    for(int i = 0; i < l; i++) {
        m[i] = new int[c];
        // Inicializar com zeros
        for(int j = 0; j < c; j++) {
            m[i][j] = 0;
        } 
    }
    return m;
}