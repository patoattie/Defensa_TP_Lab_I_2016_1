#include <stdio.h>
#include <stdlib.h>
#include "../TP4/arraylist/examples/example_4/inc/ArrayList.h"
#include "tramites.h"

//Funciones Comunes a ambas
int pedirDni(void)
{
    int dniCliente;

    printf("Ingrese su DNI: ");
    scanf("%d", &dniCliente);

    return dniCliente;
}

//Urgentes
eTramiteUrgente* eTramiteUrgente_nuevo(void)
{
    eTramiteUrgente* returnAux;
    returnAux = (eTramiteUrgente*)malloc(sizeof(eTramiteUrgente));
    return returnAux;
}

int eTramiteUrgente_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int retorno = -1;
    int guardoDato;
    int dniCliente;
    int turnoCliente;
    int huboError = 0;
    eTramiteUrgente* unTramite = eTramiteUrgente_nuevo();

    dniCliente = pedirDni();

    guardoDato = eTramiteUrgente_setDni(unTramite, dniCliente);
    if(guardoDato < 0)
    {
        huboError = 1;
    }

    turnoCliente = eTramiteUrgente_proximoTurno(listaNoAtendidos, listaAtendidos);

    guardoDato = eTramiteUrgente_setTurno(unTramite, turnoCliente);
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

