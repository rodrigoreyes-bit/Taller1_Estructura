//
// Created by pc on 02-05-2026.
//

#ifndef TALLER1_ESTRUCTURA_CONFIGURACION_HPP
#define TALLER1_ESTRUCTURA_CONFIGURACION_HPP
#endif //TALLER1_ESTRUCTURA_CONFIGURACION_HPP

struct nodoID {
    int id;
    nodoId* sig;
};


class Configuracion {
private:
    int idCancionActual;
    bool estaPausado;
    bool modoAleatorio;
    int repeticion;
    nodoID* listaPendientes;


};