/*
 *  Declaración e implementación de una cola y una 
 *  clase nodo, contenido que almacena la cola.
 *  Se usa para almacenar los caminos solicitados por
 * 	el usuario.
 *
 *	@author Fernando Broncano Morgado
 *	@author Juan Francisco García Hinojosa
 *  
 *  @version 1.0
 */

#ifndef COLA_H_
#define COLA_H_

#include <string>
#include <iostream>

using namespace std;

class Cola{
	private:

	class Nodo{
		string palabra;  //Contenido del nodo
		Nodo* siguiente; //Puntero al siguiente nodo

		public:

		/*
		 * PRE: {}
 		 * POST: {Se formará un nodo con la cadena pasada por parámetro}
 		 * Complejidad: O(1)
 		 */
		Nodo(string palabra){
			this -> palabra = palabra;
			this -> siguiente = NULL;
		}

		/*
		 * PRE: {}
 		 * POST: {Devuelve la cadena contenida en un nodo}
 		 * Complejidad: O(1)
 		 */
		string getPalabra(){
			return this -> palabra;
		}

		/*
		 * PRE: {}
 		 * POST: {El puntero siguiente apuntará a otro nodo}
 		 * Complejidad: O(1)
 		 */
		void setSiguiente(Nodo* siguiente){
			this -> siguiente = siguiente;
		}

		/*
		 * PRE: {}
 		 * POST: {Devuelve el nodo apuntado por siguiente}
 		 * Complejidad: O(1)
 		 */
		Nodo* getSiguiente(){
			return this -> siguiente;
		}
	};

	Nodo* inicio; //Puntero al primer nodo de la cola.
	Nodo* fin;	  //Puntero al ultimo nodo de la cola.

	public:

	/*
	 * PRE: {}
	 * POST: {Inicializa la cola con el puntero inicio y fin apuntando a null}
	 * Complejidad: O(1)
	 */
	Cola(){
		inicio = NULL;
		fin = NULL;
	}

	/*
	 * PRE: {La cola debe estar correctamente inicializada}
	 * POST: {Inserta un nodo dentro de la cola}
	 * Complejidad: O(1)
	 */
	void insertarNodo(string palabra){
		Nodo* aux = new Nodo(palabra);

		if(this -> estaVacia()){
			this -> inicio = aux;
		} else{
			this -> fin -> setSiguiente(aux);
		}

		this -> fin = aux;
	}

	/*
	 * PRE: {La cola debe estar correctamente inicializada}
	 * POST: {-Devuelve true si la cola esta vacía
	 * 		  -Devuelve false en caso contrario}
	 * Complejidad: O(1)
	 */
	bool estaVacia(){
		return inicio == NULL && fin == NULL;
	}

	/*
	 * PRE: {La cola debe estar correctamente inicializada}
	 * POST: {Devuelve la cadena del primer nodo de la cola}
	 * Complejidad: O(1)
	 */
	string primero(){
		if(!estaVacia()){
			return inicio -> getPalabra();
		} else{
			return NULL;
		}
	}

	/*
	 * PRE: {La cola debe estar correctamente inicializada}
	 * POST: {Borra el primer nodo de la cola}
	 * Complejidad: O(1)
	 */
	void desencolar(){
		if(!estaVacia()){
			Nodo* aux = inicio;
			inicio = inicio -> getSiguiente();
			delete aux;

			if(inicio == NULL){
				fin = NULL;
			}
		}
	}

	/*
	 * PRE: {La cola debe estar correctamente inicializada}
	 * POST: {Muestra la cadena de cada nodo de la cola}
	 * Complejidad: O(n)
	 */
	void mostrar(){
		Nodo* aux = inicio;
		while(aux != NULL){
			cout << aux -> getPalabra() << endl;
			aux = aux -> getSiguiente();
		}
	}
};

#endif /* COLA_H_ */

