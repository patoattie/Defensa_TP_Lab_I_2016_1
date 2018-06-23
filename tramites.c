#include <stdio.h>
#include <stdlib.h>
#include "../TP4/arraylist/examples/example_4/inc/ArrayList.h"
#include "tramites.h"

int pedirDni(void)
{
    int dniCliente;

    printf("Ingrese su DNI: ");
    scanf("%d", &dniCliente);

    return dniCliente;
}

eTramite* eTramite_nuevo(void)
{
    eTramite* returnAux;
    returnAux = (eTramite*)malloc(sizeof(eTramite));
    return returnAux;
}

int eTramite_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int retorno = -1;
    int guardoDato;
    int dniCliente;
    int turnoCliente;
    int huboError = 0;
    eTramite* unTramite = eTramite_nuevo();

    dniCliente = pedirDni();

    guardoDato = eTramite_setDni(unTramite, dniCliente);
    if(guardoDato < 0)
    {
        huboError = 1;
    }

    turnoCliente = eTramite_proximoTurno(listaNoAtendidos, listaAtendidos);

    guardoDato = eTramite_setTurno(unTramite, turnoCliente);
    if(guardoDato < 0)
    {
        huboError = 1;
    }

    if(huboError == 0)
    {
        guardoDato = al_add(listaNoAtendidos, unTramite);
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

    if(huboError == 0)
    {
        retorno = 0;
    }

    return retorno;
}

int eTramite_setDni(eTramite* this, int dniCliente)
{
    int retorno = -1;

    if(dniCliente > 0 && this != NULL)
    {
        this->dni = dniCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramite_getDni(eTramite* this)
{
    int dniCliente = -1;

    if(this != NULL)
    {
        dniCliente = this->dni;
    }

    return dniCliente;
}

int eTramite_setTurno(eTramite* this, int turnoCliente)
{
    int retorno = -1;

    if(turnoCliente > 0 && this != NULL)
    {
        this->turno = turnoCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramite_getTurno(eTramite* this)
{
    int turnoCliente = -1;

    if(this != NULL)
    {
        turnoCliente = this->turno;
    }

    return turnoCliente;
}

void eTramite_borrar(eTramite* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int eTramite_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int proximoTurno;
    int posicionUltimoAtendido;
    int posicionUltimoNoAtendido;
    int turnoUltimoAtendido = 0;
    int turnoUltimoNoAtendido = 0;
    eTramite* tramiteAtendido = NULL;
    eTramite* tramiteNoAtendido = NULL;

    if(listaNoAtendidos != NULL && listaAtendidos != NULL)
    {
        if(al_isEmpty(listaAtendidos) == 0)
        {
            posicionUltimoAtendido = al_len(listaAtendidos) - 1;
            tramiteAtendido = (eTramite*)al_get(listaAtendidos, posicionUltimoAtendido);
            turnoUltimoAtendido = tramiteAtendido->turno;
        }

        if(al_isEmpty(listaNoAtendidos) == 0)
        {
            posicionUltimoNoAtendido = al_len(listaNoAtendidos) - 1;
            tramiteNoAtendido = (eTramite*)al_get(listaNoAtendidos, posicionUltimoNoAtendido);
            turnoUltimoNoAtendido = tramiteNoAtendido->turno;
        }
    }

    if(turnoUltimoAtendido > turnoUltimoNoAtendido)
    {
        proximoTurno = turnoUltimoAtendido;
    }
    else
    {
        proximoTurno = turnoUltimoNoAtendido;
    }

    proximoTurno++;

    return proximoTurno;
}

void eTramite_imprimir(eTramite* this)
{
    printf("%d - %d\n", eTramite_getDni(this), eTramite_getTurno(this));
}

int eTramite_listar(ArrayList* lista)
{
    int i;
    int retorno = -1;
    eTramite* unTramite = NULL;

    for(i = 0; i < al_len(lista); i++)
    {
        unTramite = (eTramite*)al_get(lista, i);
        if(unTramite != NULL)
        {
            eTramite_imprimir(unTramite);
            retorno = 0;
        }
    }

    return retorno;
}

int eTramite_proximoCliente(ArrayList* urgentesNoAtendidos, ArrayList* urgentesAtendidos, ArrayList* regularesNoAtendidos, ArrayList* regularesAtendidos)
{
    int retorno = -1;

    if(urgentesNoAtendidos != NULL && urgentesAtendidos != NULL && regularesNoAtendidos != NULL && regularesAtendidos != NULL)
    {
        retorno = eTramite_atenderCliente(urgentesNoAtendidos, urgentesAtendidos);

        if(retorno < 0) //No hay urgentes para atender
        {
            retorno = eTramite_atenderCliente(regularesNoAtendidos, regularesAtendidos);
        }
    }

    return retorno;
}

int eTramite_atenderCliente(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int retorno = -1;
    eTramite* unTramite = NULL;

    if(listaNoAtendidos != NULL && listaAtendidos != NULL)
    {
        if(al_isEmpty(listaNoAtendidos) == 0)
        {
            unTramite = (eTramite*)al_pop(listaNoAtendidos, 0);
            retorno = al_add(listaAtendidos, unTramite);

            if(retorno == 0) //Alta OK
            {
                printf("PROXIMO CLIENTE:\n");
                eTramite_imprimir(unTramite);
            }
        }
    }

    return retorno;
}
