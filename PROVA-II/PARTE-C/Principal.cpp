#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Grafos.h"
#include <locale.h>

using namespace std;

int **Madj, **Md;
int i, j, n, OPC, inicio, fim, peso;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Graph *G1 = new Graph();
    
    // CORREÇÃO: Usar const char* para evitar warning
    n = G1->Ent_Grafo(Md, (char*)"Dist5.txt");
    
    G1->Gera_Matriz_Adj(n, n, G1->dist);
    G1->NArestas(n, n);
    
    // CORREÇÃO: Removido o malloc desnecessário pois GrauG já aloca
    G1->GrauG(n);
    
    do{
        system("cls");
        OPC = G1->Menu_Grafo();
        switch(OPC){
            case 1: 
                system("cls");
                G1->Mostra_Grafo();
                break;
            case 2:
                system("cls");
                G1->Imprime_Matriz(n, 0); // 0 para matriz de adjacência
                break;
            case 3:
                system("cls");
                G1->Imprime_Matriz(n, 1); // 1 para matriz de distâncias
                break;
            case 4:
                cout << "------------------------------" << endl;
                cout << " INSERINDO ARCO EM G(V,A) " << endl;
                cout << "------------------------------" << endl;
                cout << "Digite o inicio do arco: ";
                cin >> inicio;
                cout << "Digite o final do arco: ";
                cin >> fim;
                cout << "Digite o peso do arco " << inicio << " - " << fim << ": ";
                cin >> peso;
                G1->Insere_Arco(inicio, fim, peso);
                cout << " Arco " << inicio << " - " << fim << " inserido!" << endl;
                system("pause");
                break;
            case 5:
                cout << "------------------------------" << endl;
                cout << " REMOVENDO ARCO EM G(V,A) " << endl;
                cout << "------------------------------" << endl;
                cout << "Digite o inicio do arco: ";
                cin >> inicio;
                cout << "Digite o final do arco: ";
                cin >> fim;
                G1->Remove_Arco(inicio, fim);
                cout << " Arco " << inicio << " - " << fim << " removido!" << endl;
                system("pause");
                break;
            case 6:
                system("cls");
                G1->GrauG(n);
                G1->MostraGrauG(n);
                system("pause");
                break;
        }
    } while(OPC != 7);
    
    delete G1;
    return 0;	
}