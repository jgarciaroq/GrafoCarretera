#include "CargarDatos.h"

CargarDatos::CargarDatos(Grafo* g){
    this -> nombreFichero = "../datos.in";
    leerFichero(g);
}

bool CargarDatos::leerFichero(Grafo* g){
    bool leido = false;
    int numNodos, numAristas;
    string linea, ciudadInicio, ciudadFin;

    entradaDatos.open(nombreFichero);
    cout << "----------";

    if(entradaDatos.is_open()){
        getline(entradaDatos, linea);
        cout << linea;

        /*
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
        }*/

        entradaDatos.close();
        leido = true;
    } else{
        cout << "Error";
    }

    return leido;
}

CargarDatos::~CargarDatos(){
}