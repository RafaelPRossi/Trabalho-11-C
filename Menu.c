
// Um menu para cadastro, consulta e vendas de produtos

/* BIBLIOTECAS */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* VARIAVEIS GLOBAIS */
// é possivel ver e editar elas a partir todas as funções
int     operacao;
int     tamanho = 0;

char    produto[10][20];
int     codigo[10];
int     quantidade[10];
float   valor[10];

char    cliente[10][20] = {""}; //isso deixa todos os clientes vazios
float   venda[10];
int     quantidade_vendida[10];

/* FUNÇÕES */

// função para gerar o cabecalho (para não ter que ficar fazendo isso toda hora)
void cabecalho()
{
    printf("|-----------------------------------------------------|\n");

    switch(operacao)
    {
    case 1:
        printf("|---------------------- CADASTRO ---------------------|\n");
        break;
    case 2:
        printf("|---------------------- CONSULTA ---------------------|\n");
        break;
    case 3:
        printf("|------------------- BAIXA DO ESTOQUE ----------------|\n");
        break;
    case 4:
        printf("|------------------- RELATORIO VENDAS ----------------|\n");
        break;
    case 5:
        printf("|------------------ RELATORIO ESTOQUE ----------------|\n");
        break;
    }
    printf("|-----------------------------------------------------|\n\n");
}

