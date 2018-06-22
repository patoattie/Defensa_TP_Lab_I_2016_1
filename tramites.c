#include <stdio.h>
#include <stdlib.h>
#include "../TP4/arraylist/examples/example_4/inc/ArrayList.h"
#include "tramites.h"

eTramiteUrgente* nuevoTramiteUrgente(void)
{
    eTramiteUrgente* returnAux;
    returnAux = (eTramiteUrgente*)malloc(sizeof(eTramiteUrgente));
    return returnAux;
}

int agregarTramiteUrgente(ArrayList* listaTramite)
{
    int retorno = -1;
    int huboError = 0;
    int guardoDato;
    char nombre[TAM_NOMBRE];
    eTramiteUrgente* unTramite = employee_new();

    retorno = 0;

    if(huboError == 0)
    {
        pedirString("Ingrese nombre del empleado: ", nombre, TAM_NOMBRE);
        if(strcmp(nombre, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
            huboError = 1;
        }
    }

    if(huboError == 0)
    {
        pedirString("Ingrese apellido del empleado: ", apellido, TAM_APELLIDO);
        if(strcmp(apellido, "") == 0)
        {
            printf("El dato es obligatorio, por favor reingrese\n");
            huboError = 1;
        }
    }

    if(huboError == 0)
    {
        guardoDato = employee_setId(unEmpleado, employee_nuevoId(arrayEmpleados));
        if(guardoDato < 0)
        {
            huboError = 1;
        }

        guardoDato = employee_setName(unEmpleado, nombre);
        if(guardoDato < 0)
        {
            huboError = 1;
        }

        guardoDato = employee_setLastName(unEmpleado, apellido);
        if(guardoDato < 0)
        {
            huboError = 1;
        }

        guardoDato = employee_setIsEmpty(unEmpleado, 0);
        if(guardoDato < 0)
        {
            huboError = 1;
        }

        if(huboError == 0)
        {
            guardoDato = al_add(arrayEmpleados, unEmpleado);
            if(guardoDato < 0) //Hubo error
            {
                huboError = 1;
                printf("Error al guardar los datos en el array list\n");
            }
        }
        else
        {
            printf("Error al guardar los datos en la estructura\n");
        }
    }
    else
    {
        printf("Error de carga de datos, por favor reingrese\n");
    }

    if(huboError == 0)
    {
        retorno = 1;
    }

    return retorno;
}

int setDni(void)
{
    int retorno = -1;
    int dniCliente;

    printf("Ingrese su DNI: ");
    scanf("%d", &dniCliente);

    if(dniCliente > 0)
    {
        retorno = dniCliente;
    }

    return retorno;
}
