/*
 *  Implementación del grafo declarado en Grafo.h
 *
 *	@author Fernando Broncano Morgado
 *	@author Juan Francisco García Hinojosa
 *  
 *  @version 1.0
 */

#include <iostream>
#include "Grafo.h"

using namespace std;

//Constructor
Grafo::Grafo(){
	numNodos = 0;
	numArcos = 0;
	inicializarMatriz();
	cargarDatos();
}

void Grafo::cargarDatos(){
    int numNodos, numAristas, numCaminos;
    string linea, ciudadInicio, ciudadFin;

    ifstream entradaDatos;
	entradaDatos.open(FICHERO_ENT, ios::in);

    if(entradaDatos.is_open()){
        
        //Leer numero de nodos.
        getline(entradaDatos, linea, '\n');
        numNodos = stoi(linea);

        //Leer nombre de nodos e insertarlos.
        for(int i = 0; i < numNodos; i++){
            getline(entradaDatos, linea, '\n');
            this -> insertarVertices(linea);
        }

        //Leer salto de linea en linea 9
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de aristas.
        getline(entradaDatos, linea, '\n');
        numAristas = stoi(linea);

        //Leer las aristas e insertarlas en el grafo.
        for(int i = 0; i < numAristas; i++){
            getline(entradaDatos, ciudadInicio, ' ');
            getline(entradaDatos, ciudadFin, ' ');
            getline(entradaDatos, linea, '\n');
            if(this -> insertarArcos(ciudadInicio, ciudadFin, stof(linea))) cout << "Bien";
			else cout << "No inserta: " << ciudadInicio << ciudadFin << endl;
        }

		cout << numAristas;
		//Leer salto de linea en linea 9
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de aristas.
        getline(entradaDatos, linea, '\n');
        numCaminos = stoi(linea);

        entradaDatos.close();

		mostrarDatos(matrizAdyacencia);
    } else{
        cout << "Error: Fichero no encontrado.";
    }
}

bool Grafo::pertenece(string vertice, int &posicion){
	bool encontrado = false;
	int indice = 0;

	cout << vertice << numNodos << endl;
	
	while(indice < numNodos && !encontrado){
		
		if(this -> cjtoVertices[indice] == vertice){
			posicion = indice;
			cout << posicion;
			encontrado = true;
		} else indice++;
	}

	return encontrado;
}

void Grafo::inicializarMatriz(){
	
	for(int i = 0; i < MAX; i++){
		cjtoVertices[i] = "\0";
	}

	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			if(i==j){
				matrizAdyacencia[i][j] = 0;
			} else{
				matrizAdyacencia[i][j] = INF;
			}
		}
	}
}


void Grafo::insertarVertices(string vertice){
	int i = 0;
	bool insertado = false;

	while(!insertado && i < MAX){

		if(cjtoVertices[i] == "\0"){
			cjtoVertices[i] = vertice;
			numNodos++;
			insertado = true;
		} else i++;
	}
}

void Grafo::borrar(string vertice){
	bool borrado = false;
	int i = 0;

	while(!borrado && i < MAX){
		if(cjtoVertices[i] == vertice){
			cjtoVertices[i] = "\0";

			for(int j = 0; j < MAX; j++){	
				if(i != j){
					matrizAdyacencia[i][j] = INF;
				} else{
					matrizAdyacencia[i][j] = 0;
				}
			}

			borrado = true;
		} else i++;
	}
}

void Grafo::verVertices(){
	cout << numNodos << endl;
	for (int i=0; i < numNodos; i++){
		cout << cjtoVertices[i] << endl;
	}
}

bool Grafo::insertarArcos(string inicio, string fin, float distancia){

	bool insertado = false;
	int posInicio, posFin;

	if(inicio != fin){
		if(pertenece(inicio, posInicio) && pertenece(fin, posFin)){
			matrizAdyacencia[posInicio][posFin] = distancia;
			matrizAdyacencia[posFin][posInicio] = distancia;
			insertado = true;
		}
	}

	return insertado;
}



void Grafo::copiarMatrizAdyacencia(){
	for (int i=0; i < numNodos; i++){
		for (int j=0; i < numNodos; j++){
			matrizAdyacenciaFloyd[i][j]=matrizAdyacencia[i][j];
		}
	}
}

void Grafo::iniciarMatrizCaminos(){
	for(int i = 0; i < numNodos; i++){
		for(int j = 0; j < numNodos; j++){
			if(i==j){
				matrizCaminos[i][j] = 0;
			} else{
				matrizCaminos[i][j] = INF;
			}
		}
	}
}


void Grafo::Floyd (){
	copiarMatrizAdyacencia();
	iniciarMatrizCaminos();
	for (int k=0; k<numNodos; k++){
		for (int i=0; i<numNodos; i++){
			for(int j=0; j<numNodos; j++){
				if((matrizAdyacenciaFloyd[i][k]+matrizAdyacenciaFloyd[k][j]) < matrizAdyacenciaFloyd[i][j]){
					matrizAdyacenciaFloyd[i][j]=matrizAdyacenciaFloyd[i][k]+matrizAdyacenciaFloyd[k][j];
					matrizCaminos[i][j]=k;
				}
			}
		}
	}
}

void Grafo::caminoFloyd(int posOrigen, int posDestino, ofstream &salidaDatos){
	int k;
	k=matrizCaminos[posOrigen][posDestino];
	if(k!=0){
		caminoFloyd(posOrigen, k, salidaDatos);
		salidaDatos<<cjtoVertices[k]<<" ";
		caminoFloyd(k, posDestino, salidaDatos);
	}
}

//Muestra el valor de cada arista.
void Grafo::mostrarDatos(float matriz[MAX][MAX]){
	for(int i = 0; i < numNodos; i++){
		for(int j = 0; j < numNodos; j++){
			if(matriz[i][j] != INF) cout << matriz[i][j] << " ";
			else cout << "---- ";
		}
		cout << endl;
	}
}
