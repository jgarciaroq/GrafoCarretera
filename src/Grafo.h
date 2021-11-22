/*
 *  Declaración del grafo y los métodos para cargar y volcar
 *	datos.
 *
 *	@author Fernando Broncano Morgado
 *	@author Juan Francisco García Hinojosa
 *  
 *  @version 1.0
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int MAX = 20;    		//Constante de valor 20, es de utilidad ya que se indica que como máximo tedremos 20 nodos.
static const float INF = 9999.99;	//Constante infinito para inicializar la matriz

class Grafo{

	string cjtoVertices[MAX];    		//Conjunto de nodos que tendra nuestro grafo
	float matrizAdyacencia[MAX][MAX];	//Conjunto de aristas que tendra nuestro grafo
	float matrizFloyd[MAX][MAX]; 		//Matriz de Floyd
	float matrizCaminos[MAX][MAX]; 	    //Matriz de caminos utilizadas en Floyd
	int numNodos;						//Numero de nodos insertados en el grafo
	int numArcos;						//Numero de vertices insertados en el grafo
	
public:
	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas}
	 * POST: {-Inicializamos el numero de ocupados 0
	 *  	  -Inicializamos el conjunto de vértices
	 *        -Inicializamos el conjunto de caminos (Matriz de Adyacencia) con el valor 9999 en todas sus casillas y 0 en la diagonal,
	 *        }
	 * Complejidad: O(n^2)
	 */
	Grafo();

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	bool pertenece(string vertice);
	
	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	int posicion(string vertice);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	void insertarVertice(string vertice);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	bool insertarArco(string inicio, string fin, float distancia);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	void borrar(string vertice);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	void copiarMatriz(float matriz1[MAX][MAX], float matriz2[MAX][MAX]);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	void floyd();
	
	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	string caminoFloyd(string inicio, string fin);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	string caminoFloyd(int posInicio, int posFin);

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void mostrarDatos(float matriz[MAX][MAX]);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	void prim(Grafo* mst);

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	float sumaDistancia();

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	float getDistancia(string inicio, string fin);
};


#endif /* GRAFO_H_ */
