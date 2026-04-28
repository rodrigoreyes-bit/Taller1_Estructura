#include "Almacenamiento.hpp"

#include <iostream>
#include <string>
using namespace std;

Almacenamiento::Almacenamiento() {}
//
vector<Cancion> Almacenamiento::getListaCanciones() {
}
//hola :3
void Almacenamiento::crearCanción(string id, string nombre, string artista, string album, int duracion) {
    Cancion *c = new Cancion(id, nombre, artista, album, duracion);

}

void Almacenamiento::mostrarListaCanciones() {
}







