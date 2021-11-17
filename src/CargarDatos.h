#ifndef CARGARDATOS_H_
#define CARGARDATOS_H_

#include <fstream>
#include <ios>
#include "Grafo.h"

using namespace std;

class CargarDatos{

    string nombreFichero;
    ifstream entradaDatos;

public:
    bool leerFichero(Grafo* g);
    

public:
    CargarDatos();
    CargarDatos(Grafo* g);
    ~CargarDatos();
};

#endif /* CARGARDATOS_H_ */