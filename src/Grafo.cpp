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
	for(int i = 0; i < MAX; i++){
		cjtoVertices[i] = "\0";
	}

	for(int i=0; i < MAX; i++){
		for(int j=0; j < MAX; j++){
			cjtoVertices[j]=" ";
			if (i==j){
				matrizAdyacencia[i][j]=0;
			}else{
				matrizAdyacencia[i][j]=INF;
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
		}
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
					matrizAdyacencia[j][i] = INF;
				} else{
					matrizAdyacencia[i][j] = 0;
					matrizAdyacencia[j][i] = 0;
				}
			}
			borrado = true;
		} else i++;
	}

	
}

void Grafo::verVertices (){
	cout << numNodos << endl;
	for (int i=0; i < numNodos; i++){
		cout << cjtoVertices[i] <<endl;
	}
}

void Grafo::insertarArcos(int numArcos, ifstream &flujo_lectura){
	
}