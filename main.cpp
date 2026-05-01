#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Almacenamiento.hpp"

using namespace std;

Almacenamiento* a = new Almacenamiento();

void lecturaCanciones() {
    ifstream archivo("music_source.txt");
    string linea;

    if (!archivo.is_open()) {
        cout << "Error: No se encontro music_source.txt" << endl;
        return;
    }
    //hola

    cout << "--- Contenido del archivo music_source.txt ---" << endl;

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
        getline(ss, ubicacion, ',');

        // ESTO ES PARA VER SI LEE EL ARCH !!!!!!!!!!!!!!!!
        cout << "ID: " << id << " | "
             << "Cancion: " << nombre << " | "
             << "Artista: " << artista << " | "
             << "Album: " << album << " [" << anio << "] | "
             << "Duracion: " << duracion << "s | "
             << "Ruta: " << ubicacion << endl;
        //int id, string nombre, string artista, string album, int ano, int duracion,
        //string ubicacion
        //a->crearCanción(stoi(id), nombre, artista, album,stoi(anio),stoi(duracion),ubicacion);

    }

    archivo.close();
}

int main() {
    lecturaCanciones();
    return 0;
}