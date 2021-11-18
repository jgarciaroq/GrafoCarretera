/*
 * Grafo.h
 *
 *Indica el/los nombre/s del/los autor/es
 *  Juan Francisco Garcia Hinojosa
 *  Fernando Broncano
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define FICHERO_ENT "datos.in"
#define FICHERO_SAL "datos.out"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int MAX = 20;    //Constante de valor 20, es de utilidad ya que se indica que como máximo tedremos 20 nodos.
static const float INF = 9999.99;	//Constante infinito para inicializar la matriz

class Grafo {

	string cjtoVertices[MAX];    	//Conjunto de nodos que tendra nuestro grafo

	float matrizAdyacencia[MAX][MAX];  //Conjunto de aristas que tendra nuestro grafo

	int numNodos;					//Numero de nodos insertados en el grafo

	int numArcos;					//Numero de vertices insertados en el grafo

	//********************************************************************************
	//	De esta forma tienes lo imprescindible para un grafo; los vértices y las aristas.
	//	Deberás añadir más matrices, si lo consideras necesario para resolver el ejercicio.
	//	Son las matrices que resultan de aplicar los diferentes algoritmos que vayas necesitando.
	//*********************************************************************************************************

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
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas e inicializadas}
	 * POST: {Abrimos un flujo de lectura del fichero "Datos.in" y cargamos las diferentes estructuras del Grafo a partir de los datos}
	 * Complejidad: O(n)
	 */
	void cargarDatos();

	/**
	 * @brief 
	 * 
	 */
	void inicializarMatriz();

	/**
	 * @brief 
	 * 
	 * @param vertice 
	 */
	void insertarVertices(string vertice);

	/**
	 * @brief 
	 * 
	 * @param numArcos 
	 * @param flujo_lectura 
	 */
	bool insertarArcos(string inicio, string fin, float distancia);

	/**
	 * @brief 
	 * 
	 */
	void verVertices ();

	//********************************************************************************
	//	Deberás añadir más métodos necesarios para resolver el ejercicio.
	//	Documentarlos de forma correcta.
	//**********************************************************************************************************

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void mostrarDatos(float matriz[MAX][MAX]);

	/**
	 * @brief 
	 * 
	 * @param vertice 
	 */
	void borrar(string vertice);

	/**
	 * @brief 
	 * 
	 * @param vertice 
	 * @param posicion 
	 * @return true 
	 * @return false 
	 */
	bool pertenece(string vertice, int &posicion);
	

	//RecuperaCamino
};


#endif /* GRAFO_H_ */



