#pragma once
#include <iostream>
#include <functional>

template<typename T>
class Nodo {
public:
	T elemento;
	Nodo*izq;
	Nodo*der;
};

template<typename T>
class AVL {

	
	Nodo<T>*raiz;
	CuentaBancaria *aux;
	
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
	void _insertarTamaño(Nodo<T>*& nodo, CuentaBancaria *e) {//arbol indexado por tamaño
		aux = nodo->elemento;
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else if (e->getpeso()< aux->getpeso()) {
			return _insertar(nodo->izq, e);
		}
		else if (e->getpeso >= aux->getpeso()) {
			return _insertar(nodo->der, e);
		}
	}

	void _insertarDia(Nodo<T>*& nodo, CuentaBancaria *e) {//arbol indexado por tamaño
		aux = nodo->elemento;
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else if (e->Fecha() < aux->Fecha()) {
			return _insertar(nodo->izq, e);
		}
		else if (e->getpeso >= aux->getpeso()) {
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
	AVL() {
		raiz = nullptr;
		aux = new CuentaBancaria();//para hacer las compáraciones
	}

	void Insertar(T e) {
		_insertarTamaño(raiz, e);
	}
	int Alturader() {
		return _AlturaDer(raiz);
	}
	int Alturaizq() {
		return _AlturaIzq(raiz);
	}

};