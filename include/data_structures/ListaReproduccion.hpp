#ifndef TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#define TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#include "../classes/Almacenamiento.hpp"
#include "Nodo.h"
class Configuracion;

class ListaReproduccion {
private:
    Nodo* inicio;
    Nodo* actual;
    string estadoReproduccion;
    string estadoAleatorio;
    string estadoRepeticion;

public:
    ListaReproduccion();


    void cambiarEstado();
    void adelantarCancion();
    // Debe tener conocimiento del estado de la repeticion, debe tener un protocolo para eliminar canciones de la lista
    // una vez ya se hayan reproducido, esto excepto a que la instancia de estadoRepeticion sea "Repetir Todas", en ese caso
    // se guardan las canciones.



    void setEstadoReproduccion(string estado);
    Cancion* getCancionActual();
    void cambiarEstadoReproduccion(Configuracion* c); //W
    void pistaAnterior(); //Q
    void pistaSiguiente(Almacenamiento* alm); //E

    void agregarAlFinal(Cancion* cancion);
    void mostrarListaReproduccion(); //A
    void saltarACancion(int pos); //A
    void reproducirAltiro(Cancion* cancion); //A

    void protocoloAleatorio(int opcion);

};
#endif //TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
