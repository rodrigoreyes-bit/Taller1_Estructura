#include "Almacenamiento.hpp"

#include <iostream>
#include <string>
using namespace std;

Almacenamiento::Almacenamiento() {
}

void Almacenamiento::crearCanción(int id, string nombre, string artista, string album, int ano, int duracion,
                                  string ubicacion) {
    Cancion *c = new Cancion(id, nombre, artista, album, ano, duracion, ubicacion);

    Nodo* cursor = str;

    if (!str->dato->getNombre().empty()) {
        str->dato = c;
    }else {

        while (cursor != nullptr) {
            if (cursor->siguiente == nullptr) {
                cursor->siguiente->dato = c;
            }

        }

    }
}

void Almacenamiento::mostrarListaCanciones() {
}
