#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "room/room.c"

int main()
{
    setlocale(LC_ALL, "portuguese");

    int user_menuOption;

    do
    {
        printf("-------| Hotel Descanso Garantido |-------\n\n");

        printf("\t1 - Cadastrar Cliente\n");
        printf("\t2 - Cadastrar Funcion�rio\n");
        printf("\t3 - Cadastrar Estadia\n");
        printf("\t4 - Cadastrar Quarto\n");

        printf("\nDigite o n�mero da op��o desejada: ");
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
                registerRoom();
                break;

            default:
                printf("\n**Op��o Inv�lida! Tente novamente**");
                getchar();
                fflush(stdin);
        }
        system("cls || clear");

    } while(user_menuOption != 0);


    return 0;
}
