
#include "../../include/data_structures/ListaReproduccion.hpp"
#include <iostream>
using namespace std;

ListaReproduccion::ListaReproduccion(Almacenamiento* lista) {
    this->inicio = nullptr;
    //VER ESTO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    this->estadoReproduccion = "";
    this->estadoAleatorio = "";
    this->estadoRepeticion = "";

    Nodo* cursor = lista->str;
    Nodo* ultimo = nullptr;

    while (cursor != nullptr) {
        Nodo* nuevo = new Nodo(cursor->dato); // comparte Cancion, pero no Nodo

        if (inicio == nullptr) {
            inicio = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }

        cursor = cursor->siguiente;
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
