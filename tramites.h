#ifndef TRAMITES_H_INCLUDED
#define TRAMITES_H_INCLUDED

typedef struct
{
    int turno;
    int dni;
} eTramiteUrgente;

typedef struct
{
    int turno;
    int dni;
} eTramiteRegular;

//Funciones Comunes a ambas
int pedirDni(void);

//Urgentes
eTramiteUrgente* eTramiteUrgente_nuevo(void);
int eTramiteUrgente_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
int eTramiteUrgente_setDni(eTramiteUrgente* this, int dniCliente);
int eTramiteUrgente_getDni(eTramiteUrgente* this);
int eTramiteUrgente_setTurno(eTramiteUrgente* this, int turnoCliente);
int eTramiteUrgente_getTurno(eTramiteUrgente* this);
void eTramiteUrgente_borrar(eTramiteUrgente* this);
int eTramiteUrgente_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
void eTramiteUrgente_imprimir(eTramiteUrgente* this);
int eTramiteUrgente_listar(ArrayList* listaNoAtendidos);

//Regulares
eTramiteRegular* eTramiteRegular_nuevo(void);
int eTramiteRegular_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
int eTramiteRegular_setDni(eTramiteRegular* this, int dniCliente);
int eTramiteRegular_getDni(eTramiteRegular* this);
int eTramiteRegular_setTurno(eTramiteRegular* this, int turnoCliente);
int eTramiteRegular_getTurno(eTramiteRegular* this);
void eTramiteRegular_borrar(eTramiteRegular* this);
int eTramiteRegular_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
void eTramiteRegular_imprimir(eTramiteRegular* this);
int eTramiteRegular_listar(ArrayList* listaNoAtendidos);

#endif // TRAMITES_H_INCLUDED
