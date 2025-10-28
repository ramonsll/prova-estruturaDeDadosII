#include <iostream>
using namespace std;

struct No{
    int valor;
    int contador;
    No* dir;
    No* esq;
};

// Função para inserir 
No* inserir(No* raiz, int valor){
    if (raiz == nullptr){
        No* novo = new No;
        novo->valor = valor;
        novo->contador = 1;
        novo->esq = novo->dir = nullptr;
        return novo;
    }
    if (valor < raiz->valor){
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if(valor > raiz->valor){
        raiz->dir = inserir(raiz->dir, valor);
    }
    else{
        raiz->contador++;  // ← CONTADOR DE REPETIÇÕES
    }
    return raiz;
}

No* remover(No* raiz, int valor){
    if(raiz == nullptr){
        return raiz;
    }
    
    if(valor < raiz->valor){
        raiz->esq = remover(raiz->esq, valor);
    }
    else if(valor > raiz->valor){
        raiz->dir = remover(raiz->dir, valor);
    }
    else{
        // Se tem mais de uma ocorrência, só decrementa o contador
        if(raiz->contador > 1){
            raiz->contador--;
            return raiz;
        }

        
        if(raiz->esq == nullptr){
            No* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        else if(raiz->dir == nullptr){
            No* temp = raiz->esq;
            delete raiz;
            return temp;
        }

        // Nó com dois filhos: encontra o menor na subárvore direita
        No* temp = raiz->dir;
        while(temp && temp->esq != nullptr)
            temp = temp->esq;
            
        raiz->valor = temp->valor;
        raiz->contador = temp->contador;
        raiz->dir = remover(raiz->dir, temp->valor);
    }
    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esq);
        cout << raiz->valor << " (" << raiz->contador << ") ";
        emOrdem(raiz->dir);
    }
}

int Menu(){
    int opc;
    system("cls");
    cout << "\n\n    ARVORE BINARIA\n   =================\n   [1] INSERIR VALORES\n   [2] LISTAR VALORES\n   [3] REMOVER VALOR\n   [4] SAIR\n   =================\n   Escolha uma opcao: ";
    cin >> opc;
    return opc;
}

int main(){
    No* raiz = nullptr;
    int opc, n, valor;

    do {
        opc = Menu();
        switch(opc) {
            case 1: 
                system("cls");
                cout << "INSERIR VALORES\n\nQuantos valores? ";
                cin >> n;
                cout << "Insira os valores:\n";
                for(int i = 0; i < n; i++){
                    cin >> valor;
                    raiz = inserir(raiz, valor);
                }
                cout << "Valores inseridos!\n";
                system("pause");
                break;
                
            case 2: 
                system("cls");
                cout << "LISTAR ARVORE\n\n";
                if (raiz == nullptr) {
                    cout << "Arvore vazia!\n";
                } else {
                    emOrdem(raiz);
                    cout << endl;
                }
                system("pause");
                break;
                
            case 3: 
                system("cls");
                cout << "REMOVER VALOR\n\n";
                if (raiz == nullptr) {
                    cout << "Arvore vazia!\n";
                } else {
                    cout << "Arvore atual: ";
                    emOrdem(raiz);
                    cout << "\n\nValor para remover: ";
                    cin >> valor;
                    raiz = remover(raiz, valor);
                    cout << "Arvore atualizada: ";
                    emOrdem(raiz);
                    cout << endl;
                }
                system("pause");
                break;
                
            case 4: 
                system("cls");
                cout << "SAINDO...\n";
                break;
        }
    } while (opc != 4);

    return 0;
}