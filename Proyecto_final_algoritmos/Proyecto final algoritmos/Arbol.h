#pragma once
#include <iostream>
#include <functional>
using namespace std;
template<typename T>
class Nodo {
public:
	T elemento;
	Nodo*izq;
	Nodo*der;
};

template<typename T>
class AVL {

	typedef function<int(T, T)> Comp;

	Nodo<T>*raiz;
	void(*procesar)(T);//funcion como puntero
	Comp comparar;

	//---------------------------------------------------------------------
	void _insertar(Nodo<T>*& nodo, T e) {

		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			int alturader = Alturader();
			int alturaizq = Alturaizq();
			if (alturader - alturaizq>1) {
				cout << "esta desbalanceado a la derecha en:" << e << endl;
			}
			if (alturader - alturaizq < -1) {
				cout << "esta desbalanceado a la izquierda en:" << e << endl;
			}

		}
		else if (e< nodo->elemento) {
			return _insertar(nodo->izq, e);
		}
		else if (e >= nodo->elemento) {
			return _insertar(nodo->der, e);
		}
	}
	//---------------------------------------------------------------------
	void rotacion(Nodo<T>*nodo) {

	}
	//------------------------------------------------------------------------
	int _AlturaIzq(Nodo<T>*nodo) {
		if (nodo == nullptr) {
			return 0;
		}
		return _AlturaIzq(nodo->izq) + 1;
	}

	int _AlturaDer(Nodo<T>*nodo) {
		if (nodo == nullptr) {
			return 0;
		}
		return _AlturaDer(nodo->der) + 1;
	}
	//---------------------------------------------------------------------
public:
	AVL() {}
	AVL(void(*nuevoProcesar)(T)) {
		this->procesar = nuevoProcesar;
		this->comparar = [](T a, T b)-> int {return a - b; };
		raiz = nullptr;
	}

	void Insertar(T e) {
		_insertar(raiz, e);
	}
	int Alturader() {
		return _AlturaDer(raiz);
	}
	int Alturaizq() {
		return _AlturaIzq(raiz);
	}

};