#ifndef TRAMITES_H_INCLUDED
#define TRAMITES_H_INCLUDED

typedef struct
{
    int turno;
    int dni;
} eTramite;

int pedirDni(void);

eTramite* eTramite_nuevo(void);
void eTramite_hardcodeo(ArrayList* urgentesNoAtendidos, ArrayList* urgentesAtendidos, ArrayList* regularesNoAtendidos, ArrayList* regularesAtendidos);
int eTramite_agregar(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos, int dniCliente);
int eTramite_setDni(eTramite* this, int dniCliente);
int eTramite_getDni(eTramite* this);
int eTramite_setTurno(eTramite* this, int turnoCliente);
int eTramite_getTurno(eTramite* this);
void eTramite_borrar(eTramite* this);
int eTramite_proximoTurno(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
void eTramite_imprimir(eTramite* this);
int eTramite_listar(ArrayList* lista);
int eTramite_proximoCliente(ArrayList* urgentesNoAtendidos, ArrayList* urgentesAtendidos, ArrayList* regularesNoAtendidos, ArrayList* regularesAtendidos);
int eTramite_atenderCliente(ArrayList* listaNoAtendidos, ArrayList* listaAtendidos);
int eTramite_listarOrdenado(ArrayList* lista);
int eTramite_ordenarPorDni(void* tramiteA, void* tramiteB);

#endif // TRAMITES_H_INCLUDED
