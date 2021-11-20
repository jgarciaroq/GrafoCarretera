//============================================================================
// Name        : GrafosCarretera.cpp
// Author      : Juanfra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Grafo.h"
#include "Cola.h"
#include <iostream>

#define FICHERO_ENT "Datos2.in"
#define FICHERO_SAL "datos2.out"

using namespace std;

//Metood para cargar los datos en el grafo
//y guardar los caminos a resolver.
bool cargarDatos(Grafo* grafo, Cola* cola){
	bool cargado;
	int numNodos, numAristas, numCaminos;
    string linea, ciudadInicio, ciudadFin;
    ifstream entradaDatos;
	
	grafo = new Grafo();
	cola = new Cola();

	entradaDatos.open(FICHERO_ENT, ios::in);
	
    if(entradaDatos.is_open()){
        
        //Leer numero de nodos.
        getline(entradaDatos, linea, '\n');
        numNodos = stoi(linea);

        //Leer nombre de nodos e insertarlos.
        for(int i = 0; i < numNodos; i++){

			getline(entradaDatos, linea, '\n');
			
			//Eliminamos el retorno de carro.
			//Evitando problemas entre Linux y Windows.
			if(linea[linea.size() - 1] == '\r'){
				linea.erase(linea.size() - 1);
			}

            grafo -> insertarVertice(linea);
        }

        //Leer salto de linea entre los nodos y los arcos.
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de aristas.
        getline(entradaDatos, linea, '\n');
        numAristas = stoi(linea);

        //Leer las aristas e insertarlas en el grafo.
        for(int i = 0; i < numAristas; i++){
            getline(entradaDatos, ciudadInicio, ' ');
            getline(entradaDatos, ciudadFin, ' ');
            getline(entradaDatos, linea, '\n');
			
			
            if(!grafo -> insertarArco(ciudadInicio, ciudadFin, stof(linea))){
				cout << "No inserta: " << ciudadInicio << " -- " <<ciudadFin << "." << endl;
			} 
        }

		//Leer salto de linea entre los arcos y los caminos.
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de caminos a resolver.
        getline(entradaDatos, linea, '\n');
        numCaminos = stoi(linea);

		//Guardamos los datos de los caminos a resolver.
        for(int i = 0; i < numCaminos; i++){
			//Coger primera palabra de la linea.
        	getline(entradaDatos, ciudadInicio, ' ');
        	
			//Coger segunda palabra de la linea 
			getline(entradaDatos, ciudadFin, '\n');
			
			//Eliminamos el retorno de carro.
			//Evitando problemas entre Linux y Windows.
			if(ciudadFin[ciudadFin.size() - 1] == '\r'){
				ciudadFin.erase(ciudadFin.size() - 1);
			}

			//Insertamos los datos del fichero en una cola
			//para su procesamineto posterior.
			cola -> insertarNodo(ciudadInicio);
			cola -> insertarNodo(ciudadFin);
        }
		
        entradaDatos.close();
		cargado = true;	

    } else{
        cout << "Error: Fichero no encontrado.";
		cargado = false;
    }

	return cargado;
}


void ejecutar(Grafo* grafo, Cola* cola){
	
}

int main(){

	//ejecutar();
	//Grafo* g = new Grafo();
	//g -> prueba();
	//g -> verVertices();
	//delete g;

	/*Cola* cola = new Cola();

	cola -> insertarNodo("Badajoz");
	cola -> insertarNodo("Caceres");
	cola -> insertarNodo("Sevilla");

	cola -> mostrar();

	cola -> desencolar();
	cola -> desencolar(); 
	cola -> desencolar();

	cola -> mostrar(); */
////////////////////////////////////

	Grafo* grafo;
	Cola* cola;

	if(cargarDatos(grafo, cola)){
		ejecutar(grafo, cola);
	}

	return 0;
}
