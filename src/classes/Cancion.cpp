#include "../../include/classes/Cancion.hpp"

// Constructor
Cancion::Cancion(int id, string nombre, string artista, string album, int anio, int duracion, string ubicacion) {
    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->anio = anio;
    this->duracion = duracion;
    this->ubicacion = ubicacion;
}

int Cancion::getId() const {
    return id;
}
string Cancion::getNombre() const {
    return nombre;
}
string Cancion::getArtista() const {
    return artista;
}
string Cancion::getAlbum() const {
    return album;
}
int Cancion::getAnio() const {
    return anio;
}
int Cancion::getDuracion() const {
    return duracion;
}
string Cancion::getUbicacion() const {
    return ubicacion;
}
void Cancion::setId(int id) {
    this->id = id;
}
void Cancion::setNombre(string nombre) {
    this->nombre = nombre;
}
void Cancion::setArtista(string artista) {
    this->artista = artista;
}
void Cancion::setAlbum(string album) {
    this->album = album;
}
void Cancion::setAnio(int anio) {
    this->anio = anio;
}
void Cancion::setDuracion(int duracion) {
    this->duracion = duracion;
}
void Cancion::setUbicacion(string ubicacion) {
    this->ubicacion = ubicacion;
}