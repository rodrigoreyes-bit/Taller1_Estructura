
#include "../../include/data_structures/Nodo.h"
#include "../../include/classes/Cancion.hpp"

Nodo::Nodo(Cancion* cancion) {
    this->dato = cancion;
    this->siguiente = nullptr;
}