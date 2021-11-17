//============================================================================
// Name        : GrafosCarretera.cpp
// Author      : Juanfra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Grafo.h"
#include "CargarDatos.h"
#include <iostream>

using namespace std;

int main() {

	Grafo* g = new Grafo();
	CargarDatos* carga = new CargarDatos();
	carga->leerFichero(g);
	//delete carga;
	//g -> verVertices();

	delete carga;
	delete g;

	return 0;
}
