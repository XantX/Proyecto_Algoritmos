#pragma once
#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class Nodo {
public:
	T *elemento;
	Nodo*izq;
	Nodo*der;
	
};

template<typename T>
class AVL {


	Nodo<T>*raiz;
	CuentaBancaria *aux;
	std::vector<CuentaBancaria>arrcuentas;
	int comparar(int uno, int dos) {
		return uno - dos;
	}
	//---------------------------------------------------------
	void _buscar(Nodo<T>*nodo, std::string LetraIni) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			int arbolElemt = int(aux->getnombre().front());
			int elemtbuscado = int(LetraIni);
			int result=comparar(arbolElemt, elemtbuscado);
			if (result==0) {
				arrcuentas.push_back(aux);
				result = -1;
			}
				if (result<0) {
					_buscar(nodo->der, LetraIni);
				}
				else {
					_buscar(nodo->izq, LetraIni);
				}
			
		}
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
	void _insertarTamaño(Nodo<T>*& nodo, CuentaBancaria *e) {//arbol indexado por tamaño
		
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else {
			aux = nodo->elemento;
			if (e->getpeso() < aux->getpeso()) {
				return _insertarTamaño(nodo->izq, e);
			}
			else if (e->getpeso() >= aux->getpeso()) {
				return _insertarTamaño(nodo->der, e);
			}
		}
	}
	void _insertarFecha(Nodo<T>*& nodo, CuentaBancaria *e) {//arbol indexado por fecha
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else {
			aux = nodo->elemento;
			if (e->Fecha() < aux->Fecha()) {
				return _insertarFecha(nodo->izq, e);
			}
			else if (e->Fecha() >= aux->Fecha()) {
				return _insertarFecha(nodo->der, e);
			}
		}
	}

	void _insertarInicioLetra(Nodo<T>*& nodo, CuentaBancaria *e) {//arbol indexado por letra inicial
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_balanceo(nodo);
		}
		else {
			aux = nodo->elemento;
			int LetraEntrante = int(e->getnombre().at(0));
			int letradelArbol = int(aux->getnombre().at(0));
			if (LetraEntrante < letradelArbol) {
				return _insertarInicioLetra(nodo->izq, e);
			}
			else if (LetraEntrante >= letradelArbol) {
				return _insertarInicioLetra(nodo->der, e);
			}
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

	void Insertar(T *e, int caso) {
		switch (caso)
		{
		case 1:
			_insertarTamaño(raiz, e);
			break;
		case 2:
			_insertarFecha(raiz, e);
			break;
		case 3:
			_insertarInicioLetra(raiz, e);
			break;
		}
	}
	int Alturader() {
		return _AlturaDer(raiz);
	}
	int Alturaizq() {
		return _AlturaIzq(raiz);
	}

};