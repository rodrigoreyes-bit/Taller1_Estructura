#include <iostream>
#include <fstream>
#include <sstream>
#include "Almacenamiento.hpp"

using namespace std;

void lecturaCanciones(Almacenamiento* a) {
    ifstream archivo("music_source.txt");
    string linea;

    if (!archivo.is_open()) {
        cout << "Error: No se encontro music_source.txt" << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string id, nombre, artista, album, anio, duracion, ubicacion;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, anio, ',');
        getline(ss, duracion, ',');
        getline(ss, ubicacion);

        try {
            a->crearCanción(stoi(id), nombre, artista, album, stoi(anio), stoi(duracion), ubicacion);
        } catch (...) {
        }
    }
    archivo.close();
}

int main() {
    Almacenamiento* a = new Almacenamiento();
    lecturaCanciones(a);
    a->mostrarListaCanciones();
    return 0;
}