#include <iostream>
using namespace std;

struct No {
    int valor;
    No *esq, *dir;
};

No* novoNo(int valor) {
    No* no = new No;
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void listar(No* raiz) {
    if (raiz != NULL) {
        listar(raiz->esq);
        cout << raiz->valor << " ";
        listar(raiz->dir);
    }
}

No* menorValor(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            delete raiz;
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        No* temp = menorValor(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = remover(raiz->dir, temp->valor);
    }
    return raiz;
}

int main() {
    No* raiz = NULL;
    int opcao, valor;
    int numerosIniciais[] = {20, 5, 12, 36, 27, 45, 9, 2, 6, 17, 40};

    for (int i = 0; i < 11; i++)
        raiz = inserir(raiz, numerosIniciais[i]);

    do {
        cout << "\n===== MENU ARVORE BINARIA =====" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Listar elementos (in-order)" << endl;
        cout << "3 - Remover elemento" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite o valor a inserir: ";
            cin >> valor;
            raiz = inserir(raiz, valor);
            cout << "Valor inserido com sucesso!" << endl;
            break;
        case 2:
            cout << "Elementos da arvore: ";
            listar(raiz);
            cout << endl;
            break;
        case 3:
            cout << "Digite o valor a remover: ";
            cin >> valor;
            raiz = remover(raiz, valor);
            cout << "Valor removido (se existia)!" << endl;
            break;
        case 4:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