int eTramiteUrgente_setDni(eTramiteUrgente* this, int dniCliente)
{
    int retorno = -1;

    if(dniCliente > 0 && this != NULL)
    {
        this->dni = dniCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramiteUrgente_getDni(eTramiteUrgente* this)
{
    int dniCliente = -1;

    if(this != NULL)
    {
        dniCliente = this->dni;
    }

    return dniCliente;
}

int eTramiteUrgente_setTurno(eTramiteUrgente* this, int turnoCliente)
{
    int retorno = -1;

    if(turnoCliente > 0 && this != NULL)
    {
        this->turno = turnoCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramiteUrgente_getTurno(eTramiteUrgente* this)
{
    int turnoCliente = -1;

    if(this != NULL)
    {
        turnoCliente = this->turno;
    }

    return turnoCliente;
}

void eTramiteUrgente_borrar(eTramiteUrgente* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int eTramiteUrgente_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int proximoTurno;
    int posicionUltimoAtendido;
    int posicionUltimoNoAtendido;
    int turnoUltimoAtendido = 0;
    int turnoUltimoNoAtendido = 0;
    eTramiteUrgente* tramiteAtendido = NULL;//eTramiteUrgente_nuevo();
    eTramiteUrgente* tramiteNoAtendido = NULL;//eTramiteUrgente_nuevo();

    if(listaNoAtendidos != NULL && listaAtendidos != NULL)
    {
        if(al_isEmpty(listaAtendidos) == 0)
        {
            posicionUltimoAtendido = al_len(listaAtendidos) - 1;
            tramiteAtendido = (eTramiteUrgente*)al_get(listaAtendidos, posicionUltimoAtendido);
            turnoUltimoAtendido = tramiteAtendido->turno;
        }

        if(al_isEmpty(listaNoAtendidos) == 0)
        {
            posicionUltimoNoAtendido = al_len(listaNoAtendidos) - 1;
            tramiteNoAtendido = (eTramiteUrgente*)al_get(listaNoAtendidos, posicionUltimoNoAtendido);
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

    //eTramiteUrgente_borrar(tramiteAtendido);
    //eTramiteUrgente_borrar(tramiteNoAtendido);

    return proximoTurno;
}

void eTramiteUrgente_imprimir(eTramiteUrgente* this)
{
    printf("%d - %d\n", eTramiteUrgente_getDni(this), eTramiteUrgente_getTurno(this));
}

int eTramiteUrgente_listar(ArrayList* listaNoAtendidos)
{
    int i;
    int retorno = -1;
    eTramiteUrgente* unTramite = NULL;//eTramiteUrgente_nuevo();

    for(i = 0; i < al_len(listaNoAtendidos); i++)
    {
        unTramite = (eTramiteUrgente*)al_get(listaNoAtendidos, i);
        if(unTramite != NULL)
        {
            eTramiteUrgente_imprimir(unTramite);
            retorno = 0;
        }
    }

    //eTramiteUrgente_borrar(unTramite);

    return retorno;
}

//Regulares
eTramiteRegular* eTramiteRegular_nuevo(void)
{
    eTramiteRegular* returnAux;
    returnAux = (eTramiteRegular*)malloc(sizeof(eTramiteRegular));
    return returnAux;
}

int eTramiteRegular_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int retorno = -1;
    int guardoDato;
    int dniCliente;
    int turnoCliente;
    int huboError = 0;
    eTramiteRegular* unTramite = eTramiteRegular_nuevo();

    dniCliente = pedirDni();

    guardoDato = eTramiteRegular_setDni(unTramite, dniCliente);
    if(guardoDato < 0)
    {
        huboError = 1;
    }

    turnoCliente = eTramiteRegular_proximoTurno(listaNoAtendidos, listaAtendidos);

    guardoDato = eTramiteRegular_setTurno(unTramite, turnoCliente);
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

int eTramiteRegular_setDni(eTramiteRegular* this, int dniCliente)
{
    int retorno = -1;

    if(dniCliente > 0 && this != NULL)
    {
        this->dni = dniCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramiteRegular_getDni(eTramiteRegular* this)
{
    int dniCliente = -1;

    if(this != NULL)
    {
        dniCliente = this->dni;
    }

    return dniCliente;
}

int eTramiteRegular_setTurno(eTramiteRegular* this, int turnoCliente)
{
    int retorno = -1;

    if(turnoCliente > 0 && this != NULL)
    {
        this->turno = turnoCliente;
        retorno = 0;
    }

    return retorno;
}

int eTramiteRegular_getTurno(eTramiteRegular* this)
{
    int turnoCliente = -1;

    if(this != NULL)
    {
        turnoCliente = this->turno;
    }

    return turnoCliente;
}

void eTramiteRegular_borrar(eTramiteRegular* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int eTramiteRegular_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos)
{
    int proximoTurno;
    int posicionUltimoAtendido;
    int posicionUltimoNoAtendido;
    int turnoUltimoAtendido = 0;
    int turnoUltimoNoAtendido = 0;
    eTramiteRegular* tramiteAtendido = NULL;//eTramiteRegular_nuevo();
    eTramiteRegular* tramiteNoAtendido = NULL;//eTramiteRegular_nuevo();

    if(listaNoAtendidos != NULL && listaAtendidos != NULL)
    {
        if(al_isEmpty(listaAtendidos) == 0)
        {
            posicionUltimoAtendido = al_len(listaAtendidos) - 1;
            tramiteAtendido = (eTramiteRegular*)al_get(listaAtendidos, posicionUltimoAtendido);
            turnoUltimoAtendido = tramiteAtendido->turno;
        }

        if(al_isEmpty(listaNoAtendidos) == 0)
        {
            posicionUltimoNoAtendido = al_len(listaNoAtendidos) - 1;
            tramiteNoAtendido = (eTramiteRegular*)al_get(listaNoAtendidos, posicionUltimoNoAtendido);
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

    //eTramiteRegular_borrar(tramiteAtendido);
    //eTramiteRegular_borrar(tramiteNoAtendido);

    return proximoTurno;
}

void eTramiteRegular_imprimir(eTramiteRegular* this)
{
    printf("%d - %d\n", eTramiteRegular_getDni(this), eTramiteRegular_getTurno(this));
}

int eTramiteRegular_listar(ArrayList* listaNoAtendidos)
{
    int i;
    int retorno = -1;
    eTramiteRegular* unTramite = NULL;//eTramiteRegular_nuevo();

    for(i = 0; i < al_len(listaNoAtendidos); i++)
    {
        unTramite = (eTramiteRegular*)al_get(listaNoAtendidos, i);
        if(unTramite != NULL)
        {
            eTramiteRegular_imprimir(unTramite);
            retorno = 0;
        }
    }

    //eTramiteRegular_borrar(unTramite);

    return retorno;
}
