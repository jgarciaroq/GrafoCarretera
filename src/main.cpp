//============================================================================
// Name        : GrafosCarretera.cpp
// Author      : Juanfra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Grafo.h"
#include <iostream>

using namespace std;

int main(){

	Grafo* g = new Grafo();
	g -> prueba();
	//g -> verVertices();
	delete g;

	return 0;
}
