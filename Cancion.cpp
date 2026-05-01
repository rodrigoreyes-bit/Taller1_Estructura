#include "Cancion.hpp"

Cancion::Cancion(int id, string nombre, string artista, string album, int ano, int duracion, string ubicacion) {
    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->anio = ano;
    this->duracion = duracion;
    this->ubicacion = ubicacion;
}

Cancion::Cancion() : id(0), anio(0), duracion(0) {}

int Cancion::getId() const {
    return id;
}
string Cancion::getNombre() const {
    return nombre;
}
string Cancion::getArtista() const {
    return artista;
}