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

//c:

//ex4
int Fila_Redonda(Fila* f1, struct aluno al);
void imprimi_bolinha(Fila *f1);

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
