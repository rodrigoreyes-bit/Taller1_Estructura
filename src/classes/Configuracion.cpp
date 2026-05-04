
#include "../../include/classes/Configuracion.hpp"
#include <fstream>
#include <iostream>
#include <string>

Configuracion::Configuracion():
    idCancionActual(-1),
    estaPausado(true),
    modoAleatorio(false),
    repeticion(0),
    listaPendientes(nullptr){
    cargarArchivoConfig();
}


void Configuracion::cargarArchivoConfig() {
    std::ifstream arch("data/status.cfg");

    if (!arch.is_open()) {
        std::cout << "No se encontro archivo status.cfg" << std::endl;
        return;
    }

    std::string variable;
    int val;

    while (arch >> variable) {
        if (variable == "idCancionActual") {
            arch >> this->idCancionActual;
        }
        else if (variable == "estaPausado") {
            arch >> val;
            if (val ==1) {
                this->estaPausado = true;
            }else if (val == 0) {
                this->estaPausado = false;
            }
        }
        else if (variable == "modoAleatorio") {
            arch >> val;
            if (val==1) {
                this->modoAleatorio = true;
            }else {
                this->modoAleatorio = false;
            }
        }
        else if (variable == "repeticion") {
            arch >> this->repeticion;
        }
        else if (variable == "cancionesPendientes") {
            int id;
            while (arch >> id) {
                this->insertarIdPendientes(id, false);
            }
        }

    }
}

void Configuracion::sobreescribirArchivoConfig() {
    std:: ofstream arch("data/status.cfg");
    if (!arch.is_open()) {
        std::cout << "No se encontró archivo status.cfg" << std::endl;
        return;
    }

    arch << "idCancionActual " << this->idCancionActual << "\n";
    arch << "estaPausado ";
    if (this->estaPausado == true) {
        arch << 1;
    }else {
        arch << 0;
    }
    arch << "\n";

    arch << "modoAleatorio ";
    if (this->modoAleatorio== true) {
        arch << 1;
    }else {
        arch << 0;
    }
    arch << "\n";

    arch << "repeticion " << this->repeticion << "\n";
    arch << "cancionesPendientes ";
    nodoID* aux = listaPendientes;
    while (aux != nullptr) {
        arch << " " << aux->id;
        aux = aux->sig;
    }
    arch << "\n";

    arch.close();
}


void Configuracion::insertarIdPendientes(int id, bool guardar) {
    nodoID* nuevo = new nodoID();
    nuevo->id = id;
    nuevo-> sig = nullptr;

    if (listaPendientes == nullptr) {
        listaPendientes = nuevo;
    }
    else {
        nodoID* aux = listaPendientes;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    if (guardar) {
        sobreescribirArchivoConfig();
    }


}

//setters
void Configuracion::setPausa(bool estado) {
    estaPausado = estado;
    sobreescribirArchivoConfig();
}

void Configuracion::setRandom(bool estadoR) {
    modoAleatorio = estadoR;
    sobreescribirArchivoConfig();
}

void Configuracion::setRepeticion(int modoRep) {
    repeticion = modoRep;
    sobreescribirArchivoConfig();
}

void Configuracion::setIdCancionActual(int id) {
    idCancionActual = id;
    sobreescribirArchivoConfig();
}

//getters

int Configuracion::getIdCancionActual() { return idCancionActual;}


int Configuracion::getRepeticion() { return repeticion;}


bool Configuracion::getRandom() { return modoAleatorio;}


bool Configuracion::getPausa() { return estaPausado;}


nodoID* Configuracion::getListaPendientes() { return listaPendientes;}





