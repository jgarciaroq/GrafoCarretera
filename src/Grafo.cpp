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
	//Iniciamos el grafo con 0 vertices y aristas.
	numNodos = 0;
	numArcos = 0;
	
	//Establecer a 0 el cjtoVertices.
	for(int i = 0; i < MAX; i++){
		cjtoVertices[i] = "\0";
	}

	//Iniciar matrizAdyacencia a INF y diagonal principal a 0.
	inicializarMatriz(matrizAdyacencia);

	//Cargar datos del fichero y realizar la petición de caminos.
	cargarDatos();
}

void Grafo::cargarDatos(){
    int numNodos, numAristas, numCaminos;
    int inicio, fin;
    string linea, ciudadInicio, ciudadFin;
    ifstream entradaDatos;

	entradaDatos.open(FICHERO_ENT, ios::in);

    if(entradaDatos.is_open()){
        
        //Leer numero de nodos.
        getline(entradaDatos, linea, '\n');
        numNodos = stoi(linea);

        //Leer nombre de nodos e insertarlos.
        for(int i = 0; i < numNodos; i++){

			getline(entradaDatos, linea, '\n');
			
			//Eliminamos el retorno de carro.
			//Evitando problemas entre Linux y Windows.
			if(linea[linea.size() - 1] == '\r'){
				linea.erase(linea.size() - 1);
			}

            this -> insertarVertices(linea);
        }

        //Leer salto de linea en linea 9.
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de aristas.
        getline(entradaDatos, linea, '\n');
        numAristas = stoi(linea);

        //Leer las aristas e insertarlas en el grafo.
        for(int i = 0; i < numAristas; i++){
            getline(entradaDatos, ciudadInicio, ' ');
            getline(entradaDatos, ciudadFin, ' ');
            getline(entradaDatos, linea, '\n');
			
			
            if(!this -> insertarArcos(ciudadInicio, ciudadFin, stof(linea))){
				cout << "No inserta: " << ciudadInicio << " -- " <<ciudadFin << "." << endl;
			} 
        }

		//Leer salto de linea en linea 9
        getline(entradaDatos, linea, '\n');
        
        //Leer numero de aristas.
        getline(entradaDatos, linea, '\n');
        numCaminos = stoi(linea);

		//Completar matriz de Floyd
        floyd();

		//Mostrar matriz de Floyd.
        //mostrarDatos(matrizFloyd);

        for(int i = 0; i < numCaminos; i++){
			//Coger primera palabra de la linea.
        	getline(entradaDatos, ciudadInicio, ' ');
        	
			//Coger segunda palabra de la linea 
			getline(entradaDatos, ciudadFin, '\n');
			
			//Eliminamos el retorno de carro.
			//Evitando problemas entre Linux y Windows.
			if(ciudadFin[ciudadFin.size() - 1] == '\r'){
				ciudadFin.erase(ciudadFin.size() - 1);
			}

			//Encontrar la posicion de las ciudades en el conjunto de vertices.
        	pertenece(ciudadInicio, inicio);
        	pertenece(ciudadFin, fin);

			//Buscar el camino desde el inicio al fin.
        	caminoFloyd(inicio, fin);

			//Mostramos la distancia.
        	cout << " " << matrizFloyd[inicio][fin] << endl;

        }

        entradaDatos.close();

    } else{
        cout << "Error: Fichero no encontrado.";
    }

}

void Grafo::prueba(){
	mostrarDatos(matrizCaminos);
	cout << "-------------------------" << endl;
	mostrarDatos(matrizFloyd);
	cout << "-------------------------" << endl;
	floyd();
	mostrarDatos(matrizCaminos);
	cout << "-------------------------" << endl;
	mostrarDatos(matrizFloyd);
	cout << "-------------------------" << endl;
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

void Grafo::mostrarVertices(){
	cout << numNodos << endl;
	for (int i=0; i < numNodos; i++){
		cout << cjtoVertices[i] << "   " << endl;
	}
}

bool Grafo::insertarArcos(string inicio, string fin, float distancia){

	bool insertado = false;
	int posInicio, posFin;

	if(inicio != fin){
		if(pertenece(inicio, posInicio) && pertenece(fin, posFin)){
			matrizAdyacencia[posInicio][posFin] = distancia;
			matrizAdyacencia[posFin][posInicio] = distancia;
			insertado = true;
		}
	}

	return insertado;
}

void Grafo::copiarMatriz(float matriz1[MAX][MAX], float matriz2[MAX][MAX]){
	for(int i = 0; i < numNodos; i++)
		for(int j = 0; j < numNodos; j++)
			matriz2[i][j] = matriz1[i][j];
}

void Grafo::floyd(){
	float distActual, distMinima;

	//Iniciar MatrizFloyd con los datos de la de adyacencia.
	copiarMatriz(matrizAdyacencia, matrizFloyd);

	//Iniciar la matriz de caminos a infinito.
	for(int i = 0; i < numNodos; i++){
		for(int j = 0; j < numNodos; j++){
			if(matrizAdyacencia[i][j] != INF){
				matrizCaminos[i][j] = j;
			} else{
				matrizCaminos[i][j] = INF;
			}
		}
	}

	//Realizacion del algortimo de floyd.
	for(int k = 0; k < numNodos; k++){
		for(int i = 0; i < numNodos; i++){
			for(int j = 0; j < numNodos; j++){
				distActual = matrizFloyd[i][k] + matrizFloyd[k][j];
				distMinima = matrizFloyd[i][j];  
				
				if(distActual < distMinima){
					matrizFloyd[i][j] = distActual;
					matrizCaminos[i][j] = k;
				}
			}
		}
	}
}

void Grafo::caminoFloyd(int posInicio, int posFin){
	int intermediario = matrizCaminos[posInicio][posFin];

	if(posInicio != posFin){
		cout << cjtoVertices[posInicio] << " ";
		caminoFloyd(intermediario, posFin);
	} else{
		cout << cjtoVertices[posFin];
	}
}

//Muestra el valor de cada arista.
void Grafo::mostrarDatos(float matriz[MAX][MAX]){
	for(int i = 0; i < numNodos; i++){
		for(int j = 0; j < numNodos; j++){	
			if(matriz[i][j] != INF){
				cout << matriz[i][j] << " ";	
			} else{
				cout << "-- ";
			}
		}
		cout << endl;
	}
}
