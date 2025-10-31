#include <iostream> // Biblioteca para entrada e saída (cout, cin)
#include <cstdlib>  // Biblioteca para system("cls") e system("pause")
#include <string>   // Biblioteca para usar string
#include <sstream>  // Biblioteca para converter números em string
#include <algorithm> // Biblioteca para usar a função max()
using namespace std; // Para não precisar usar std::

// Estrutura do nó da árvore AVL
struct No {
    string nome;   // Armazena o nome da pessoa
    char sexo;     // Armazena o sexo (M/F)
    int idade;     // Armazena a idade
    float peso;    // Armazena o peso
    int altura;    // Armazena a altura do nó na árvore
    No* dir;       // Ponteiro para o filho direito
    No* esq;       // Ponteiro para o filho esquerdo
};

// Função que retorna a altura de um nó
int altura(No* N) {
    if (N == NULL) return 0; // Se nó é nulo, altura é 0
    return N->altura; // Retorna a altura armazenada no nó
}

// Função que calcula o fator de balanceamento
int fatorBalanceamento(No* N) {
    if (N == NULL) return 0; // Se nó é nulo, fator é 0
    return altura(N->esq) - altura(N->dir); // Altura esquerda - altura direita
}

// Função para criar um novo nó
No* novoNo(string nome, char sexo, int idade, float peso) {
    No* novo = new No; // Aloca memória para novo nó
    novo->nome = nome; // Atribui nome
    novo->sexo = sexo; // Atribui sexo
    novo->idade = idade; // Atribui idade
    novo->peso = peso; // Atribui peso
    novo->altura = 1; // Nova altura é 1
    novo->esq = NULL; // Inicializa filho esquerdo como nulo
    novo->dir = NULL; // Inicializa filho direito como nulo
    return novo; // Retorna o novo nó
}

// Rotação simples à direita para balancear a árvore
No* rotacaoDireita(No* y) {
    No* x = y->esq;   // x recebe o filho esquerdo de y
    No* T2 = x->dir;  // T2 recebe o filho direito de x

    x->dir = y;       // x vira pai de y
    y->esq = T2;      // y recebe T2 como filho esquerdo

    // Atualiza alturas após rotação
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x; // Retorna nova raiz
}

// Rotação simples à esquerda para balancear a árvore
No* rotacaoEsquerda(No* x) {
    No* y = x->dir;   // y recebe o filho direito de x
    No* T2 = y->esq;  // T2 recebe o filho esquerdo de y

    y->esq = x;       // y vira pai de x
    x->dir = T2;      // x recebe T2 como filho direito

    // Atualiza alturas após rotação
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y; // Retorna nova raiz
}

// F1: Função para inserir pessoa na árvore AVL
No* inserir(No* raiz, string nome, char sexo, int idade, float peso) {
    // Se árvore vazia, cria novo nó
    if (raiz == NULL) {
        return novoNo(nome, sexo, idade, peso);
    }

    // Se nome menor, insere na esquerda
    if (nome < raiz->nome) {
        raiz->esq = inserir(raiz->esq, nome, sexo, idade, peso);
    }
    // Se nome maior, insere na direita
    else if (nome > raiz->nome) {
        raiz->dir = inserir(raiz->dir, nome, sexo, idade, peso);
    }
    // Nomes iguais não são permitidos
    else {
        return raiz;
    }

    // Atualiza altura deste nó ancestral
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    // Obtém o fator de balanceamento
    int balance = fatorBalanceamento(raiz);

    // Caso Esquerda-Esquerda (rotação direita)
    if (balance > 1 && nome < raiz->esq->nome) {
        return rotacaoDireita(raiz);
    }

    // Caso Direita-Direita (rotação esquerda)
    if (balance < -1 && nome > raiz->dir->nome) {
        return rotacaoEsquerda(raiz);
    }

    // Caso Esquerda-Direita (rotação dupla: esq + dir)
    if (balance > 1 && nome > raiz->esq->nome) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Caso Direita-Esquerda (rotação dupla: dir + esq)
    if (balance < -1 && nome < raiz->dir->nome) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz; // Retorna o nó não modificado
}

// F2: Função para listar todas as pessoas em ordem alfabética
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq); // Visita subárvore esquerda
        // Imprime dados da pessoa
        cout << raiz->nome << " (" << raiz->sexo << ") - Idade: " 
             << raiz->idade << ", Peso: " << raiz->peso << endl;
        emOrdem(raiz->dir); // Visita subárvore direita
    }
}

