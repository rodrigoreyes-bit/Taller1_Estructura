//
// Created by Rodrigo on 4/9/2026.
//

#ifndef TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
#define TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
#include "Almacenamiento.hpp"

//Implementar listas entrelazadas en la lista de reproducción. Hacer struct de nodos con istancia de las canciones
//deseadas de manera privada

struct Nodo {
    Nodo *siguiente;
    Nodo *anterior;
    Canción *cancion;
};

class ListaReproducción {
private:
    Nodo *inicio;
    string estadoReproduccion;
    string estadoAleatorio;
    string estadoRepeticion;

public:
    ListaReproducción();

    void cambiarEstado();

    void adelantarCancion();
    // Debe tener conocimiento del estado de la repeticion, debe tener un protocolo para eliminar canciones de la lista
    // una vez ya se hayan reproducido, esto excepto a que la instancia de estadoRepeticion sea "Repetir Todas", en ese caso
    // se guardan las canciones.

    void retrocederCancion();

    void mostrarListaReproduccion();

    void protocoloAleatorio(int opcion);

};


#endif //TALLER1_ESTRUCTURA_LISTAREPRODUCCIÓN_HPP
