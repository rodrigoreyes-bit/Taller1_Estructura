#include "Almacenamiento.hpp"
#include <string>
#include <vector>
using namespace std;

Almacenamiento::Almacenamiento() {}

vector<Canción> Almacenamiento::getListaCanciones() {
    return this->listaCanciones;
}

void Almacenamiento::crearCanción(string id, string nombre, string artista, string album, float duracion) {
    Canción *c = new Canción(id, nombre, artista, album, duracion);
    listaCanciones.push_back(c);

}








