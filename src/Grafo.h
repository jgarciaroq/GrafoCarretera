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

#define FICHERO_ENT "datos.in"
#define FICHERO_SAL "datos.out"

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
	float matrizCaminos[MAX][MAX]; 		//Matriz de caminos utilizadas en Floyd
	int numNodos;						//Numero de nodos insertados en el grafo
	int numArcos;						//Numero de vertices insertados en el grafo
	ofstream salidaDatos;
	
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

	Grafo(Grafo* other);

	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas e inicializadas}
	 * POST: {Abrimos un flujo de lectura del fichero "Datos.in" y cargamos las diferentes estructuras del Grafo a partir de los datos}
	 * Complejidad: O(n)
	 */
	void cargarDatos();

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void mostrarDatos(float matriz[MAX][MAX]);

	void inicializarMatriz(float matriz[MAX][MAX]);

	void insertarVertice(string vertice);

	bool insertarArco(string inicio, string fin, float distancia);

	void mostrarVertices();

	void borrar(string vertice);

	bool pertenece(string vertice, int &posicion);
	
	void floyd();

	void copiarMatriz(float matriz1[MAX][MAX], float matriz2[MAX][MAX]);

	void iniciarMatrizCaminos();

	void caminoFloyd(int posInicio, int posFin);

	void iniciarCaminos();

	Grafo* prim();

	void prueba();

	~Grafo();
};


#endif /* GRAFO_H_ */
