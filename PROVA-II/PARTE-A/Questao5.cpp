#include <iostream>
using namespace std;

struct No {
    int valor;
    No *esq, *dir;
};

// Cria um novo nó
No* novoNo(int valor) {
    No* no = new No;
    no->valor = valor;
    no->esq = no->dir = NULL; // substitui nullptr por NULL
    return no;
}

// Inserção na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Listagem in-order (ordem crescente)
void listar(No* raiz) {
    if (raiz != NULL) {
        listar(raiz->esq);
        cout << raiz->valor << " ";
        listar(raiz->dir);
    }
}

// Verifica se a árvore é cheia
int ehCheia(No* raiz) {
    if (raiz == NULL)
        return 1; // Árvore vazia é cheia
    if ((raiz->esq == NULL) && (raiz->dir == NULL))
        return 1; // Nó folha é cheio
    if ((raiz->esq != NULL) && (raiz->dir != NULL))
        return ehCheia(raiz->esq) && ehCheia(raiz->dir);
    return 0; // Nó com apenas um filho
}

// ================= MENU PRINCIPAL =================
int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        cout << "\n===== MENU ARVORE BINARIA =====" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Listar elementos (em ordem)" << endl;
        cout << "3 - Verificar se a arvore eh cheia" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite o valor a inserir: ";
            cin >> valor;
            raiz = inserir(raiz, valor);
            cout << "Elemento inserido com sucesso!" << endl;
            break;

        case 2:
            if (raiz == NULL)
                cout << "A arvore esta vazia!" << endl;
            else {
                cout << "Elementos em ordem: ";
                listar(raiz);
                cout << endl;
            }
            break;

        case 3:
            if (ehCheia(raiz))
                cout << "A arvore eh cheia!" << endl;
            else
                cout << "A arvore NAO eh cheia!" << endl;
            break;

        case 4:
            cout << "Encerrando o programa..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 4);

    return 0;
}
