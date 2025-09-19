#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main()
{
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    struct aluno a2[4] =
    {
        {5, "Lucas", 8.2, 7.9, 9.0},
        {7, "Fernanda", 6.8, 8.1, 7.5},
        {6, "João", 9.1, 8.3, 8.7},
        {8, "Mariana", 7.4, 6.9, 8.0}
    };

    Fila* fi = cria_Fila();
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    int i;
    for(i=0; i < 4; i++)
    {
        insere_Fila(fi,a[i]);
        if(Fila_vazia(fi))
            printf("Erro!!!!!!\n");

        consulta_Fila(fi,&al);
        printf("Consulta: %d \t %s\n",al.matricula,al.nome);
    }

    printf("\n");

    imprime_Fila(fi);
    printf("\n");
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));

    printf("\n");

    //ex1
    Fila *f2 = cria_Fila();
    divorsio_edition(fi, f2, 1);
    printf("\n\n\n");

    //ex2
    //a
    File_file(fi);
    printf("\n");

    libera_Fila(fi);

    //b
    Pilha *pi = NULL;
    for(int i = 0; i < 4; i++)
    {
        empilhar(&pi, a[i]);

    }
    printf("\n");
    Fila_Pilha(pi);
    printf("\n\n\n");

    //c
    Fila *fi_2c = cria_Fila();
    for(int i = 0; i < 4; i++)
    {
        insere_Fila(fi_2c,a[i]);
        if(Fila_vazia(fi_2c))
            printf("Erro!!!!!!\n");

    }
    printf("\n");
    Pilha_de_Filas(fi_2c);
    printf("\n\n\n");

    //ex3
    Fila *fi_ex3 = cria_Fila();
    for(int i = 0; i < 4; i++)
    {
        insere_Fila(fi_ex3,a[i]);
        if(Fila_vazia(fi_ex3))
            printf("Erro!!!!!!\n");

    }
    imprime_Fila(fi_ex3);
    printf("\n");
    inverter_fila_com_pilha(fi_ex3);
    imprime_Fila(fi_ex3);
    printf("\n\n\n");

    //ex4

    Fila *f4 = cria_Fila();

    for(int i = 0; i < 4; i++)
    {
        Fila_Redonda(f4, a[i]);
        if(Fila_vazia(f4))
            printf("Erro!!!!!!\n");

    }

    imprimi_bolinha(f4);
    fura_fila_circular(f4, a[3]);
    printf("\n");
    imprimi_bolinha(f4);
    libera_planeta(f4);

    //ex5
    // ============================
    // Menu contínuo (exercício 5)
    // ============================
    Fila_aviao *fila = criar_aviao();
    if (fila == NULL)
    {
        fprintf(stderr, "Erro ao alocar fila\n");
        return 1;
    }
    int opcao;
    struct aviao novo;
    printf("\n\nPressione qualquer tecla para iniciar o menu do ex5...\n");
    getchar(); // aguarda entrada

    system("cls || clear"); // limpa console

    do
    {
        printf("\n=== Controle da Pista de Decolagem ===\n");
        printf("1 - Listar numero de avioes na fila\n");
        printf("2 - Autorizar decolagem do primeiro aviao\n");
        printf("3 - Adicionar um aviao a fila\n");
        printf("4 - Listar todos os avioes na fila\n");
        printf("5 - Listar caracteristicas do primeiro aviao\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n'); // limpa buffer
            continue;
        }
        getchar(); // limpa buffer do enter

        switch(opcao)
        {
        case 1:
            tamanho_aviao(fila);
            break;

        case 2:
            decolar_aviao(fila);
            printf("Primeiro aviao autorizado para decolagem.\n");
            break;

        case 3:
            printf("Digite o modelo do aviao: ");
            fgets(novo.modelo, sizeof(novo.modelo), stdin);
            novo.modelo[strcspn(novo.modelo, "\n")] = '\0'; // remover \n

            printf("Digite o ano de fabricacao: ");
            if (scanf("%d", &novo.ano_de_fabricacao) != 1)
            {
                printf("Ano invalido.\n");
                while (getchar() != '\n');
                break;
            }
            getchar(); // limpar buffer

            adiciona_aviao(fila, novo);
            printf("Aviao adicionado a fila!\n");
            break;

        case 4:
            pista_de_decolagem(fila);
            break;

        case 5:
            primeiro_aviao(fila);
            break;

        case 0:
            retirada(fila);
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
        }

        // Aguarda o usuário pressionar Enter antes de limpar a tela
        printf("\nPressione Enter para continuar...");
        getchar();
        system("cls || clear"); // limpa a tela após o Enter

    }
    while(opcao != 0);

    //ex6
    Fila *f1_ex6 = cria_Fila();
    Fila *f2_ex6 = cria_Fila();
    Fila *fi_reserva = cria_Fila();

    for(int i = 0; i < 4; i++)
    {
        insere_Fila(f1_ex6,a[i]);
        if(Fila_vazia(f1_ex6))
            printf("Erro!!!!!!\n");

    }
    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        insere_Fila(f2_ex6,a2[i]);
        if(Fila_vazia(f2_ex6))
            printf("Erro!!!!!!\n");

    }
    printf("\n");

    fila_compleento(f1_ex6, f2_ex6, fi_reserva);
    imprime_Fila(fi_reserva);

    libera_Fila(f1_ex6);
    libera_Fila(f2_ex6);
    libera_Fila(fi_reserva);

    //ex7
    Fila *fi_ex7 = cria_Fila();
    for(int i = 0; i < 4; i++)
    {
        insere_Fila(fi_ex7,a[i]);
        if(Fila_vazia(fi_ex7))
            printf("Erro!!!!!!\n");

    }
    //imprime_Fila(fi_ex7);
    printf("\n");
    fila_reversa(fi_ex7);
    imprime_Fila(fi_ex7);



    //ex8
    // ============================
    // Menu contínuo (exercício 8)
    // ============================
    Fila *fila1 = NULL;
    Fila *fila2 = NULL;
    int opcao_ex8;
    struct aluno al_ex8;

    printf("\n\nPressione qualquer tecla para iniciar o menu do ex5...\n");
    getchar(); // aguarda entrada
    system("cls || clear"); // limpa console

    do
    {
        menu();
        scanf("%d", &opcao_ex8);
        getchar(); // Limpa o buffer do teclado

        switch(opcao_ex8)
        {
        case 1:
            fila1 = cria_Fila();
            fila2 = cria_Fila();
            printf("Filas inicializadas com sucesso!\n");
            break;

        case 2:
            if(Fila_vazia(fila1))
                printf("Fila 1 está vazia.\n");
            else
                printf("Fila 1 possui elementos.\n");
            break;

        case 3:
            if(Fila_cheia(fila1))
                printf("Fila 1 está cheia.\n");
            else
                printf("Fila 1 não está cheia.\n");
            break;

        case 4:
            printf("Digite a matrícula: ");
            scanf("%d", &al_ex8.matricula);
            getchar();
            printf("Digite o nome: ");
            fgets(al_ex8.nome, 30, stdin);
            al.nome[strcspn(al_ex8.nome, "\n")] = '\0'; // Remove o '\n'
            printf("Digite as 3 notas: ");
            scanf("%f %f %f", &al_ex8.n1, &al_ex8.n2, &al_ex8.n3);
            insere_Fila(fila1, al_ex8);
            printf("Elemento inserido na fila.\n");
            break;

        case 5:
            if(remove_Fila(fila1))
                printf("Elemento removido da fila.\n");
            else
                printf("Fila vazia. Nada para remover.\n");
            break;

        case 6:
            if(consulta_Fila(fila1, &al))
            {
                printf("Elemento no inicio da fila:\n");
                printf("Matricula: %d\n", al_ex8.matricula);
                printf("Nome: %s\n", al_ex8.nome);
                printf("Notas: %.2f %.2f %.2f\n", al_ex8.n1, al_ex8.n2, al_ex8.n3);
            }
            else
            {
                printf("Fila vazia.\n");
            }
            break;

        case 7:
            if(tamanho_Fila(fila1) > tamanho_Fila(fila2))
                printf("Fila 1 possui mais elementos.\n");
            else if(tamanho_Fila(fila1) < tamanho_Fila(fila2))
                printf("Fila 2 possui mais elementos.\n");
            else
                printf("As duas filas possuem a mesma quantidade de elementos.\n");
            break;

        case 8:
            printf("Digite a matrícula: ");
            scanf("%d", &al_ex8.matricula);
            getchar();
            printf("Digite o nome: ");
            fgets(al_ex8.nome, 30, stdin);
            al.nome[strcspn(al_ex8.nome, "\n")] = '\0';
            printf("Digite as 3 notas: ");
            scanf("%f %f %f", &al_ex8.n1, &al_ex8.n2, &al_ex8.n3);
            fura_fila(fila1, al_ex8);
            printf("Elemento inserido no início da fila (furou a fila).\n");
            break;

        case 9:
            libera_Fila(fila1);
            libera_Fila(fila2);
            printf("Encerrando programa...\n");
            break;

        default:
            printf("Opcao inválida. Tente novamente.\n");
        }
        // Aguarda o usuário pressionar Enter antes de limpar a tela
        printf("\nPressione Enter para continuar...");
        getchar();
        system("cls || clear"); // limpa a tela após o Enter

    }
    while(opcao_ex8 != 9);

    return 0;
}



