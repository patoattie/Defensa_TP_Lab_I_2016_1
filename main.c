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

    ArrayList* urgentesNoAtendidos = al_newArrayList();
    ArrayList* regularesNoAtendidos = al_newArrayList();
    ArrayList* urgentesAtendidos = al_newArrayList();
    ArrayList* regularesAtendidos = al_newArrayList();

    int retornoOpcion;

    //eTramite_hardcodeo(urgentesNoAtendidos, urgentesAtendidos, regularesNoAtendidos, regularesAtendidos);
    eTramite_cargarDesdeArchivo(urgentesNoAtendidos, ARCHIVO_URGENTES_NO_ATENDIDOS);
    eTramite_cargarDesdeArchivo(urgentesAtendidos, ARCHIVO_URGENTES_ATENDIDOS);
    eTramite_cargarDesdeArchivo(regularesNoAtendidos, ARCHIVO_REGULARES_NO_ATENDIDOS);
    eTramite_cargarDesdeArchivo(regularesAtendidos, ARCHIVO_REGULARES_ATENDIDOS);

    while(seguir == 's')
    {
        system("cls");

        printf("1- Tramite Urgente\n");
        printf("2- Tramite Regular\n");
        printf("3- Proximo Cliente\n");
        printf("4- Listar No Atendidos\n");
        printf("5- Informar Atendidos\n");
        printf("6- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                retornoOpcion = eTramite_agregar(urgentesNoAtendidos, urgentesAtendidos, -1);
                if(retornoOpcion == 0)
                {
                    printf("\nAlta de Tramite Urgente OK");
                }
                break;
            case 2:
                retornoOpcion = eTramite_agregar(regularesNoAtendidos, regularesAtendidos, -1);
                if(retornoOpcion == 0)
                {
                    printf("\nAlta de Tramite Regular OK");
                }
                break;
            case 3:
                retornoOpcion = eTramite_proximoCliente(urgentesNoAtendidos, urgentesAtendidos, regularesNoAtendidos, regularesAtendidos);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Clientes para atender\n");
                }
                break;
            case 4:
                printf("\nTRAMITES URGENTES:\n");
                retornoOpcion = eTramite_listar(urgentesNoAtendidos);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Tramites Urgentes para listar\n");
                }

                printf("\nTRAMITES REGULARES:\n");
                retornoOpcion = eTramite_listar(regularesNoAtendidos);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Tramites Regulares para listar\n");
                }
                break;
            case 5:
                printf("\nTRAMITES URGENTES:\n");
                retornoOpcion = eTramite_listarOrdenado(urgentesAtendidos);
                if(retornoOpcion < 0)
                {
                    printf("\nNo hay Tramites Urgentes para listar\n");
                }

                printf("\nTRAMITES REGULARES:\n");
                retornoOpcion = eTramite_listarOrdenado(regularesAtendidos);
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

    eTramite_guardarEnArchivo(urgentesNoAtendidos, ARCHIVO_URGENTES_NO_ATENDIDOS);
    eTramite_guardarEnArchivo(urgentesAtendidos, ARCHIVO_URGENTES_ATENDIDOS);
    eTramite_guardarEnArchivo(regularesNoAtendidos, ARCHIVO_REGULARES_NO_ATENDIDOS);
    eTramite_guardarEnArchivo(regularesAtendidos, ARCHIVO_REGULARES_ATENDIDOS);

    return 0;
}
