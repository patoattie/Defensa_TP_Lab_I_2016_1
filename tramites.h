#ifndef TRAMITES_H_INCLUDED
#define TRAMITES_H_INCLUDED

typedef struct
{
    int turno;
    int dni;
} eTramiteUrgente;

eTramiteUrgente* nuevoTramiteUrgente(void);
int agregarTramiteUrgente(ArrayList* listaTramite, void* elementoTramite);
int setDni(void);

#endif // TRAMITES_H_INCLUDED
