
#include "../../include/data_structures/ListaReproduccion.hpp"
#include <iostream>
using namespace std;

ListaReproduccion::ListaReproduccion() {
    this->inicio = nullptr;
    this->estadoReproduccion = "Detenido";
    this->estadoAleatorio = "Desactivado";
    this->estadoRepeticion = "Desactivado";
}

void ListaReproduccion::agregarAlFinal(Cancion* cancion) {
    Nodo* nuevo = new Nodo(cancion);
    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
}

void ListaReproduccion::mostrarListaReproduccion() {
    if (inicio == nullptr) {
        cout << "No hay canciones disponibles." << endl;
        return;
    }
    //acá falta agregar lo de (S-R1) !!!!!!!!!!!!!!!!!!!!!!!! -> Actual (S-R1):
    cout << "Actual: " << inicio->dato->getNombre() << " - " << inicio->dato->getArtista()<< endl;

    cout << "Lista de reproduccion actual:" << endl;
    Nodo* cursor = inicio->siguiente;

    if (cursor == nullptr) {
        cout << "Vacia" << endl;
    } else {
        int i = 1;
        while (cursor != nullptr) {
            cout << i << ". " << cursor->dato->getNombre() << " - " << cursor->dato->getArtista() << endl;
            cursor = cursor->siguiente;
            i++;
        }
    }

    cout << "Opciones:" << endl;
    if (inicio->siguiente != nullptr) {
        cout << "S<num> - Saltar a la cancion seleccionada" << endl;
    }
    cout << "V - Volver al menu principal" << endl;
}

void ListaReproduccion::saltarACancion(int pos) {
    if (inicio == nullptr || inicio->siguiente == nullptr) {
        return;
    }

    Nodo* cursor = inicio->siguiente;
    int i = 1;

    while (cursor != nullptr && i < pos) {
        cursor = cursor->siguiente;
        i++;
    }

    if (cursor == nullptr) return;

    Nodo* temp = inicio;

    while (temp != cursor) {
        Nodo* eliminar = temp;
        temp = temp->siguiente;
        delete eliminar;
    }

    inicio = cursor;
    inicio->anterior = nullptr;
}
