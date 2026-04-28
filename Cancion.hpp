//
// Created by Rodrigo on 4/27/2026.
//

#include <string>
#include <iostream>
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
    Cancion();
    Cancion(int id, std::string nombre, std::string artista, std::string album,
            int anio, int duracion, std::string ubicacion);

    int getId();
    string getNombre();
    string getArtista();
    string getAlbum();
    int getAnio();
    int getDuracion();
    string getUbicacion();
};
