#include <string>
#include "Cancion.hpp"
using namespace std;


class Nodo {
    public:
        Cancion* dato;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(Cancion* cancion);
};

