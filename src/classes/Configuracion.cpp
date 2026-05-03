
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

}


void Configuracion::cargarArchivoConfig() {
    std::ifstream arch("status.cfg");

    if (!arch.is_open()) {
        std::cout << "No se encontró archivo status.cfg" << std::endl;
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
            }else {
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
                this->insertarIdPendientes(id);
            }
        }

    }
}

void Configuracion::sobreescribirArchivoConfig() {
    std:: ofstream arch("status.cfg");
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


void Configuracion::insertarIdPendientes(int id) {
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
}