void cadastrar()
{
    //VARIAVEIS LOCAIS
    //só podem ser vistas e editadas nesta função
    char continuar;

    do
    {
        if(tamanho == 10)
        {
            break;
        }

        cabecalho();
        printf("                     ESTOQUE [%i/10]                   \n", tamanho+1);

        printf("\nPRODUTO - \t");
        fgets(produto[tamanho],20,stdin);
        fflush(stdin);

        printf("CODIGO - \t%i\n", tamanho);
        codigo[tamanho] = tamanho;
        fflush(stdin);

        printf("VALOR - \t");
        scanf("%f", &valor[tamanho]);
        fflush(stdin);

        printf("QUANTIDADE - \t");
        scanf("%i", &quantidade[tamanho]);
        fflush(stdin);

        tamanho++;

        do
        {
            printf("\nDESEJA CONTINUAR [S/N]? ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            fflush(stdin);
        }
        while(continuar != 'S' && continuar != 'N');

        system("cls");
    }
    while(continuar == 'S');
}

void consulta()
{
    //VARIAVEIS LOCAIS
    char produto_desejado[20];
    int i;
    int achou;
    char continuar;

    do
    {
        cabecalho();

        printf("PRODUTO DESEJADO: ");
        fgets(produto_desejado,20,stdin);
        fflush(stdin);

        i = 0;
        achou = 0;

        while(i < tamanho)
        {
                if(strcmp(produto_desejado,produto[i]) == 0)
                {
                    achou = 1;
                    printf("\n|-----------------------------------------------------|");
                    printf("\n|               PRODUTO - FOI ENCONTRADO              |", produto[i]);
                    printf("\n|-----------------|-----------------|-----------------|");
                    printf("\n|      CODIGO     |      VALOR      |    QUANTIDADE   |");
                    printf("\n|-----------------|-----------------|-----------------|");
                    printf("\n        %i             R$%.2f               %i         ", codigo[i], valor[i], quantidade[i]);
                    printf("\n-------------------------------------------------------\n");
                }
            i++;
        }

        if(achou == 0)
        {
            printf("\nPRODUTO - NAO FOI ENCONTRADO\n", produto[i]);
        }

        do
        {
            printf("DESEJA CONTINUAR [S/N]? ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            fflush(stdin);
        }
        while(continuar != 'S' && continuar != 'N');

        system("cls");
    }
    while(continuar == 'S');
}

void baixa()
{
    //VARIAVEIS LOCAIS
    char produto_desejado[20];
    int i;
    int achou;
    char continuar;

    do
    {
        cabecalho();

        printf("PRODUTO DESEJADO: ");
        fgets(produto_desejado,20,stdin);
        fflush(stdin);

        i = 0;
        achou = 0;

        while(i < tamanho)
        {
                if(strcmp(produto_desejado,produto[i]) == 0)
                {
                    achou = 1;

                    printf("COMPRADOR - \t");
                    fgets(cliente[i],20,stdin);
                    fflush(stdin);
                    cliente[i][strcspn(cliente[i], "\n")] = 0;

                    printf("QUANTIDADE VENDIDA - \t");
                    scanf("%i", &quantidade_vendida[i]);
                    fflush(stdin);

                    venda[i] = quantidade_vendida[i] * valor[i];

                    quantidade[i] = quantidade[i] - quantidade_vendida[i];
                }
            i++;
        }

        if(achou == 0)
        {
            printf("\nPRODUTO - NAO FOI ENCONTRADO\n", produto[i]);
        }

        do
        {
            printf("DESEJA CONTINUAR [S/N]? ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            fflush(stdin);
        }
        while(continuar != 'S' && continuar != 'N');

        system("cls");
    }
    while(continuar == 'S');
}

void relatorio_vendas()
{
    //VARIAVEIS LOCAIS
    char produto_desejado[20];
    int i;
    int achou;
    char continuar;

    do
    {
        cabecalho();

        i = 0;

        printf("\n|-----------------|-----------------|-----------------|");
        printf("\n|     CLIENTE     |   VALOR VENDA   |    QUANTIDADE   |");
        printf("\n|-----------------|-----------------|-----------------|");

        while(i < tamanho)
        {
                if(strcmp(cliente[i],"") == 0)
                {
                    //cliente vazio não faz nada (poderia ter adcionado um ! na condição do IF, faria a mesma coisa.
                }
                else
                {
                    printf("\n        %s           %.2f            %i          ", cliente[i], venda[i], quantidade_vendida[i]);
                    printf("\n|-----------------------------------------------------|");
                }
            i++;
        }

        do
        {
            printf("\nDESEJA CONTINUAR [S/N]? ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
            fflush(stdin);
        }
        while(continuar != 'S' && continuar != 'N');

        system("cls");
    }
    while(continuar == 'S');
}

void relatorio_estoque()
{
    int i;

    printf("\n|-----------------|-----------------|-----------------|");
    printf("\n|      CODIGO     |      VALOR      |    QUANTIDADE   |");
    printf("\n|-----------------|-----------------|-----------------|");

    i = 0;
    while(i < tamanho)
    {
        printf("\n        %i               %.2f               %i         ", codigo[i], valor[i], quantidade[i]);
        printf("\n|-----------------------------------------------------|");

        i++;
    }
    printf("\n");
    system("pause");
    system("cls");
}

/* FUNÇÃO PRINCIPAL */

int main()
{
    do
    {
        printf("\n------------------------- MENU -----------------------\n");
        printf("[1] CADASTRO DE PRODUTOS    \n");
        printf("[2] CONSULTA DE PRODUTOS    \n");
        printf("[3] BAIXA DE PRODUTOS       \n");
        printf("[4] RELATORIO DE VENDAS     \n");
        printf("[5] RELATORIO DO ESTOQUE    \n");
        printf("[6] SAIR DO SISTEMA       \n\n");

        printf("INFORME SUA OPCAO: ");
        scanf("%i", &operacao);
        fflush(stdin);
        printf("\n------------------------------------------------------\n");

        switch(operacao)
        {
        case 1:
            system("cls");
            cadastrar();
            break;
        case 2:
            system("cls");
            consulta();
            break;
        case 3:
            system("cls");
            baixa();
            break;
        case 4:
            system("cls");
            relatorio_vendas();
            break;
        case 5:
            system("cls");
            relatorio_estoque();
            break;
        case 6:
            return 0;

        default:
            printf("OPCAO INVALIDA TENTE NOVAMENTE: ");
            system("pause");
            system("cls");
        }
    }
    while(operacao >= 1 || operacao <= 6);

    return 0;
}
