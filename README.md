# 🌳📊 Atividade Avaliativa II - Estruturas de Dados

**Universidade Estadual do Rio Grande do Norte**  
**Disciplina: Laboratório de Estrutura de Dados**  
**Professor: Francisco Chagas de Lima Júnior**

---

## 📋 Descrição do Projeto

Este repositório contém a implementação completa da **Atividade Avaliativa II** da disciplina de Laboratório de Estrutura de Dados, desenvolvida em **C++**. O projeto está organizado em três partes principais conforme especificado na avaliação.

---

## 🗂️ Estrutura do Projeto

```
PROVA-II/
│
├── 📁 PARTE-A/                 # ÁRVORES BINÁRIAS DE BUSCA (2,0 pontos)
│   ├── 📄 Questao01.cpp       # Q1 - Implementação básica
│   ├── 📄 Questao02.cpp       # Q2 - Maior valor recursivo
│   ├── 📄 Questao03.cpp       # Q3 - Árvore com dados pessoais
│   ├── 📄 Questao04.cpp       # Q4 - Tratamento de chaves repetidas
│   ├── 📄 Questao05.cpp       # Q5 - Verificação de árvore cheia
│   └── 📁 output/             # Arquivos de saída e executáveis
│
├── 📁 PARTE-B/                 # ÁRVORES AVL (2,0 pontos)
│   └── 📄 Questao01.cpp       # Transformação da árvore em AVL
│
└── 📁 PARTE-C/                 # GRAFOS (2,0 pontos)
    ├── 📄 Grafos.h            # Cabeçalho da classe Graph
    ├── 📄 Grafos.cpp          # Implementação da classe Graph
    ├── 📄 Principal.cpp       # Programa principal para grafos
    └── 📄 Questao02.cpp       # Algoritmo de Floyd-Warshall
```

## 🚀 Como Compilar e Executar

### Compilação Individual
```bash
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
