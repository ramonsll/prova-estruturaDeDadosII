#include <iostream>
#include <string>
#include <sstream> // para ostringstream
using namespace std;

// Estrutura de nó da árvore
struct No {
    string nome;
    char sexo;
    int idade;
    float peso;
    No *esq, *dir;
};

// Função para criar um novo nó
No* novoNo(string nome, char sexo, int idade, float peso) {
    No* no = new No;
    no->nome = nome;
    no->sexo = sexo;
    no->idade = idade;
    no->peso = peso;
    no->esq = no->dir = NULL;
    return no;
}

// Inserção (ordenada por nome)
No* inserir(No* raiz, string nome, char sexo, int idade, float peso) {
    if (raiz == NULL)
        return novoNo(nome, sexo, idade, peso);

    if (nome < raiz->nome)
        raiz->esq = inserir(raiz->esq, nome, sexo, idade, peso);
    else if (nome > raiz->nome)
        raiz->dir = inserir(raiz->dir, nome, sexo, idade, peso);

    return raiz;
}

// Travessia in-order para gerar listas
void gerarListas(No* raiz, string &listaHomens, string &listaMulheres) {
    if (raiz != NULL) {
        gerarListas(raiz->esq, listaHomens, listaMulheres);

        // Usando ostringstream para converter numeros em string
        ostringstream ss;
        ss << raiz->idade;
        string idadeStr = ss.str();
        ss.str(""); ss.clear(); // limpa o stringstream

        ss << raiz->peso;
        string pesoStr = ss.str();
        ss.str(""); ss.clear();

        string pessoa = raiz->nome + " (" + string(1, raiz->sexo) + ") - Idade: " +
                        idadeStr + ", Peso: " + pesoStr + "\n";

        // Adicionar à lista correspondente
        if (raiz->sexo == 'M' || raiz->sexo == 'm')
            listaHomens += pessoa;
        else if (raiz->sexo == 'F' || raiz->sexo == 'f')
            listaMulheres += pessoa;

        gerarListas(raiz->dir, listaHomens, listaMulheres);
    }
}

// Listagem geral (in-order)
void listarTodos(No* raiz) {
    if (raiz != NULL) {
        listarTodos(raiz->esq);
        cout << raiz->nome << " (" << raiz->sexo << ") - Idade: "
             << raiz->idade << ", Peso: " << raiz->peso << endl;
        listarTodos(raiz->dir);
    }
}

// Menu principal
int main() {
    No* raiz = NULL;
    int opcao;
    string nome;
    char sexo;
    int idade;
    float peso;

    do {
        cout << "\n===== MENU ARVORE BINARIA =====" << endl;
        cout << "1 - Inserir pessoa" << endl;
        cout << "2 - Listar todos (ordem alfabetica)" << endl;
        cout << "3 - Gerar listas de homens e mulheres" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // limpa buffer do teclado

        switch (opcao) {
        case 1:
            cout << "\n--- Inserir nova pessoa ---" << endl;
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Sexo (M/F): ";
            cin >> sexo;
            cout << "Idade: ";
            cin >> idade;
            cout << "Peso: ";
            cin >> peso;
            raiz = inserir(raiz, nome, sexo, idade, peso);
            cout << "Pessoa inserida com sucesso!" << endl;
            break;

        case 2:
            cout << "\n--- Listagem completa ---" << endl;
            if (raiz == NULL)
                cout << "A arvore esta vazia!" << endl;
            else
                listarTodos(raiz);
            break;

        case 3: {
            cout << "\n--- Gerando listas por sexo ---" << endl;
            string listaHomens = "";
            string listaMulheres = "";
            gerarListas(raiz, listaHomens, listaMulheres);

            cout << "\n==== LISTA DE HOMENS ====\n";
            if (listaHomens.empty())
                cout << "Nenhum homem cadastrado.\n";
            else
                cout << listaHomens;

            cout << "\n==== LISTA DE MULHERES ====\n";
            if (listaMulheres.empty())
                cout << "Nenhuma mulher cadastrada.\n";
            else
                cout << listaMulheres;
            break;
        }

        case 4:
            cout << "Encerrando o programa..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 4);

    return 0;
}
