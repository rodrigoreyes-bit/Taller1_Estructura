//
// Created by Rodrigo on 4/27/2026.
//

#ifndef TALLER1_ESTRUCTURA_CANCION_HPP
#define TALLER1_ESTRUCTURA_CANCION_HPP
#include <string>

using namespace std;

class Cancion {
private:
    int id;
    string nombre;
    string artista;
    string album;
    int anio;
    int duracion;
    string ubicacion;

public:
    Cancion(int id, string nombre, string artista, string album,
            int anio, int duracion, string ubicacion);

    Cancion();

    int getId() const;

    string getNombre() const;

    string getArtista() const;
};


#endif //TALLER1_ESTRUCTURA_CANCION_HPP
