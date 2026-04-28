#include <iostream>
#include "Cancion.hpp"
using namespace std;

class Nodo {
    public:
        Cancion dato;
        Nodo* siguiente;

        Nodo(Cancion cancion);
};

