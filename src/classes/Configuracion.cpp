
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
    std::ifstream arch("config.cfg");

    if (!arch.is_open()) {
        std::cout << "No se encontro music_source.txt" << std::endl;
        return;
    }

    std::string variable;

    while (arch >> variable) {

    }


}
