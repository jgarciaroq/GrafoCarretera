#include "CargarDatos.h"

CargarDatos::CargarDatos(Grafo* g){
    this -> nombreFichero = "datos.in";
    this -> entradaDatos.open(nombreFichero);
}

bool CargarDatos::leerFichero(Grafo* g){
    bool leido = false;
    int numNodos, numAristas;
    string linea, ciudadInicio, ciudadFin;

    if(this -> entradaDatos.is_open()){
        
        //Leer numero de nodos.
        getline(entradaDatos, linea);
        numNodos = stoi(linea);
        
        //Leer numero de nodos e insertarlos.
        for(int i = 0; i < numNodos; i++){
            getline(entradaDatos, linea);
            g -> insertarVertices(linea);
        }

        //Leer numero de aristas.
        getline(entradaDatos, linea);
        numAristas = stoi(linea);

        //Leer las aristas e insertarlas en el grafo.
        for(int i = 0; i < numAristas; i++){
            getline(entradaDatos, ciudadInicio, ' ');
            getline(entradaDatos, ciudadFin, ' ');
            getline(entradaDatos, linea);

            g -> insertarArcos(ciudadInicio, ciudadFin, stof(linea));
        }
    }

    return leido;
}

CargarDatos::~CargarDatos(){
    this -> entradaDatos.close();
}