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
	
	for(int i = 0; i < MAX; i++){
		cjtoVertices[i] = "\0";
	}

	inicializarMatriz(matrizAdyacencia);
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
            getline(entradaDatos, linea, ' ');
            this -> insertarVertices(linea);
			getline(entradaDatos, linea, '\n');
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
			
			
            if(this -> insertarArcos(ciudadInicio, ciudadFin, stof(linea))) cout << "Bien" << endl;
			else cout << "No inserta: " << ciudadInicio << "----" <<ciudadFin << "." << endl;
        }

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

void Grafo::prueba(){
	Floyd();
	mostrarDatos(matrizCaminos);
	mostrarDatos(matrizFloyd);
}

bool Grafo::pertenece(string vertice, int &posicion){
	bool encontrado = false;
	int indice = 0;
	
	while(indice < numNodos && !encontrado){
		if(cjtoVertices[indice] == vertice){
			posicion = indice;
			encontrado = true;
		} else indice++;
	}

	return encontrado;
}

void Grafo::inicializarMatriz(float matriz[MAX][MAX]){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			if(i==j){
				matriz[i][j] = 0;
			} else{
				matriz[i][j] = INF;
			}
		}
	}
}


void Grafo::insertarVertices(string vertice){
	int i = 0;
	bool insertado = false;

	while(!insertado && i < MAX){

		if(cjtoVertices[i] == "\0"){
			cjtoVertices[i] = string(vertice);
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
		cout << cjtoVertices[i] << "   " << endl;
	}
}

bool Grafo::insertarArcos(string inicio, string fin, float distancia){

	bool insertado = false;
	int posInicio, posFin;

	if(inicio != fin){
		if(pertenece( inicio, posInicio) && pertenece(fin, posFin)){
			matrizAdyacencia[posInicio][posFin] = distancia;
			matrizAdyacencia[posFin][posInicio] = distancia;
			insertado = true;
		}
	}

	return insertado;
}



void Grafo::copiarMatrizAdyacencia(){
	for(int i=0; i < numNodos; i++){
		for(int j=0; i < numNodos; j++){
			matrizFloyd[i][j] = matrizAdyacencia[i][j];
		}
	}
}

void Grafo::Floyd(){
	copiarMatrizAdyacencia();
	inicializarMatriz(matrizCaminos);

	for (int k=0; k<numNodos; k++){
		for (int i=0; i<numNodos; i++){
			for(int j=0; j<numNodos; j++){
				if((matrizFloyd[i][k]+matrizFloyd[k][j]) < matrizFloyd[i][j]){
					matrizFloyd[i][j]=matrizFloyd[i][k]+matrizFloyd[k][j];
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
