#include <stdio.h>
#include <stdlib.h>
#include "../TP4/arraylist/examples/example_4/inc/ArrayList.h"
#include "tramites.h"

int main()
{
    char seguir = 's';
    int opcion = 0;

    ArrayList* urgentes = al_newArrayList();
    ArrayList* regulares = al_newArrayList();
    ArrayList* urgentesAtendidos = al_newArrayList();
    ArrayList* regularesAtendidos = al_newArrayList();

    while(seguir == 's')
    {
        system("cls");

        printf("1- Tramite Urgente\n");
        printf("2- Tramite Regular\n");
        printf("3- Proximo Cliente\n");
        printf("4- Listar\n");
        printf("5- Informar\n");
        printf("6- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion no valida, debe ingresar del 1 al 6");
        }

        if(seguir == 's')
        {
            printf("\n");
            system("pause");
        }
    }

    return 0;
}
