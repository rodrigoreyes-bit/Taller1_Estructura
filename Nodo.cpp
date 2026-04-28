
#include "Nodo.h"
#include "Cancion.hpp"

Nodo::Nodo(Cancion cancion) {
    this->dato = cancion;
    this->siguiente = nullptr;
}