#include <stdio.h>
#include <stdlib.h>
#include "../TP4/arraylist/examples/example_4/inc/ArrayList.h"
#include "tramites.h"

/*
Datos de prueba
444 - 1 UR
222 - 1 NO
333 - 2 UR
888 - 3 UR
777 - 2 NO
*/

int main()
{
    char seguir = 's';
    int opcion = 0;

    ArrayList* urgentes = al_newArrayList();
    ArrayList* regulares = al_newArrayList();
    ArrayList* urgentesAtendidos = al_newArrayList();
    ArrayList* regularesAtendidos = al_newArrayList();

    int retornoOpcion;

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
                retornoOpcion = eTramiteUrgente_agregar(urgentes, urgentesAtendidos);
                if(retornoOpcion == 0)
                {
                    printf("\nAlta de Tramite Urgente OK");
                }
                break;
            case 2:
                retornoOpcion = eTramiteRegular_agregar(regulares, regularesAtendidos);
                if(retornoOpcion == 0)
                {
                    printf("\nAlta de Tramite Regular OK");
                }
                break;
            case 4:
                printf("\nTRAMITES URGENTES:\n");
                retornoOpcion = eTramiteUrgente_listar(urgentes);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Tramites Urgentes para listar\n");
                }

                printf("\nTRAMITES REGULARES:\n");
                retornoOpcion = eTramiteRegular_listar(regulares);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Tramites Regulares para listar\n");
                }
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