// Função para encontrar o nó com menor valor (mais à esquerda)
No* menorNo(No* no) {
    No* atual = no; // Começa do nó atual
    // Percorre sempre para a esquerda até chegar no menor
    while (atual && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual; // Retorna o menor nó
}

// F3: Função para remover pessoa da árvore AVL
No* remover(No* raiz, string nome) {
    // Se árvore vazia, retorna nulo
    if (raiz == NULL) {
        return raiz;
    }

    // Se nome menor, busca na esquerda
    if (nome < raiz->nome) {
        raiz->esq = remover(raiz->esq, nome);
    }
    // Se nome maior, busca na direita
    else if (nome > raiz->nome) {
        raiz->dir = remover(raiz->dir, nome);
    }
    // Nó encontrado
    else {
        // Nó com um ou nenhum filho
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;

            // Caso sem filhos
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            }
            // Caso com um filho
            else {
                *raiz = *temp; // Copia dados do filho
            }
            delete temp; // Libera memória
        }
        // Nó com dois filhos
        else {
            // Encontra o sucessor in-order (menor da direita)
            No* temp = menorNo(raiz->dir);
            // Copia dados do sucessor
            raiz->nome = temp->nome;
            raiz->sexo = temp->sexo;
            raiz->idade = temp->idade;
            raiz->peso = temp->peso;
            // Remove o sucessor
            raiz->dir = remover(raiz->dir, temp->nome);
        }
    }

    // Se árvore ficou vazia após remoção
    if (raiz == NULL) {
        return raiz;
    }

    // Atualiza altura
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    // Obtém fator de balanceamento
    int balance = fatorBalanceamento(raiz);

    // Casos de balanceamento após remoção

    // Esquerda-Esquerda
    if (balance > 1 && fatorBalanceamento(raiz->esq) >= 0) {
        return rotacaoDireita(raiz);
    }

    // Esquerda-Direita
    if (balance > 1 && fatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Direita-Direita
    if (balance < -1 && fatorBalanceamento(raiz->dir) <= 0) {
        return rotacaoEsquerda(raiz);
    }

    // Direita-Esquerda
    if (balance < -1 && fatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz; // Retorna raiz possivelmente modificada
}

// F4: Função para consultar pessoa pelo nome
No* consultar(No* raiz, string nome) {
    // Se árvore vazia ou nome encontrado
    if (raiz == NULL || raiz->nome == nome) {
        return raiz;
    }

    // Se nome menor, busca na esquerda
    if (nome < raiz->nome) {
        return consultar(raiz->esq, nome);
    }

    // Se nome maior, busca na direita
    return consultar(raiz->dir, nome);
}

// Função para gerar listas separadas por sexo
void gerarListas(No* raiz, string &listaHomens, string &listaMulheres) {
    if (raiz != NULL) {
        gerarListas(raiz->esq, listaHomens, listaMulheres); // Esquerda

        // Converte idade e peso para string
        ostringstream ss;
        ss << raiz->idade;
        string idadeStr = ss.str();
        ss.str(""); // Limpa o stream
        ss << raiz->peso;
        string pesoStr = ss.str();

        // Formata string da pessoa
        string pessoa = raiz->nome + " (" + raiz->sexo + ") - Idade: " +
                       idadeStr + ", Peso: " + pesoStr + "\n";

        // Adiciona à lista correspondente
        if (raiz->sexo == 'M' || raiz->sexo == 'm') {
            listaHomens += pessoa;
        }
        else if (raiz->sexo == 'F' || raiz->sexo == 'f') {
            listaMulheres += pessoa;
        }

        gerarListas(raiz->dir, listaHomens, listaMulheres); // Direita
    }
}

// Função que exibe o menu principal
int Menu() {
    int opc;
    
    system("cls"); // Limpa tela
    cout << "\n\n";
    cout << "    ARVORE AVL - PESSOAS" << endl;
    cout << "   =======================" << endl;
    cout << "   [1] INSERIR PESSOA" << endl;
    cout << "   [2] LISTAR TODOS" << endl;
    cout << "   [3] REMOVER PESSOA" << endl;
    cout << "   [4] CONSULTAR PESSOA" << endl;
    cout << "   [5] LISTAS POR SEXO" << endl;
    cout << "   [6] SAIR" << endl;
    cout << "   =======================" << endl;
    cout << "   Escolha uma opcao: ";
    cin >> opc;
    return opc; // Retorna opção escolhida
}

// Função principal
int main() {
    No* raiz = NULL; // Inicializa árvore vazia
    int opc, idade, n;
    float peso;
    string nome;
    char sexo;

    do {
        opc = Menu(); // Exibe menu e obtém opção
        
        switch(opc) {
            case 1: // INSERIR PESSOA
                system("cls");
                cout << "INSERIR PESSOA\n" << endl;
                cout << "Quantas pessoas deseja inserir? ";
                cin >> n;
                cin.ignore(); // Limpa buffer do teclado
                cout << "Insira os dados:" << endl;
                for(int i = 0; i < n; i++) {
                    cout << "\nPessoa " << i+1 << ":" << endl;
                    cout << "Nome: ";
                    getline(cin, nome); // Lê nome com espaços
                    cout << "Sexo (M/F): ";
                    cin >> sexo;
                    cout << "Idade: ";
                    cin >> idade;
                    cout << "Peso: ";
                    cin >> peso;
                    cin.ignore(); // Limpa buffer
                    raiz = inserir(raiz, nome, sexo, idade, peso); // Insere na árvore
                }
                cout << "\nPessoas inseridas com sucesso!" << endl;
                system("pause"); // Pausa para usuário ver mensagem
                break;
                
            case 2: // LISTAR TODOS
                system("cls");
                cout << "LISTAR TODOS\n" << endl;
                if(raiz == NULL) {
                    cout << "A arvore esta vazia!" << endl;
                }
                else {
                    cout << "Pessoas em ordem alfabetica:" << endl;
                    emOrdem(raiz); // Lista em ordem
                }
                system("pause");
                break;
                
            case 3: // REMOVER PESSOA
                system("cls");
                cout << "REMOVER PESSOA\n" << endl;
                if(raiz == NULL) {
                    cout << "A arvore esta vazia!" << endl;
                }
                else {
                    cout << "Nome da pessoa a remover: ";
                    cin.ignore();
                    getline(cin, nome);
                    raiz = remover(raiz, nome); // Remove pessoa
                    cout << "\nRemocao concluida!" << endl;
                }
                system("pause");
                break;
                
            case 4: // CONSULTAR PESSOA
                system("cls");
                cout << "CONSULTAR PESSOA\n" << endl;
                if(raiz == NULL) {
                    cout << "A arvore esta vazia!" << endl;
                }
                else {
                    cout << "Nome da pessoa a consultar: ";
                    cin.ignore();
                    getline(cin, nome);
                    No* resultado = consultar(raiz, nome); // Busca pessoa
                    if(resultado != NULL) {
                        cout << "\nPESSOA ENCONTRADA:" << endl;
                        cout << "Nome: " << resultado->nome << endl;
                        cout << "Sexo: " << resultado->sexo << endl;
                        cout << "Idade: " << resultado->idade << endl;
                        cout << "Peso: " << resultado->peso << endl;
                    }
                    else {
                        cout << "\nPessoa nao encontrada!" << endl;
                    }
                }
                system("pause");
                break;
                
            case 5: // LISTAS POR SEXO
                system("cls");
                cout << "LISTAS POR SEXO\n" << endl;
                if(raiz == NULL) {
                    cout << "A arvore esta vazia!" << endl;
                }
                else {
                    string listaH = "", listaM = "";
                    gerarListas(raiz, listaH, listaM); // Gera listas
                    
                    cout << "=== HOMENS ===" << endl;
                    if(listaH.empty()) {
                        cout << "Nenhum homem cadastrado\n";
                    } else {
                        cout << listaH;
                    }
                    
                    cout << "=== MULHERES ===" << endl;
                    if(listaM.empty()) {
                        cout << "Nenhuma mulher cadastrada\n";
                    } else {
                        cout << listaM;
                    }
                }
                system("pause");
                break;
                
            case 6: // SAIR
                system("cls");
                cout << "SAINDO...\n" << endl;
                break;
                
            default: // OPÇÃO INVÁLIDA
                cout << "\nOpcao invalida! Tente novamente." << endl;
                system("pause");
                break;
        }
        
    } while(opc != 6); // Repete até usuário escolher sair

    return 0; // Fim do programa
}