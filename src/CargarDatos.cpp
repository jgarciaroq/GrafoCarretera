#include "CargarDatos.h"

CargarDatos::CargarDatos(){
    this -> nombreFichero = "datos.in";
    this -> entradaDatos.open(nombreFichero);
}

CargarDatos::

CargarDatos::~CargarDatos(){
    this -> entradaDatos.close();
}