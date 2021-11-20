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

using namespace std;



int main(){

	//Grafo* g = new Grafo();
	//g -> prueba();
	//g -> verVertices();
	//delete g;

	Cola* cola = new Cola();

	cola -> insertarNodo("Badajoz");
	cola -> insertarNodo("Caceres");
	cola -> insertarNodo("Sevilla");

	cola -> mostrar();

	cola -> desencolar();
	cola -> desencolar(); 
	cola -> desencolar();

	cola -> mostrar();

	return 0;
}
