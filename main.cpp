#include <iostream>
#include <fstream>
#include <sstream>
#include "Almacenamiento.hpp"
using namespace std;

Almacenamiento *almacenamiento = new Almacenamiento();

void lecturaCanciones() {
    //Falta control de error en esta lectura, en vola implementar strategy en logica
    ifstream archivo("music_source.txt");
    string linea;

    if (!archivo.is_open()) cout << "Error al abrir el archivo";

    while (getline(archivo, linea)) {
        vector<string> split;
        //stringstream modifica string a propiedades secuenciales sin indices. Permite leer un string
        //linea por linea (como input por consola) usando getline().
        stringstream stream(linea);
        string auxSplit;
        //getline(Linea actual stream, variable donde guardar fragmentos, Guia de fragmento split).
        while (getline(stream, auxSplit, ',')) {
            split.push_back(auxSplit);
        }

        almacenamiento->crearCanción(split[0], split[1], split[2], split[3], stoi(split[4]));
    }
    almacenamiento->mostrarListaCanciones();
}

int main() {
    //Es como python, debe tener instancia de la función antes de poder llamarla.
    lecturaCanciones();
    return 0;
}
