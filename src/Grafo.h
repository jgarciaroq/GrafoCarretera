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
	
	/*
	 * PRE: {-La matrizCaminos debe estar correctamente inicializada y cargada
	 * 		 -Los parámetros de entrada deben tener un valor válido dentro del cjtoVertices}
	 * POST: {Muestra el camino desde la ciudad de inicio hasta la ciudad de destino ambos inclusive}
	 * Complejidad: O(n)
	 */
	string caminoFloyd(int posInicio, int posFin);

public:
	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas}
	 * POST: {-Inicializamos el numero de ocupados 0
	 *  	  -Inicializamos el conjunto de vértices
	 *        -Inicializamos el conjunto de caminos (Matriz de Adyacencia) con el valor 9999 en todas sus casillas y 0 en la diagonal
	 *        }
	 * Complejidad: O(n^2)
	 */
	Grafo();

	/*
	 * PRE: {El cjtoVertices debe estar correctamente inicializado}
	 * POST: {- Devuelve true si el vértice pasado por parámetro existe en el cjtoVertices
	 * 		  - Devuelve false si el vértice pasado por parámetro no existe dentro del cjtoVertices}
	 * Complejidad: O(n)
	 */
	bool pertenece(string vertice);
	
	/*
	 * PRE: {El vértice debe de existir dentro del cjtoVertices}
	 * POST: {Devuelve la posición que tiene ese vértice dentro del cjtoVertices}
	 * Complejidad: O(n)
	 */
	int posicion(string vertice);

	/*
	 * PRE: {El cjtoVertices debe estar correctamente inicializado}
	 * POST: {Inserta dentro de cjtoVertices un vértice pasado por parámetro}
	 * Complejidad: O(n)
	 */
	void insertarVertice(string vertice);

	/*
	 * PRE: {Los vértices deben existir dentro del cjtoVertices}
	 * POST: {Inserta un arco entre la ciudad de inicio y la ciudad de fin}
	 * Complejidad: O(n)
	 */
	bool insertarArco(string inicio, string fin, float distancia);

	/*
	 * PRE: {El vértice debe existir dentro del cjtoVertices}
	 * POST: {Borra un vértice del cjtoVertices y cambia la matrizAdyacencia poniendo que no existen caminos para ese vértice}
	 * Complejidad: O(n)
	 */
	void borrar(string vertice);

	/*
	 * PRE: {Ambas matrices deben estar correctamente inicializadas}
	 * POST: {Copia el contenido de la matriz1 en la matriz2}
	 * Complejidad: O(n^2)
	 */
	void copiarMatriz(float matriz1[MAX][MAX], float matriz2[MAX][MAX]);

	/*
	 * PRE: {La matrizAdyacencia debe estar correctamente definida, inicializada y cargada}
	 * POST: {-Inicializa MatrizFloyd con los datos de la matrizAdyacencia
	 * 		  -Inicializa la matriz de caminos a INF
	 * 		  -Se busca el camino mínimo entre todos los pares de vértices}
	 * Complejidad: O(n^3)
	 */
	void floyd();
	
	/*
	 * PRE: {-Los parámetros de entrada deben existir dentro del cjtoVertices}
	 * POST: {Devuelve lo que devuelva el método caminoFloyd}
	 * Complejidad: O(n)
	 */
	string caminoFloyd(string inicio, string fin);

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada}
	 * Complejidad: O(n^2)
	 */
	void mostrarDatos(float matriz[MAX][MAX]);

	/*
	 * PRE: {mst debe estar correctamente inicializado}
	 * POST: {-Insertamos el primer vértice del grafo cjtoVertices en mst cjtoVertices
	 * 		  -Se calcula el camino mínimo abarcando la mayor cantidad de vértices sin formar un ciclo}
	 * Complejidad: O(n^3) con n = numNodos 
	 */
	void prim(Grafo* mst);

	/*
	 * PRE: {matrizAdyacencia debe estar correctamente definida, cargada e inicializada}
	 * POST: {Devuelve la suma de la matriz triangular superior}
	 * Complejidad: O(n^2)
	 */
	float sumaDistancia();

	/*
	 * PRE: {matrizFloyd debe estar correctamente definida, cargada e inicializada}
	 * POST: {Devuelve la distancia entre una ciudad origen y una ciudad destino}
	 * Complejidad: O(n)
	 */
	float getDistancia(string inicio, string fin);
};


#endif /* GRAFO_H_ */
