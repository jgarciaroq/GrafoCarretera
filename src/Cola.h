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
 		 * POST: {}
 		 * Complejidad: O()
 		 */
		Nodo(string palabra){
			this -> palabra = palabra;
			this -> siguiente = NULL;
		}

		/*
		 * PRE: {}
 		 * POST: {}
 		 * Complejidad: O()
 		 */
		string getPalabra(){
			return this -> palabra;
		}

		/*
		 * PRE: {}
 		 * POST: {}
 		 * Complejidad: O()
 		 */
		void setSiguiente(Nodo* siguiente){
			this -> siguiente = siguiente;
		}

		/*
		 * PRE: {}
 		 * POST: {}
 		 * Complejidad: O()
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
	 * POST: {}
	 * Complejidad: O()
	 */
	Cola(){
		inicio = NULL;
		fin = NULL;
	}

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
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
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	bool estaVacia(){
		return inicio == NULL && fin == NULL;
	}

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
	 */
	string primero(){
		if(!estaVacia()){
			return inicio -> getPalabra();
		} else{
			return NULL;
		}
	}

	/*
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
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
	 * PRE: {}
	 * POST: {}
	 * Complejidad: O()
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

