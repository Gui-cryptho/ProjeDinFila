# Estruturas de Dados - Lista de Exercícios com Filas e Pilhas

**Aluno:** Guilherme de Sousa Brito  
**RA:** 2576627

Este repositório contém a resolução da lista de exercícios proposta pelo professor na disciplina de Estruturas de Dados. Os exercícios abordam o uso de filas, pilhas, suas combinações e variações, além de simulações práticas com essas estruturas.

---

## 📘 Enunciados dos Exercícios

### 1. Método `separa`
Implemente um método que receba como parâmetro a referência `f1` e um valor de matrícula `n`, e divida a fila em duas. A segunda fila (`f2`) deve começar no primeiro nó logo após a primeira ocorrência de `n` na fila original.  
**Assinatura:** `int separa(Fila f1, Fila f2, matricula n)`

---

### 2. Combinações de Estruturas com Fila
Implemente as seguintes estruturas:
- a) Uma fila de filas
- b) Uma fila de pilhas
- c) Uma pilha de filas

---

### 3. Inversão de Fila com Pilha
Considere uma pilha `P` vazia e uma fila `F` não vazia. Utilizando apenas os testes de fila e pilha vazias, as operações `Enfileira`, `Desenfileira`, `Empilha`, `Desempilha`, e uma variável `aux` inteira, escreva um programa que inverta a ordem dos elementos da fila.

---

### 4. Fila Circular e Função `FuraFila`
Pesquise sobre filas circulares.  
Implemente a função `FuraFila(Fila* f, float x)` que insere um item na primeira posição da fila em tempo constante `O(1)`, sem movimentar os outros itens.  
Altere também a função de percorrer a fila para aproveitar a característica circular.

---

### 5. Simulação de Pista de Decolagem
Escreva um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. O usuário deve poder:
- a) Listar o número de aviões aguardando na fila de decolagem
- b) Autorizar a decolagem do primeiro avião da fila
- c) Adicionar um avião à fila de espera
- d) Listar todos os aviões na fila de espera
- e) Listar as características do primeiro avião da fila

---

### 6. Mesclagem de Filas Ordenadas
Implemente um método que receba três filas, sendo duas já preenchidas em ordem crescente, e preencha a terceira com os valores das duas primeiras também em ordem crescente.

---

### 7. Função `reverso`
Implemente a função `reverso`, que reposiciona os elementos da fila de forma que o início da fila se torne o fim, e vice-versa.

---

### 8. Menu Interativo de Operações com Fila
Escreva um programa com menu contínuo que execute as opções abaixo:

```c
void menu() {
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila é vazia.\n");
    printf("3-Verifica se a fila é cheia.\n");
    printf("4-Enfileira o elemento na fila.\n");
    printf("5-Desenfileira elemento da fila.\n");
    printf("6-Le o número no início da fila.\n");
    printf("7-Testar qual fila possui mais elementos.\n");
    printf("8-Furar a fila.\n");
    printf("9-Sair.\n");
}
