#ifndef CARGARDATOS_H_
#define CARGARDATOS_H_

#include <fstream>
#include "Grafo.h"

using namespace std;

class CargarDatos{

    ifstream entradaDatos;
    string nombreFichero;
    bool leerFichero(Grafo g);
    

public:
    CargarDatos(Grafo g);
    
    


};

#endif /* CARGARDATOS_H_ */