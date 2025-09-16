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


    Fila *f2 = cria_Fila();
    divorsio_edition(fi, f2, 1);
    printf("\n\n\n");



    File_file(fi);
    printf("\n");


    Fila *f4 = cria_Fila();

    libera_Fila(fi);

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

    return 0;
}


