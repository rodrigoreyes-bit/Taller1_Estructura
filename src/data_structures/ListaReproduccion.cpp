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

void ListaReproduccion::pistaSiguiente(Configuracion* c, Almacenamiento* alm) {
    if (actual == nullptr) {
        return;
    }
    if (c->getRepeticion() == 1) { //si solo repite 1 cancion, la pista sig no cambia c:
        c->setPausa(false);
        return;
    }
    if (actual->siguiente != nullptr) { //aca, si no esta en repeticion de 1 cancion y todavia tiene canciones
        actual = actual->siguiente;     //en la cola, pone la pista siguiente
        c->setPausa(false);
        c->setIdCancionActual(actual->dato->getId());

    } else {
        if (c->getRepeticion() == 2) { //si esta en modo repetir todas (2) y se termino la lista
            if (c->getRandom()) { //en el caso de q este random, genera una nueva lista aleatoria
                generarListaAleatoria(alm, c);
            } else { //en el caso de q no este random, vuelve al inicio
                actual = inicio;
            }

        } else { //si no hay repeticion y se acaba la lista, se genera una nueva lista aleatoria c:
            generarListaAleatoria(alm, c);
        }

        if (actual != nullptr) {
            c->setPausa(false);
            c->setIdCancionActual(actual->dato->getId());
        }
    }
}

void ListaReproduccion::generarListaAleatoria(Almacenamiento *alm, Configuracion *c) {
     Nodo* aux = inicio; //esto es para limpiar la lista actual c:
    while (aux != nullptr) {
        Nodo* temp = aux;
        aux = aux->siguiente;
        delete temp;
    }

    inicio = nullptr;
    actual = nullptr;

    int cantCanciones = 0;

    Nodo* canciones = alm->getPrimerNodo();
    while (canciones != nullptr) {
        cantCanciones++;
        canciones = canciones->siguiente;
    }

    if (cantCanciones == 0) {
        return;
    }

    //esto lo tuve q buscar, hay q probarlo
    int* listaMezcla = new int[cantCanciones];
    canciones = alm->getPrimerNodo();
    for (int i = 0; i < cantCanciones; i++) {
        listaMezcla[i] = canciones->dato->getId();
        canciones = canciones->siguiente;
    }

    for (int i = cantCanciones - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tempId = listaMezcla[i];
        listaMezcla[i] = listaMezcla[j];
        listaMezcla[j] = tempId;
    }

    for (int i = 0; i < cantCanciones; i++) {
        Nodo* buscador = alm->getPrimerNodo();
        while(buscador != nullptr){
            if(buscador->dato->getId() == listaMezcla[i]){
                agregarAlFinal(buscador->dato);
                break;
            }
            buscador = buscador->siguiente;
        }
    }

    delete[] listaMezcla;

    if (inicio != nullptr) {
        actual = inicio;
        c->setIdCancionActual(actual->dato->getId());
        c->setPausa(false);
    }
}

void ListaReproduccion::pistaAnterior(Configuracion *c) {
    if (actual == nullptr) {
        return;
    }

    if (c->getRepeticion() == 1) {
        c->setPausa(false);
        return;
    }

    if (actual->anterior != nullptr) {
        actual = actual->anterior;
        c->setIdCancionActual(actual->dato->getId());
        c->setPausa(false);

    } else {
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
        nuevo->anterior = nullptr;
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
}

void ListaReproduccion::saltarACancion(int pos, Configuracion *c) {
    if (actual == nullptr || actual->siguiente == nullptr || pos <= 0) {
        return;
    }
    Nodo* cursor = actual->siguiente;
    int cont = 1;

    while (cursor != nullptr && cont < pos) {
        cursor = cursor->siguiente;
        cont++;
    }

    if (cursor != nullptr) {
        actual = cursor;
        actual->anterior = nullptr;
        c->setIdCancionActual(actual->dato->getId());
        c->setPausa(false);
    }
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
    if (actual == nullptr) {
        return;
    }
    if (modoRepe == 1) {
        return;
    }

    if (actual->siguiente == nullptr) {
        if (modoRepe == 2) {
            if (c->getRandom()) {
                //mezclarListaRepeticion(alm, c); //ARREGLAR ESTA FUNCIOOOOON
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