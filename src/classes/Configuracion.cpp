
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

    while (arch >> variable) {
        if (variable == "idCancionActual") {
            arch >> this->idCancionActual;
        }
        else if (variable == "estaPausado") {
            arch >> this->estaPausado;
        }
        else if (variable == "modoAleatorio") {
            arch >> this->modoAleatorio;
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


