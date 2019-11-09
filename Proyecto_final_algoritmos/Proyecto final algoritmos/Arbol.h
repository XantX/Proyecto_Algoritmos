#pragma once
#include <iostream>
#include <functional>
#include "dirent.h"
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

	void Litar(string Dir) {//ruta
		DIR*directorio;
		struct dirent*elemto;
		string nombre;
		if (directorio=opendir(dir.c_str())) {
			while (elemto = readdir(directorio)) {
				nombre = elemto->d_name;
				if (nombre != "."&& nombre != "..")cout << nombre;
			}
		}
		closedir(directorio);
	} 
	//----------------------------------------------------------
	void rotarIzq(Nodo<T>*&nodo) {
		Nodo<T>*aux = nodo->der;
		nodo->der = aux->izq;
		aux->izq = nodo;
		nodo = aux;
	}
	void rotarDer(Nodo<T>*&nodo) {
		Nodo<T>*aux = nodo->izq;
		nodo->izq = aux->der;
		aux->der = nodo;
		nodo = aux;
	}
	//---------------------------------------------------------------------
	void _insertar(Nodo<T>*& nodo, T e) {

		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else if (e< nodo->elemento) {
			return _insertar(nodo->izq, e);
		}
		else if (e >= nodo->elemento) {
			return _insertar(nodo->der, e);
		}

	}

	//---------------------------------------------------------------------
	void _balanceo(Nodo<T>*nodo) {
		if (nodo == nullptr) {
			return;
		}
		int alturader = _AlturaDer(nodo);
		int alturaizq = _AlturaIzq(nodo);
		int fb = alturader - alturaizq;
		if (fb>1) {
			alturader = _AlturaDer(nodo->der);
			alturaizq = _AlturaIzq(nodo->der);
			if (alturaizq>alturader) {
				rotarDer(nodo->der);
			}
			rotarIzq(nodo);
		}
		if (fb<-1) {
			
			alturader = _AlturaDer(nodo->izq);
			alturaizq = _AlturaIzq(nodo->izq);
			if (alturaizq<alturader) {
				rotarIzq(nodo->izq);
			}
			rotarDer(nodo);
		}
		_balanceo(nodo->der);
		_balanceo(nodo->izq);
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