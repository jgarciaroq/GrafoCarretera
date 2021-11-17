#include "CargarDatos.h"

CargarDatos::CargarDatos(Grafo g){
    this -> nombreFichero = "datos.in";
    this -> entradaDatos.open(nombreFichero);
}

bool CargarDatos::leerFichero(Grafo g){
    bool leido = false;

    if(this -> entradaDatos.is_open()){
        string linea;
        getline(entradaDatos, linea);
        int numNodos = stoi(linea);
        
        for(int i = 0; i < numNodos; i++){
            getline(entradaDatos, linea);
            g.insertarVertices(linea);
        }

        getline(entradaDatos, linea);
    }

    return leido;
}

CargarDatos::~CargarDatos(){
    this -> entradaDatos.close();
}