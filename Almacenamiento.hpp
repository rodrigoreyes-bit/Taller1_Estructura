#ifndef TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#define TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#include <string>
#include <vector>
using namespace std;

struct Canción {
    string id;
    string nombre;
    string artista;
    string album;
    int duracion;
    string ubicacion;
};

class Almacenamiento {
private:
    //vector que almacena las canciones del archivo en cmake
    //En el caso que el archivo music_source.txt no está presente, entonces no se puede cargar ninguna canción a la
    //aplicación, por lo que no se puede mantener el estado de reproducción en el caso que status.cfg lo posea.
    vector<Canción> listaCanciones;

public:
    Almacenamiento(); //Constructor
    vector<Canción> getListaCanciones();

    void crearCanción(string id, string nombre, string artista, string album, int duracion);
    void mostrarListaCanciones();
};


#endif //TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
