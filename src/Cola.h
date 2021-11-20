#ifndef COLA_H_
#define COLA_H_

#include <string>
#include <iostream>

using namespace std;

class Cola{
	private:

	class Nodo{
		string palabra;
		Nodo* siguiente;

		public:

		Nodo(string palabra){
			this -> palabra = palabra;
			this -> siguiente = NULL;
		}

		string getPalabra(){
			return this -> palabra;
		}

		void setSiguiente(Nodo* siguiente){
			this -> siguiente = siguiente;
		}

		Nodo* getSiguiente(){
			return this -> siguiente;
		}
	};

	Nodo* inicio;
	Nodo* fin;

	public:

	Cola(){
		inicio = NULL;
		fin = NULL;
	}

	void insertarNodo(string palabra){
		Nodo* aux = new Nodo(palabra);

		if(this -> estaVacia()){
			this -> inicio = aux;
		} else{
			this -> fin -> setSiguiente(aux);
		}

		this -> fin = aux;
	}

	bool estaVacia(){
		return inicio == NULL && fin == NULL;
	}

	string primero(){
		if(!estaVacia()){
			return inicio -> getPalabra();
		} else{
			return NULL;
		}
	}

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

	void mostrar(){
		Nodo* aux = inicio;
		while(aux != NULL){
			cout << aux -> getPalabra() << endl;
			aux = aux -> getSiguiente();
		}
	}

	~Cola(){
	}
};

#endif /* COLA_H_ */

