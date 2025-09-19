//Arquivo FilaDin.h
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);




//ex1
int divorsio_edition(Fila *f1, Fila *f2, int n);

//ex2
//a:
typedef struct fila_fila Fila_Fila;

Fila_Fila *criar_file();
void insere_file(Fila_Fila *fi_fi, Fila *fi);
void imprime_fi_fi(Fila_Fila *fi_fi);
void File_file(Fila *fi);

//b:
typedef struct fila_de_pilhas Fila_De_Pilhas;
typedef struct pilha Pilha;
Pilha *criar_pilha();
Fila_De_Pilhas *criar_fila_pi();
void empilhar(Pilha **pi, struct aluno al);
void insere_pi(Fila_De_Pilhas *fi, Pilha *pi);
void Imprimi_Pilha(Pilha *pi);
void imprime_Fi_PI(Fila_De_Pilhas *fi_pi);
void Fila_Pilha(Pilha *pi);
void liberar_pilha(Pilha *pi);

//c:
typedef struct Elem_PiFi Pilha_Fila;
void empilhar_fila(Pilha_Fila **pi_fi, Fila *fila);
void imprime_pilha_filas(Pilha_Fila *pi_fi);
void Pilha_de_Filas(Fila *f1);

//ex3

//ex4
int Fila_Redonda(Fila* f1, struct aluno al);
void imprimi_bolinha(Fila *f1);
void fura_fila_circular(Fila *fi, struct aluno al);

//ex5
struct aviao
{
    char modelo[20];
    int ano_de_fabricacao;

};

typedef struct fila_aviao Fila_aviao;

Fila_aviao *criar_aviao();
void adiciona_aviao(Fila_aviao *avi, struct aviao modelo);
int decolar_aviao(Fila_aviao *avi);
void pista_de_decolagem(Fila_aviao *avi);
void retirada(Fila_aviao *avi);
int primeiro_aviao(Fila_aviao *avi);
int tamanho_aviao(Fila_aviao *avi);

//ex6
void ordena_fila_reserva(Fila *fi_reserva);
void fila_compleento(Fila *fi, Fila *fi1, Fila *fi_reserva);

//ex7
void fila_reversa(Fila *fi);

//ex8
void fura_fila(Fila *fi, struct aluno al);
void menu();
