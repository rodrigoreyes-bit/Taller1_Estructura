#ifndef TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#define TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#include <string>
#include <vector>
#include "ListaReproducción.hpp"
#include "Cancion.hpp"

using namespace std;


class Almacenamiento {
private:


public:
    Almacenamiento(); //Constructor
    vector<Cancion> getListaCanciones();

    void crearCanción(string id, string nombre, string artista, string album, int duracion);
    void mostrarListaCanciones();
};


#endif //TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
