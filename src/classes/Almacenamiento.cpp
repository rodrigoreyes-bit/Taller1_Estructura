#include "../../include/classes/Almacenamiento.hpp"
#include <iostream>

Almacenamiento::Almacenamiento() {
    this->str = nullptr;
}

void Almacenamiento::crearCanción(int id, string nombre, string artista, string album, int ano, int duracion, string ubicacion) {
    Cancion *nuevaCancion = new Cancion(id, nombre, artista, album, ano, duracion, ubicacion);
    Nodo *nuevoNodo = new Nodo(nuevaCancion);

    if (str == nullptr) {
        str = nuevoNodo;
    } else {
        Nodo *cursor = str;
        while (cursor->siguiente != nullptr) {
            cursor = cursor->siguiente;
        }
        cursor->siguiente = nuevoNodo;
        nuevoNodo->anterior = cursor;
    }
}

void Almacenamiento::mostrarListaCanciones() {
    Nodo *cursor = str;
    if (cursor == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    while (cursor != nullptr) {
        cout << "ID: " << cursor->dato->getId() << " - " << cursor->dato->getNombre() << endl;
        cursor = cursor->siguiente;
    }
}