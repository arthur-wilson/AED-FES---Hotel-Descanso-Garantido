#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int user_menuOption;

    do
    {
        printf("-------| Hotel Descanso Garantido |-------\n\n");

        printf("\t1 - Cadastrar Cliente\n");
        printf("\t2 - Cadastrar Funcionário\n");
        printf("\t3 - Cadastrar Estadia\n");
        printf("\t4 - Cadastrar Quarto\n");

        printf("\nDigite o número da opção desejada: ");
        scanf("%i", &user_menuOption);
        fflush(stdin);

        switch(user_menuOption)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                printf("\n**Opção Inválida! Tente novamente**");
                getchar();
                fflush(stdin);
        }
        system("cls");

    } while(user_menuOption != 0);


    return 0;
}
