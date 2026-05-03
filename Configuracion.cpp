
#include "Configuracion.hpp"
#include <fstream>

Configuracion::Configuracion():

    idCancionActual(-1),
    estaPausado(true),
    modoAleatorio(false),
    repeticion(0),
    listaPendientes(nullptr){

}


void Configuracion::cargarArchivoConfig() {
    std::ifstream arch("config.cfg");

    if (!arch.is_open())
}
