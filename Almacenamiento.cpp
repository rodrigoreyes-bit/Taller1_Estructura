#include "Almacenamiento.hpp"

#include <iostream>
#include <string>
#include <vector> //esto se tiene que sacar >:c
using namespace std;

Almacenamiento::Almacenamiento() {}

vector<Canción> Almacenamiento::getListaCanciones() {
    return this->listaCanciones;
}
//hola :3
void Almacenamiento::crearCanción(string id, string nombre, string artista, string album, int duracion) {
    Canción *c = new Canción(id, nombre, artista, album, duracion);
    listaCanciones.push_back(*c);

}

void Almacenamiento::mostrarListaCanciones() {
    for (Canción c : this->listaCanciones) {
        cout << c.nombre << endl;
    }
}







