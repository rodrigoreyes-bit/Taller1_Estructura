#ifndef TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#define TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#include <string>
#include "ListaReproducción.hpp"
#include "Cancion.hpp"

using namespace std;


class Almacenamiento {
private:
    Nodo* str = nullptr;

public:
    Almacenamiento(); //Constructor
    void crearCanción(int id, string nombre, string artista, string album, int ano, int duracion, string ubicacion);

    void mostrarListaCanciones();

};


#endif //TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
