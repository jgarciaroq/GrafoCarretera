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
	//Iniciamos el grafo con 0 vertices y 0 aristas.
	numNodos = 0;
	numArcos = 0;
	
	//Establecer a 0 el cjtoVertices.
	for(int i = 0; i < MAX; i++){
		cjtoVertices[i] = "\0";
	}

	//Iniciar matrizAdyacencia a INF y diagonal principal a 0.
	for(int i = 0; i < MAX; i++){
<<<<<<< HEAD
		cjtoVertices[i] = "\0";
	}

	//Iniciar matrizAdyacencia a INF y diagonal principal a 0.
	inicializarMatriz(matrizAdyacencia);
}

void Grafo::cargarDatos(){
    int numNodos, numAristas, numCaminos;
    int inicio, fin;
    string linea, ciudadInicio, ciudadFin;
    ifstream entradaDatos;
	Grafo* mst;
	

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

            this -> insertarVertice(linea);
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
			
			
            if(!this -> insertarArco(ciudadInicio, ciudadFin, stof(linea))){
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

        mostrarDatos(matrizFloyd);
        mostrarDatos(matrizCaminos);
        for (int i = 0; i < numCaminos; i++){
        	int suma=0;

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
        	salidaDatos << " " << matrizFloyd[inicio][fin] << endl;
        }

		mst = prim();
		mst -> mostrarDatos(mst -> matrizAdyacencia);

        entradaDatos.close();
		salidaDatos.close();

    }
    }else{
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
=======
		for(int j = 0; j < MAX; j++){
			if(i==j){
				matrizAdyacencia[i][j] = 0;
			} else{
				matrizAdyacencia[i][j] = INF;
			}
		}
	}
>>>>>>> refs/remotes/origin/master
}

bool Grafo::pertenece(string vertice){
	bool encontrado = false;
	int indice = 0;
	
	while(indice < numNodos && !encontrado){
		if(cjtoVertices[indice] == vertice){
			encontrado = true;
		} else indice++;
	}

	return encontrado;
}

int Grafo::posicion(string vertice){
	bool encontrado = false;
	int indice = 0;
	
	while(indice < numNodos && !encontrado){
		if(cjtoVertices[indice] == vertice){
			encontrado = true;
		} else indice++;
	}

	return indice;
}

void Grafo::insertarVertice(string vertice){
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

bool Grafo::insertarArco(string inicio, string fin, float distancia){
	bool insertado = false;
	int posInicio, posFin;

	if(inicio != fin){
		if(pertenece(inicio) && pertenece(fin)){
			posInicio = posicion(inicio);
			posFin = posicion(fin);

			matrizAdyacencia[posInicio][posFin] = distancia;
			matrizAdyacencia[posFin][posInicio] = distancia;

			insertado = true;
		}
	}

	return insertado;
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

void Grafo::floyd(){
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
				if(matrizFloyd[i][k] + matrizFloyd[k][j] < matrizFloyd[i][j]){
					matrizFloyd[i][j] = matrizFloyd[i][k] + matrizFloyd[k][j];
					matrizCaminos[i][j] = matrizCaminos[i][k];
				}
			}
		}
	}
}

string Grafo::caminoFloyd(string inicio, string fin){
	return caminoFloyd(posicion(inicio), posicion(fin));
}

string Grafo::caminoFloyd(int posInicio, int posFin){
	int intermediario = matrizCaminos[posInicio][posFin];

	if(posInicio != posFin){
		return cjtoVertices[posInicio] + " " + caminoFloyd(intermediario, posFin);
	} else{
		return cjtoVertices[posFin];
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

void Grafo::copiarMatriz(float matriz1[MAX][MAX], float matriz2[MAX][MAX]){
	for(int i = 0; i < numNodos; i++)
		for(int j = 0; j < numNodos; j++)
			matriz2[i][j] = matriz1[i][j];
}


void Grafo::prim(Grafo* mst){
	int nodoInicio, nodoFin;
	float minimo;

    //Insertamos el primer vertice.
	mst -> insertarVertice(this -> cjtoVertices[mst -> numNodos]);
	
	while(mst -> numNodos < this -> numNodos){
		
		for(int i = 0; i < this -> numNodos; i++){
			for(int j = 0; j < this -> numNodos; j++){
				if(this -> matrizAdyacencia[i][j] != INF && i != j){
					if(mst -> pertenece(this -> cjtoVertices[i]) && 
					   !mst -> pertenece(this -> cjtoVertices[j])){
						nodoInicio = i;
						nodoFin = j;
						minimo = this -> matrizAdyacencia[i][j];
					}
				}
			}
		}

		for(int i = 0; i < this -> numNodos; i++){
			for(int j = 0; j < this -> numNodos; j++){
				if(this -> matrizAdyacencia[i][j] != INF && i != j){
					if(mst -> pertenece(this -> cjtoVertices[i]) && 
					   !mst -> pertenece(this -> cjtoVertices[j])){
						if(this -> matrizAdyacencia[i][j] < minimo){
							nodoInicio = i;
							nodoFin = j;
							minimo = this -> matrizAdyacencia[i][j];
						}
					}
				}
			}
		}

		mst -> insertarVertice(this -> cjtoVertices[nodoFin]);
		mst -> insertarArco(this -> cjtoVertices[nodoInicio], this -> cjtoVertices[nodoFin], minimo);
	}
}

float Grafo::sumaDistancia(){
	float suma = 0;
	
	for(int i = 0; i < numNodos; i++)
		for(int j = i; j < numNodos; j++)
			if(matrizAdyacencia[i][j] != INF)
				suma += matrizAdyacencia[i][j];
	
	return suma;
}

<<<<<<< HEAD
Grafo::~Grafo(){
	if(salidaDatos.is_open()){
		salidaDatos.close();
	}
}
=======
float Grafo::getDistancia(string inicio, string fin){
	return matrizFloyd[posicion(inicio)][posicion(fin)];
}
>>>>>>> refs/remotes/origin/master
