#ifndef TRAMITES_H_INCLUDED
#define TRAMITES_H_INCLUDED

#define ARCHIVO_URGENTES_NO_ATENDIDOS "UrgentesNoAtendidos.dat"
#define ARCHIVO_URGENTES_ATENDIDOS "UrgentesAtendidos.dat"
#define ARCHIVO_REGULARES_NO_ATENDIDOS "RegularesNoAtendidos.dat"
#define ARCHIVO_REGULARES_ATENDIDOS "RegularesAtendidos.dat"

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
void eTramite_cargarDesdeArchivo(ArrayList* lista, char* nombreArchivo);
void eTramite_guardarEnArchivo(ArrayList* lista, char* nombreArchivo);

#endif // TRAMITES_H_INCLUDED
