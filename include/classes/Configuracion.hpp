

#ifndef TALLER1_ESTRUCTURA_CONFIGURACION_HPP
#define TALLER1_ESTRUCTURA_CONFIGURACION_HPP
#endif //TALLER1_ESTRUCTURA_CONFIGURACION_HPP

struct nodoID {
    int id;
    nodoID* sig;
};


class Configuracion {
    private:
        int idCancionActual;
        bool estaPausado;
        bool modoAleatorio;
        int repeticion;
        nodoID* listaPendientes;


    public:
        Configuracion();
        void cargarArchivoConfig();
        void sobreescribirArchivoConfig();
        void insertarIdPendientes(int id, bool guardar = true);
        //setters
        void setPausa(bool estado);
        void setRandom(bool estadoR);
        void setRepeticion(int modoRep);
        void setIdCancionActual(int id);
        //getters
        int getIdCancionActual();
        int getRepeticion();
        bool getRandom();
        bool getPausa();
        nodoID* getListaPendientes();



};