
#include "../../include/data_structures/ListaReproduccion.hpp"
#include <iostream>
#include "../../include/classes/Configuracion.hpp"
using namespace std;

ListaReproduccion::ListaReproduccion() {
    this->inicio = nullptr;
    this->actual = nullptr;

}

Cancion* ListaReproduccion::getCancionActual(){
    if (actual == nullptr) {
        return nullptr;
    }
    return actual->dato;
}

void ListaReproduccion::cambiarEstadoReproduccion(Configuracion* c) {
    if (actual == nullptr) {
        return;
    }
    c->setPausa(!c->getPausa());
}

void ListaReproduccion::pistaAnterior(Configuracion* c) {
    if (actual == nullptr || actual->anterior == nullptr) {
        return;
    }
    actual = actual->anterior;
    c->setIdCancionActual(actual->dato->getId());
    c->setPausa(false);

}

void ListaReproduccion::pistaSiguiente(Almacenamiento *alm, Configuracion* c) {
    if (actual == nullptr) {
        return;
    }
    if (actual->siguiente != nullptr) {
        actual = actual->siguiente;
        c->setPausa(false);
        c->setIdCancionActual(actual->dato->getId());

    } else {
        //se obtienen el total de canciones del almacenamientoo
        int total = 0;
        Nodo* aux = alm->getPrimerNodo();
        while (aux != nullptr) {
            total++;
            aux = aux->siguiente;
        }

        if (total == 0) return;
        //en el caso de q este en aleatorio se randomizan las canciones
        int indiceAleatorio = (rand() % total) + 1;
        Cancion* elegida = alm->getCancionIndice(indiceAleatorio);

        if (elegida != nullptr) {
            agregarAlFinal(elegida);
            actual = actual->siguiente;
            c->setPausa(false);
            c->setIdCancionActual(actual->dato->getId());
            //dps de la cancion, tambien se agregan las canciones que estaban de forma aleatoria a la cola
            for (int i = 1; i <= total; i++) {
                if (i != indiceAleatorio) {
                    Cancion* otra = alm->getCancionIndice(i);
                    if (otra != nullptr) {
                        agregarAlFinal(otra);
                    }
                }
            }
        }
    }

}

void ListaReproduccion::agregarAlFinal(Cancion* cancion) {
    Nodo* nuevo = new Nodo(cancion);
    if (inicio == nullptr) {
        inicio = nuevo;
        actual = inicio;
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
        cout << "Actual: Ninguna" << endl;
        cout << "Lista de reproduccion actual:" << endl;
        cout << "  Vacia" << endl;
        cout << "Opciones:" << endl;
        cout << "  V - Volver al menu principal" << endl;
        cout << "Ingrese Opcion: ";
        return;
    }
    cout << "Actual: " << inicio->dato->getNombre() << " - " << inicio->dato->getArtista() << endl;
    cout << "Lista de reproduccion actual:" << endl;

    Nodo* cursor = inicio->siguiente;

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
    if (inicio->siguiente != nullptr) {
        cout << "  S<num> - Saltar a la cancion seleccionada" << endl;
    }
    cout << "  V - Volver al menu principal" << endl;
    cout << "Ingrese Opcion: ";
}

void ListaReproduccion::saltarACancion(int pos, Configuracion* c) {
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
    actual = inicio;

    c->setIdCancionActual(actual->dato->getId());
    c->setPausa(false);

}

void ListaReproduccion::reproducirAltiro(Cancion* cancion, Configuracion* c) {
    Nodo* aux = inicio;
    while (aux != nullptr) {
        Nodo* temp = aux;
        aux = aux->siguiente;
        delete temp;
    }
    inicio = new Nodo(cancion);
    actual = inicio;
    c->setPausa(false);
    c->setIdCancionActual(actual->dato->getId());
}

void ListaReproduccion::repetirCanciones(int modoRepe, Configuracion* c, Almacenamiento* alm) {
    if (actual == nullptr){return;}

    if (modoRepe == 1) {return;}

    if (actual->siguiente == nullptr) {
        if (modoRepe == 2) {
            if (c->getRandom()) {
                mezclarListaRepeticion(alm,c);
            }else {
                actual = inicio;
            }
            return;
        }else {
            actual = nullptr;
            return;
        }
    }
    actual = actual->siguiente;
}


void ListaReproduccion::mezclarListaRepeticion(Almacenamiento* alm, Configuracion* c) {
    int total = 0;
    Nodo* aux = alm->getPrimerNodo();
    while (aux != nullptr) {
        total++;
        aux = aux->siguiente;
    }
    if (total == 0){return;}

    int idRandom = (rand() % total) + 1;
    Cancion* elegida = alm->getCancionIndice((idRandom));

    if (elegida != nullptr) {
        agregarAlFinal(elegida);
        for (int i = 1; i<= total; i++) {
            if (i != idRandom) {
                Cancion* otra = alm->getCancionIndice(i);
                if (otra != nullptr) {
                    agregarAlFinal(otra);
                }
            }
        }
    }
    actual = inicio;
    c->setIdCancionActual(actual->dato->getId());


}


