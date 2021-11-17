#include "CargarDatos.h"

CargarDatos::CargarDatos(){
    this -> nombreFichero = "../datos.in";
}

CargarDatos::CargarDatos(Grafo* g){
    this -> nombreFichero = "../datos.in";
    leerFichero(g);
}

bool CargarDatos::leerFichero(Grafo* g){
    bool leido = false;
    int numNodos, numAristas;
    string linea, ciudadInicio, ciudadFin;

    ifstream in;
    in.open("Datos.in", ios::in);

    if(in.is_open()){
        getline(in, linea, '\n');
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

        in.close();
        leido = true;
    } else{
        cout << "Error";
    }

    return leido;
}

CargarDatos::~CargarDatos(){
}