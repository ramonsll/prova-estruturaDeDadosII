#include <iostream> // biblioteca de entrada e saída
using namespace std; // usar o namespace padrão

struct No{
    int valor;
    No* dir;
    No* esq;
}; //criando estrutura do nó para realizar comparações na árvore binária

// função para inserir um novo nó na árvore binária
No* inserir(No* raiz, int valor){
    if(raiz == nullptr){ // verificando se a raiz é nula
        No* novo = new No; // criando um novo nó
        novo->valor = valor; // atribuindo o valor ao novo nó
        novo->esq = novo->dir = nullptr; // inicializando os ponteiros esquerdo e direito como nulos
        return novo;
    }
    if(valor < raiz->valor){ // se o valor for maior que o valor da raiz
        raiz->esq = inserir(raiz->esq, valor); // inserir na subárvore esquerda
    }
    else{
        raiz->dir = inserir(raiz->dir, valor); // inserir na subárvore direita
    }
    return raiz;
}

// Listagem em-ordem
void emOrdem(No* raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esq);
        cout << raiz->valor << " ";
        emOrdem(raiz->dir);
    }
}

int MaiorValor(No* raiz){
    if(raiz == nullptr){
        cout << "Árvore vazia!" << endl;
        return -1;
    }
    if(raiz->dir == nullptr){
        return raiz->valor;
    }
    return MaiorValor(raiz->dir);
}

int Menu(){
    int opc;
    
    system("cls");
    cout << "\n\n";
    cout << "    ARVORE BINARIA" << endl;
    cout << "   =================" << endl;
    cout << "   [1] INSERIR VALORES" << endl;
    cout << "   [2] APRESENTAR ARVORE" << endl;
    cout << "   [3] MAIOR VALOR" << endl;
    cout << "   [4] SAIR" << endl;
    cout << "   =================" << endl;
    cout << "   Escolha uma opcao: ";
    cin >> opc;
    return opc;
}

int main(){
    No* raiz = nullptr;
    int opc, valor, n;

    do {
        opc = Menu();
        
        switch(opc) {
            case 1: // INSERIR
                system("cls");
                cout << "INSERIR VALORES\n" << endl;
                cout << "Quantos valores deseja inserir na arvore? ";
                cin >> n;
                cout << "Insira os valores:" << endl;
                for(int i = 0; i < n; i++){
                    cout << "Valor " << i+1 << ": ";
                    cin >> valor;
                    raiz = inserir(raiz, valor);
                }
                cout << "\nValores inseridos com sucesso!" << endl;
                system("pause");
                break;
                
            case 2: // APRESENTAR ARVORE
                system("cls");
                cout << "APRESENTAR ARVORE\n" << endl;
                if (raiz == nullptr) {
                    cout << "A arvore esta vazia!" << endl;
                } else {
                    cout << "Arvore em ordem: ";
                    emOrdem(raiz);
                    cout << endl;
                }
                system("pause");
                break;
                
            case 3: // MAIOR VALOR
                system("cls");
                cout << "MAIOR VALOR\n" << endl;
                if (raiz == nullptr) {
                    cout << "A arvore esta vazia!" << endl;
                } else {
                    int maior = MaiorValor(raiz);
                    cout << "O maior valor na arvore e: " << maior << endl;
                }
                system("pause");
                break;
                
            case 4: // SAIR
                system("cls");
                cout << "SAINDO...\n" << endl;
                break;
                
            default:
                cout << "\nOpcao invalida! Tente novamente." << endl;
                system("pause");
                break;
        }
        
    } while (opc != 4);

    return 0;
}