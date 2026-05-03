#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "../include/classes/Almacenamiento.hpp"
#include "../include/data_structures/ListaReproduccion.hpp"

using namespace std;

void lecturaCanciones(Almacenamiento* a) {
    ifstream archivo("music_source.txt");
    string linea;

    if (!archivo.is_open()) {
        cout << "No se encontro music_source.txt" << endl;
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
            //Se me olvido como hacer este catch dhsjhd
        }
    }
    archivo.close();
}
//LOS ARGUMENTOS DE ESTA FUNCIÓN SON TEMPORALES, lo hice asi porque una no he terminado la parte de la lista de reproducción,
//Hay que crear una instancia de lista de reproducción y asigarle el estado actual del reproductor, y en base a esa instancia
//sacar los argumentos de la función
void menuOpciones(string estado, string modo, string cancion, string artista, string album, int anio) {

    cout << estado << " (" << modo << "): " << cancion << endl;
    cout << "Artista: " << artista << endl;
    cout << "Album: " << album << " [" << anio << "]" << endl;
    cout << "Opciones:" << endl;
    cout << "  W - Reproducir/Pausar" << endl;
    cout << "  Q - Pista Anterior" << endl;
    cout << "  E - Pista Siguiente" << endl;
    cout << "  S - Activar/Desactivar modo aleatorio" << endl;
    cout << "  R - Repeticion (Desactivado/Repetir una/Repetir todas)" << endl;
    cout << "  A - Ver lista de reproduccion actual" << endl;
    cout << "  L - Listado de canciones" << endl;
    cout << "  X - Salir" << endl;
    cout << "Ingrese Opcion: ";
}

void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void pausaPlay() {

}


int main() {
    Almacenamiento* listaAlmacenamiento = new Almacenamiento();

    lecturaCanciones(listaAlmacenamiento);
    listaAlmacenamiento->mostrarListaCanciones();
    char opcion;
    bool salir = false;

    ListaReproduccion* lista = new ListaReproduccion(listaAlmacenamiento);

    // Por mientras no tenemos cfg !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string estadoActual = "Reproduciendo";
    string modoActual = "S-R1";
    string cancionActual = "Fire Dance :,v";
    string artistaActual = "Vivid BAD Squad";
    string albumActual = "Fire Dance (Single)";
    int anioActual = 2025;

    while (!salir) {
        clearScreen();

        menuOpciones(estadoActual, modoActual, cancionActual, artistaActual, albumActual, anioActual);

        cin >> opcion;
        //Pasa el input a mayusculas porsiaca
        opcion = toupper(opcion);

        switch (opcion) {

            case 'W':
            // pausa/play
            break;

            case 'Q':
            // anterior
            break;

            case 'E':
            // siguiente
            break;

            case 'S':
            // aleatorio
            break;

            case 'R':
            // ciclo de repetición
            break;

            case 'A': {
            string input;

            do {
                clearScreen();
                lista->mostrarListaReproduccion();

                cin >> input;

                if (input.size() > 1 && input[0] == 'S') {
                    int num = stoi(input.substr(1));
                    lista->saltarACancion(num);
                    break;
                }
            } while (input != "V");
                break;
            }

            case 'L':
                // catálogo completo
                break;

            case 'X':
                //LOGICA PARA GUARDAR ESTADOOOO
                salir = true;
                break;

            default:
                //HAY QUE HACER LA LOGICA POR SI SE CAE EL SISTEMA
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }

    delete listaAlmacenamiento;
    delete lista;
    return 0;
}



