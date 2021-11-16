//============================================================================
// Name        : GrafosCarretera.cpp
// Author      : Juanfra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Grafo.h"
using namespace std;

int main() {
	Grafo g;

	ifstream flujo_lectura;
	flujo_lectura.open("datos.in");

	if (flujo_lectura.is_open()){
		g.CargarDatos(flujo_lectura);
		cout << "Entra";
		flujo_lectura.close();
	} else cout << "Error";

	g.verVertices();

	return 0;
}
