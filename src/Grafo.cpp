/*
 * Grafo.cpp
 *
 *Indica el/los nombre/s del/los autor/es
 *  Juan Francisco Garcia Hinojosa
 *  Fernando Broncano
 */

#include "Grafo.h"
#include <iostream>
using namespace std;

//Constructor
Grafo::Grafo(){
	numNodos=0;
	numArcos=0;
	inicializarMatriz();
}

void Grafo::inicializarMatriz(){
	for(int i=0; i < MAX; i++){
		for(int j=0; j < MAX; j++){
			Cjtovertices[j]=" ";
			if (i==j){
				MatAdyacencia[i][j]=0;
			}else{
				MatAdyacencia[i][j]=INF;
			}
		}
	}
}

void Grafo::CargarDatos(ifstream &flujo_lectura){
	insertarVertices(numNodos, flujo_lectura);
	insertarArcos(numArcos, flujo_lectura);
}

void Grafo::insertarVertices(int numNodos, ifstream &flujo_lectura){

	string cadena;
	int size;
	getline(flujo_lectura,cadena);
	size=stoi(cadena);
	cout << size;
	int i=0;
	while(i<size){

		getline(flujo_lectura,cadena);
		Cjtovertices[i]=cadena;
		this -> numNodos++;
		i++;
	}
}


void Grafo::verVertices (){
	cout << numNodos << endl;
	for (int i=0; i < numNodos; i++){
		cout << Cjtovertices[i] <<endl;
	}
}

void Grafo::insertarArcos(int numArcos, ifstream &flujo_lectura){

}

