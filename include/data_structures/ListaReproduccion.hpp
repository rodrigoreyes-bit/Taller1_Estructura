#ifndef TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#define TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#include "../classes/Almacenamiento.hpp"
#include "Nodo.h"
class Configuracion;

class ListaReproduccion {
private:
    Nodo* inicio;
    Nodo* actual;


public:
    ListaReproduccion();

    Cancion* getCancionActual();
    void cambiarEstadoReproduccion(Configuracion* c); //W
    void pistaAnterior(Configuracion* c); //Q
    void pistaSiguiente(Almacenamiento* alm, Configuracion* c); //E

    void agregarAlFinal(Cancion* cancion);
    void mostrarListaReproduccion(); //A
    void saltarACancion(int pos, Configuracion* c); //A
    void reproducirAltiro(Cancion* cancion, Configuracion* c); //A
    void repetirCanciones(int modoRepe, Configuracion* c, Almacenamiento* alm); //r
    void mezclarListaRepeticion(Almacenamiento* alm, Configuracion* c); // r y s


};
#endif //TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
