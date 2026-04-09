#ifndef TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#define TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
#include <string>
#include <vector>
using namespace std;
//id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo

struct Canción {
    string id;
    string nombre;
    string artista;
    string album;
    float duracion;
    string ubicacion;
};

class Almacenamiento {
private:
    vector<Canción> listaCanciones;

public:
    Almacenamiento(); //Constructor
    vector<Canción> getListaCanciones();

    void crearCanción(string id, string nombre, string artista, string album, float duracion);
};


#endif //TALLER1_ESTRUCTURA_ALMACENAMIENTO_HPP
