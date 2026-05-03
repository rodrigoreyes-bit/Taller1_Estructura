#ifndef TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#define TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#include <iostream>
#include <string>
#include "../data_structures/Nodo.h"

using namespace std;


class Almacenamiento {
public:
    Nodo* str = nullptr;
    Almacenamiento();
    void crearCanción(int id, string nombre, string artista, string album, int ano, int duracion, string ubicacion);

    void mostrarListaCanciones();
};


#endif //TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP