#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos
//Definição do tipo Fila
struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct fila
{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL)
    {
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi)
{
    if(fi != NULL)
    {
        Elem* no;
        while(fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al)
{
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al)
{
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi)
{
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi)
{
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi)
{
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi)
{
    return 0;
}

void imprime_Fila(Fila* fi)
{
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL)
    {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

/*
1) Considerando filas, implemente um método que receba como parâmetro
a referência f1 e um valor de matrícula n e dívida a fila em duas, de tal
forma que a segunda fila comece no primeiro nó logo após a primeira
ocorrência de n na fila original. Esse método deve ser da seguinte
assinatura:
int separa(Fila f1, Fila f2, matricula n)
Dentro do método separa, a segunda fila deve ser apontada pela
referência f2, enquanto f1 deve continuar apontando para o início da fila
anterior.
*/

int divorsio_edition(Fila *f1, Fila *f2, int n)
{
    Elem *no = f1->inicio;

    while(no != NULL && no->dados.matricula != n)
    {
        no = no->prox;
    }

    if (no == NULL)
    {
        return 0;
    }

    f2->inicio = no->prox;
    f2->final = f1->final;

    f1->final = no;
    no->prox = NULL;

    imprime_Fila(f1);
    printf("\n");
    imprime_Fila(f2);

    return 1;

}

/*
2) Implemente as seguintes combinações de estruturas de dados com fila:
a. Uma fila de filas;
b. Uma fila de pilhas;
c. Uma pilha de filas;
*/

//a
struct elementoFila_Fila
{
    Fila *fila;
    struct elementoFila_Fila *prox;
};

typedef struct elementoFila_Fila Elem_FiFi;

struct fila_fila
{
    struct elementoFila_Fila *inicio;
    struct elementoFila_Fila *final;
    int qtd;
};

Fila_Fila *criar_file()
{
    Fila_Fila *fi_fi = (Fila_Fila*)malloc(sizeof(Fila_Fila));
    if(fi_fi != NULL)
    {
        fi_fi->inicio = NULL;
        fi_fi->final = NULL;
        fi_fi->qtd = 0;

    }
    return fi_fi;
}

void insere_file(Fila_Fila *fi_fi, Fila *fi)
{
    Elem_FiFi *no = (Elem_FiFi*)malloc(sizeof(Elem_FiFi));
    if(no == NULL)
        return;

    no->fila = fi;
    no->prox = NULL;
    if(fi_fi->final == NULL)
        fi_fi->inicio = no;
    else
        fi_fi->final->prox = no;
    fi_fi->final = no;
    fi_fi->qtd++;
}

void imprime_fi_fi(Fila_Fila *fi_fi)
{
    Elem_FiFi *no = fi_fi->inicio;
    while(no != NULL)
    {
        printf("%p\n", no->fila);
        printf("\n");
        imprime_Fila(no->fila);
        printf("\n");

        no = no->prox;
    }
}

void File_file(Fila *fi)
{
    Fila_Fila *fi_fi = criar_file();

    insere_file(fi_fi, fi);

    imprime_fi_fi(fi_fi);

}

//b
struct pilha
{
    struct aluno dados;
    struct pilha *prox;
};


struct elemento_fila_pi
{
    Pilha *pi;
    struct elemento_fila_pi *prox;
};

typedef struct elemento_fila_pi Elem_fi_pi;

struct fila_de_pilhas
{
    struct elemento_fila_pi *inicio;
    struct elemento_fila_pi *final;
    int qtd;
};

typedef struct fila_de_pilhas Fila_De_Pilhas;

Pilha *criar_pilha()
{
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi == NULL)
        return 0;

    pi->prox = NULL;
    return pi;

}

Fila_De_Pilhas *criar_fila_pi()
{
    Fila_De_Pilhas *fi = (Fila_De_Pilhas*)malloc(sizeof(Fila_De_Pilhas));
    if (fi == NULL)
        return NULL;

    fi->inicio = NULL;
    fi->final = NULL;
    fi->qtd = 0;
    return fi;
}


void empilhar(Pilha **pi, struct aluno al)
{
    Pilha *no = (Pilha*)malloc(sizeof(Pilha));
    if(no == NULL)
        return;

    no->dados = al;
    no->prox = *pi;
    *pi = no;

}

void insere_pi(Fila_De_Pilhas *fi, Pilha *pi)
{
    Elem_fi_pi *no = (Elem_fi_pi*)malloc(sizeof(Elem_fi_pi));
    if(no == NULL)
        return;

    no->pi = pi;
    no->prox = NULL;
    if(fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;

}

void Imprimi_Pilha(Pilha *pi)
{
    Pilha *no = pi;

    while(no != NULL)
    {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }

}

void imprime_Fi_PI(Fila_De_Pilhas *fi_pi)
{
    Elem_fi_pi *no = fi_pi->inicio;

    while(no != NULL)
    {
        printf("%p", no->pi);
        printf("\n\n");
        Imprimi_Pilha(no->pi);
        no = no->prox;
    }

}

void Fila_Pilha(Pilha *pi)
{
    Fila_De_Pilhas *fi_pi = criar_fila_pi();

    insere_pi(fi_pi, pi);

    imprime_Fi_PI(fi_pi);



}

void liberar_pilha(Pilha *pi)
{
    Pilha *no;
    while (pi != NULL)
    {
        no = pi;
        pi = pi->prox;
        free(no);
    }
}

//c

struct elemento_pilha_fila
{
    Fila *fila;
    struct elemento_pilha_fila *prox;
};

typedef struct elemento_pilha_fila Elem_PiFi;


typedef struct Elem_PiFi Pilha_Fila;

void empilhar_fila(Pilha_Fila **pi_fi, Fila *fila)
{
    Elem_PiFi *no = (Elem_PiFi*)malloc(sizeof(Elem_PiFi));
    if (no == NULL)
        return;

    no->fila = fila;
    no->prox = *pi_fi;
    *pi_fi = no;
}

void imprime_pilha_filas(Pilha_Fila *pi_fi)
{
    Elem_PiFi *no = pi_fi;

    while (no != NULL)
    {
        printf("%p\n\n", no->fila);
        imprime_Fila(no->fila);
        no = no->prox;
    }
}

void Pilha_de_Filas(Fila *f1)
{
    Pilha_Fila *pi_fi = NULL;

    empilhar_fila(&pi_fi, f1);

    imprime_pilha_filas(pi_fi);
}

/*
3) Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas
os testes de fila e pilha vazias, as operações Enfileira, Desenfileira,
Empilha, Desempilha, e uma variável aux inteira, escreva um programa
que inverte a ordem dos elementos da fila.
*/

void inverter_fila_com_pilha(Fila *f)
{
    if (f == NULL || Fila_vazia(f))
        return;

    Pilha *p = NULL;
    struct aluno aux;

    while (!Fila_vazia(f))
    {
        consulta_Fila(f, &aux);
        remove_Fila(f);
        empilhar(&p, aux);
    }

    while (p != NULL)
    {
        aux = p->dados;
        insere_Fila(f, aux);
        Pilha *tmp = p;
        p = p->prox;
        free(tmp);
    }
}


/*
4) Considere a implementação de filas usando a característica de filas
“circulares”, pesquise sobre o assunto. Escreva uma função
FuraFila(Fila* f, float x) que insere um item na primeira posição da fila. O
detalhe é que seu procedimento deve ser O(1), ou seja, não pode
movimentar os outros itens da fila. (observe que este neste caso,
estaremos desrespeitando o conceito de FILA – primeiro a entrar é o
primeiro a sair). Altere também a função de percorrer a Fila para que ela
se aproveite da característica da fila circular.
*/

int Fila_Redonda(Fila* f1, struct aluno al)
{
    if(f1 == NULL)
        return 0;

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    no->dados = al;
    if (f1->inicio == NULL)
    {
        // Fila estava vazia
        no->prox = no;         // Aponta pra si mesmo
        f1->inicio = no;
        f1->final = no;
    }
    else
    {
        // Fila já tem elementos
        no->prox = f1->inicio;
        f1->final->prox = no;
        f1->final = no;
    }

    f1->qtd++;

    return 1;
}

void imprimi_bolinha(Fila *f1)
{

    if(f1 == NULL)
        return;

    Elem *no = f1->inicio;
    while(no != f1->final)
    {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
    printf("Matricula: %d\n",no->dados.matricula);
    printf("Nome: %s\n",no->dados.nome);
    printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
           no->dados.n2,
           no->dados.n3);
    printf("-------------------------------\n");
}

void fura_fila_circular(Fila *fi, struct aluno al)
{
    if (fi == NULL)
        return;

    Elem *no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return;

    no->dados = al;

    if (fi->inicio == NULL)
    {

        fi->inicio = no;
        fi->final = no;
        no->prox = no;
    }
    else
    {
        no->prox = fi->inicio;
        fi->final->prox = no;
        fi->inicio = no;
    }

    fi->qtd++;
}

void libera_planeta(Fila *fi)
{
    if(fi != NULL)
    {
        Elem* no;
        while(fi->inicio != fi->final)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        no = fi->inicio;
        fi->inicio = fi->inicio->prox;
        free(no);

        free(fi);
    }
}

/*
5) Escreva um programa que simule o controle de uma pista de decolagem
de aviões em um aeroporto. Neste programa, o usuário deve ser capaz
de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
*/

struct elemento_ex5
{
    struct aviao dado;
    struct elemento_ex5 *prox;
};

typedef struct elemento_ex5 Elem_ex5;

struct fila_aviao
{
    struct elemento_ex5 *inicio;
    struct elemento_ex5 *final;
    int qtd;
};

Fila_aviao *criar_aviao()
{
    Fila_aviao *aux = (Fila_aviao*)malloc(sizeof(Fila_aviao));
    if(aux != NULL)
    {
        aux->inicio = NULL;
        aux->final = NULL;
        aux->qtd = 0;
    }
    return aux;
}

void adiciona_aviao(Fila_aviao *avi, struct aviao modelo)
{
    Elem_ex5 *no = (Elem_ex5*)malloc(sizeof(Elem_ex5));
    if(no == NULL)
        return;

    no->dado = modelo;
    no->prox = NULL;
    if(avi->final == NULL)
        avi->inicio = no;
    else
        avi->final->prox = no;
    avi->final = no;
    avi->qtd++;
}

// Retorna 1 se conseguiu remover, 0 se falhou
int decolar_aviao(Fila_aviao *avi)
{
    if (avi == NULL)
    {
        printf("\n[ERRO] Fila nao inicializada.\n");
        return 0;
    }
    if (avi->inicio == NULL)
    {
        printf("\n[AVISO] Nao ha avioes para decolar.\n");
        return 0;
    }

    Elem_ex5 *no = avi->inicio;
    avi->inicio = avi->inicio->prox;

    if (avi->inicio == NULL)  // se removeu o ultimo
        avi->final = NULL;

    free(no);
    avi->qtd--;

    printf("\nAviao autorizado a decolar com sucesso!\n");
    return 1;
}


void pista_de_decolagem(Fila_aviao *avi)
{
    if (avi == NULL) return;
    Elem_ex5 *no = avi->inicio;
    if (no == NULL)
    {
        printf("\n--- Pista de decolagem vazia ---\n");
        return;
    }
    printf("\n=== Aviões na Pista de Decolagem ===\n");
    int pos = 1;
    while (no != NULL)
    {
        printf("[%02d] Modelo: %s | Ano: %d\n", pos, no->dado.modelo, no->dado.ano_de_fabricacao);
        no = no->prox;
        pos++;
    }
    printf("===================================\n");
}

void retirada(Fila_aviao *avi)
{
    Elem_ex5 *no;
    while(avi->inicio != NULL)
    {
        no = avi->inicio;
        avi->inicio = avi->inicio->prox;
        free(no);
    }
    free(avi);
}

int primeiro_aviao(Fila_aviao *avi)
{
    if (avi == NULL)
    {
        printf("\n[ERRO] Fila nao inicializada.\n");
        return 0;
    }

    if (avi->inicio == NULL)
    {
        printf("\n[AVISO] Nao ha avioes na fila.\n");
        return 0;
    }

    Elem_ex5 *no = avi->inicio;
    printf("\n--- Primeiro Aviao na Fila ---\n");
    printf("Modelo: %s\n", no->dado.modelo);
    printf("Ano de Fabricacao: %d\n", no->dado.ano_de_fabricacao);
    printf("-------------------------------\n");

    return 1;
}

int tamanho_aviao(Fila_aviao *avi)
{
    if (avi == NULL)
    {
        printf("\n[ERRO] Fila nao inicializada.\n");
        return -1;
    }

    printf("\n[INFO] Numero de avioes na fila: %d\n", avi->qtd);
    return avi->qtd;
}

/*
6) Implemente um método que receba três filas, duas já preenchidas em
ordem crescente e preencha a última com os valores das duas primeiras
em ordem crescente.

*/
void ordena_fila_reserva(Fila *fi_reserva)
{
    if (fi_reserva == NULL || fi_reserva->inicio == NULL)
        return;

    int trocou;
    Elem *atual;
    struct aluno temp;

    do
    {
        trocou = 0;
        atual = fi_reserva->inicio;

        while (atual->prox != NULL)
        {
            if (atual->dados.matricula > atual->prox->dados.matricula)
            {

                temp = atual->dados;
                atual->dados = atual->prox->dados;
                atual->prox->dados = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    }
    while (trocou);
}


void fila_compleento(Fila *fi, Fila *fi1, Fila *fi_reserva)
{
    Elem *no_1 = fi->inicio;
    Elem *no_2 = fi1->inicio;

    while (no_1 != NULL && no_2 != NULL)
    {
        insere_Fila(fi_reserva, no_1->dados);
        insere_Fila(fi_reserva, no_2->dados);

        no_1 = no_1->prox;
        no_2 = no_2->prox;
    }


    while (no_1 != NULL)
    {
        insere_Fila(fi_reserva, no_1->dados);
        no_1 = no_1->prox;
    }

    while (no_2 != NULL)
    {
        insere_Fila(fi_reserva, no_2->dados);
        no_2 = no_2->prox;
    }


    ordena_fila_reserva(fi_reserva);

}

/*
7) Implemente a função reverso, que reposiciona os elementos na fila de
tal forma que o início da fila torna-se o fim, e vice-versa.

*/
void fila_reversa(Fila *fi)
{
    Elem *ant = fi->inicio;
    Elem *no = ant->prox;
    Elem *aux;

    ant->prox = NULL;
    fi->final = ant;
    while(no != NULL)
    {
        aux = no->prox;
        no->prox = ant;
        ant = no;
        no = aux;
    }
    fi->inicio = ant;
}

/*
8) Faça um programa que apresente um menu contínuo com as seguintes
opções e execute de acordo com a escolha do usuário.
void menu()
{
 printf("1-Inicializa fila.\n");
 printf("2-Verifica se a fila é vazia.\n");
 printf("3-Verifica se a fila é cheia.\n");
 printf("4-Enfileira o elemento na fila.\n");
 printf("5-Desefileira elemento da fila.\n");
 printf("6-Le o número no início da fila.\n");
 printf("7-Testar qual fila possui mais elementos .\n");
 printf("8-Furar a fila .\n");
 printf("9-Sair.\n");
}
*/

void fura_fila(Fila *fi, struct aluno al)
{
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return;

    no->dados = al;
    no->prox = fi->inicio;
    fi->inicio = no;
    fi->qtd++;


}

void menu()
{
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila é vazia.\n");
    printf("3-Verifica se a fila é cheia.\n");
    printf("4-Enfileira o elemento na fila.\n");
    printf("5-Desefileira elemento da fila.\n");
    printf("6-Le o número no início da fila.\n");
    printf("7-Testar qual fila possui mais elementos .\n");
    printf("8-Furar a fila .\n");
    printf("9-Sair.\n");
}
