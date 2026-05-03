#ifndef TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#define TALLER1_ESTRUCTURA_LISTAREPRODUCCION_HPP
#include "../classes/Almacenamiento.hpp"
#include "Nodo.h"

//Implementar listas entrelazadas en la lista de reproducción. Hacer struct de nodos con instancia de las canciones
//deseadas de manera privada

class ListaReproduccion {
private:
    Nodo* inicio; ///no se si sacarlo o
    string estadoReproduccion;
    string estadoAleatorio;
    string estadoRepeticion;

public:
    ListaReproduccion();
    void agregarAlFinal(Cancion* cancion);
    void cambiarEstado();
    void adelantarCancion();
    // Debe tener conocimiento del estado de la repeticion, debe tener un protocolo para eliminar canciones de la lista
    // una vez ya se hayan reproducido, esto excepto a que la instancia de estadoRepeticion sea "Repetir Todas", en ese caso
    // se guardan las canciones.

    void retrocederCancion();

    void mostrarListaReproduccion();
    void saltarACancion(int pos);

    void protocoloAleatorio(int opcion);

};
#endif //TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
