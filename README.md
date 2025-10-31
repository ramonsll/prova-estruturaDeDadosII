# 🌳📊 Atividade Avaliativa II - Estruturas de Dados
Universidade Estadual do Rio Grande do Norte
Disciplina: Laboratório de Estrutura de Dados
Professor: Francisco Chagas de Lima Júnior

# 📋 Descrição do Projeto
Este repositório contém a implementação completa da Atividade Avaliativa II da disciplina de Laboratório de Estrutura de Dados, desenvolvida em C++. O projeto está organizado em três partes principais conforme especificado na avaliação.

# 🗂️ Estrutura do Projeto

PROVA-II/
│
├── 📁 PARTE-A/ # ÁRVORES BINÁRIAS DE BUSCA (2,0 pontos)
│ ├── 📄 Questao01.cpp # Q1 - Implementação básica (inserção, listagem, remoção)
│ ├── 📄 Questao02.cpp # Q2 - Maior valor recursivo
│ ├── 📄 Questao03.cpp # Q3 - Árvore com dados pessoais (Nome, Sexo, Idade, Peso)
│ ├── 📄 Questao04.cpp # Q4 - Tratamento de chaves repetidas
│ ├── 📄 Questao05.cpp # Q5 - Verificação de árvore cheia
│ └── 📁 output/ # Arquivos de saída e executáveis
│
├── 📁 PARTE-B/ # ÁRVORES AVL (2,0 pontos)
│ └── 📄 Questao01.cpp # Transformação da árvore do item A3 em AVL
│
└── 📁 PARTE-C/ # GRAFOS (2,0 pontos)
├── 📄 Grafos.h # Cabeçalho da classe Graph
├── 📄 Grafos.cpp # Implementação da classe Graph
├── 📄 Principal.cpp # Programa principal para grafos
└── 📄 Questao02.cpp # Algoritmo de Floyd-Warshall
    
# 🎯 Detalhamento das Partes
PARTE A - ÁRVORES BINÁRIAS DE BUSCA 🌲
📄 Questao01.cpp
Implementação básica de árvore binária

Inserção dos valores: 20, 5, 12, 36, 27, 45, 9, 2, 6, 17, 40

Remoção sequencial: 9 → 5 → 20

Funções: Inserção (F1), Listagem (F2), Remoção (F3)

📄 Questao02.cpp
Algoritmo recursivo para encontrar o maior valor

Implementação eficiente usando propriedades da ABB

📄 Questao03.cpp
Estrutura com dados: Nome, Sexo, Idade, Peso

Geração automática de listas ordenadas por sexo

Interface para cadastro e consulta

📄 Questao04.cpp
Adaptação para chaves repetidas

Contador de ocorrências em cada nó

Gerenciamento de múltiplas inserções do mesmo valor

📄 Questao05.cpp
Função para verificar se a árvore é cheia

Retorno: 1 (cheia) ou 0 (não cheia)

Tratamento de casos especiais (árvore vazia)

PARTE B - ÁRVORES AVL ⚖️
📄 Questao01.cpp
Transformação da árvore da Parte A em Árvore AVL

Balanceamento automático com rotações

Funções completas:

F1: Inserção com balanceamento

F2: Listagem ordenada

F3: Remoção com balanceamento

F4: Consulta por nome

Menu interativo para todas as operações

PARTE C - GRAFOS 🕸️
📄 Grafos.h & Grafos.cpp
Classe Graph completa para representação de grafos

Matriz de adjacência e matriz de distâncias

Operações implementadas:

Inserção e remoção de arcos

Listagem do grafo

Exibição de matrizes de representação

Cálculo do grau dos vértices

Leitura de arquivos .txt

📄 Questao02.cpp
Implementação do Algoritmo de Floyd-Warshall

Cálculo de caminhos mínimos entre todos os pares de vértices

Integração completa com a classe Graph

📄 Principal.cpp
Programa principal para operações com grafos

Interface unificada para todas as funcionalidades

Menu interativo para o usuário

# 🚀 Como Compilar e Executar
Compilação Individual
bash
# Parte A - Questões 1-5
g++ -o PARTE-A/Questao01.exe PARTE-A/Questao01.cpp
g++ -o PARTE-A/Questao02.exe PARTE-A/Questao02.cpp
g++ -o PARTE-A/Questao03.exe PARTE-A/Questao03.cpp
g++ -o PARTE-A/Questao04.exe PARTE-A/Questao04.cpp
g++ -o PARTE-A/Questao05.exe PARTE-A/Questao05.cpp

# Parte B - Questão 1
g++ -o PARTE-B/Questao01.exe PARTE-B/Questao01.cpp

# Parte C - Grafos
g++ -o PARTE-C/Principal.exe PARTE-C/Principal.cpp PARTE-C/Grafos.cpp
g++ -o PARTE-C/Questao02.exe PARTE-C/Questao02.cpp PARTE-C/Grafos.cpp
Execução
bash
# Executar qualquer questão
./PARTE-A/Questao01.exe
./PARTE-B/Questao01.exe  
./PARTE-C/Principal.exe

# 🛠️ Tecnologias e Conceitos
⚙️ Linguagem & Paradigmas
C++ (padrão C++11 ou superior)

Programação Estruturada

Recursão

Alocação Dinâmica de Memória

🌳 Estruturas de Dados
Árvores Binárias de Busca (ABB)

Árvores AVL (balanceadas)

Grafos (matriz de adjacência)

🔢 Algoritmos Implementados
Travessias de Árvores (in-order, pre-order, post-order)

Rotações AVL (simples e duplas)

Floyd-Warshall (caminhos mínimos)

Busca em Profundidade

# 📊 Funcionalidades

Questão |   	Estrutura   |	   Funcionalidades Principais
A1	          ABB    	       Inserção, Remoção, Listagem
A2	          ABB	           Maior valor recursivo
A3	          ABB	           Dados pessoais, Listas por sexo
A4	          ABB	           Chaves repetidas, Contador
A5	          ABB	           Verificação árvore cheia
B1	          AVL	           Balanceamento, Menu completo
C1	         Grafos        	 Classe Graph, Operações básicas
C2	         Grafos	         Floyd-Warshall, Caminhos mínimos
