#include "../../include/data_structures/ListaReproduccion.hpp"
#include <iostream>
#include "../../include/classes/Configuracion.hpp"
using namespace std;

ListaReproduccion::ListaReproduccion() {
    this->inicio = nullptr;
    this->actual = nullptr;
}

Cancion *ListaReproduccion::getCancionActual() {
    if (actual == nullptr) {
        return nullptr;
    }
    return actual->dato;
}

void ListaReproduccion::cambiarEstadoReproduccion(Configuracion *c) {
    if (actual == nullptr) {
        return;
    }
    c->setPausa(!c->getPausa());
}

void ListaReproduccion::pistaSiguiente(Configuracion *c) {
    if (actual == nullptr) {
        return;
    }

    if (actual->siguiente != nullptr) {
        actual = actual->siguiente;
        c->setPausa(false);
        c->setIdCancionActual(actual->dato->getId());
    } else {
        if (c->getRepeticion() == 2) {
            actual = inicio;
            c->setPausa(false);
            c->setIdCancionActual(actual->dato->getId());
        } else {
            c->setPausa(true); // Termina la lista
        }
    }
}

void ListaReproduccion::pistaAnterior(Configuracion *c) {
    if (actual == nullptr) {
        return;
    }

    if (actual->anterior != nullptr) {
        actual = actual->anterior;
        c->setIdCancionActual(actual->dato->getId());
        c->setPausa(false);
    } else {
        // Si estamos en la primera y hay repetición, saltamos al final
        if (c->getRepeticion() == 2) {
            Nodo *aux = actual;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            actual = aux;
            c->setIdCancionActual(actual->dato->getId());
            c->setPausa(false);
        }
    }
}

void ListaReproduccion::agregarAlFinal(Cancion *cancion) {
    Nodo *nuevo = new Nodo(cancion);
    if (inicio == nullptr) {
        inicio = nuevo;
        actual = inicio;
    } else {
        Nodo *aux = inicio;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
}

void ListaReproduccion::mostrarListaReproduccion() {
    if (actual == nullptr) {
        cout << "Actual: Ninguna" << endl;
        cout << "Lista de reproduccion actual:" << endl;
        cout << "  Vacia" << endl;
        cout << "Opciones:" << endl;
        cout << "  V - Volver al menu principal" << endl;
        cout << "Ingrese Opcion: ";
        return;
    }

    // Cambiamos 'inicio' por 'actual' para que refleje el estado real
    cout << "Actual: " << actual->dato->getNombre() << " - " << actual->dato->getArtista() << endl;
    cout << "Lista de reproduccion actual:" << endl;

    Nodo *cursor = actual->siguiente;

    if (cursor == nullptr) {
        cout << "  Vacia" << endl;
    } else {
        int i = 1;
        while (cursor != nullptr) {
            cout << "  " << i << ". " << cursor->dato->getNombre() << " - " << cursor->dato->getArtista() << endl;
            cursor = cursor->siguiente;
            i++;
        }
    }
    cout << "Opciones:" << endl;
    if (actual->siguiente != nullptr) {
        cout << "  S<num> - Saltar a la cancion seleccionada" << endl;
    }
    cout << "  V - Volver al menu principal" << endl;
    cout << "Ingrese Opcion: ";
}

void ListaReproduccion::saltarACancion(int pos, Configuracion *c) {
    if (actual == nullptr || actual->siguiente == nullptr) {
        return;
    }

    Nodo *cursor = actual->siguiente;
    int i = 1;

    while (cursor != nullptr && i < pos) {
        cursor = cursor->siguiente;
        i++;
    }

    if (cursor == nullptr) return;

    actual = cursor;

    c->setIdCancionActual(actual->dato->getId());
    c->setPausa(false);
}

void ListaReproduccion::reproducirAltiro(Cancion *cancion, Configuracion *c) {
    Nodo *aux = inicio;
    while (aux != nullptr) {
        Nodo *temp = aux;
        aux = aux->siguiente;
        delete temp;
    }
    inicio = new Nodo(cancion);
    actual = inicio;
    c->setPausa(false);
    c->setIdCancionActual(actual->dato->getId());
}

void ListaReproduccion::repetirCanciones(int modoRepe, Configuracion *c, Almacenamiento *alm) {
    if (actual == nullptr) { return; }

    if (modoRepe == 1) { return; }

    if (actual->siguiente == nullptr) {
        if (modoRepe == 2) {
            if (c->getRandom()) {
                mezclarListaRepeticion(alm, c);
            } else {
                actual = inicio;
            }
            return;
        } else {
            actual = nullptr;
            return;
        }
    }
    actual = actual->siguiente;
}


void ListaReproduccion::mezclarListaRepeticion(Almacenamiento* alm, ListaReproduccion* lr, Configuracion *c) {
    int total = 0;
    Nodo *aux = lr->inicio;
    while (aux != nullptr) {
        total++;
        aux = aux->siguiente;
    }
    if (total == 0) { return; }

    int idRandom = (rand() % total) + 1;
    Cancion *elegida = alm->getCancionIndice(idRandom);

    if (elegida != nullptr) {
        agregarAlFinal(elegida);
        for (int i = 1; i <= total; i++) {
            if (i != idRandom) {
                Cancion *otra = alm->getCancionIndice(i);
                if (otra != nullptr) {
                    agregarAlFinal(otra);
                }
            }
        }
    }
    actual = inicio;
    c->setIdCancionActual(actual->dato->getId());
}
