#ifndef NODO_H
#define NODO_H
#include "Cancion.hpp"

class Nodo {
public:
    Cancion* dato;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Cancion* cancion);
};
#endif