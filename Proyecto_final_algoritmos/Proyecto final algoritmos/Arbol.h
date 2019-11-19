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
	CuentaBancaria *aux2;
	std::vector<CuentaBancaria>arrcuentas;
	std::vector<CuentaBancaria>elementosEliminados;
	int comparar(int uno, int dos) {//
		return uno - dos;
	}
	//--------------------------------------------------------
	bool _eliminar(Nodo<T>*& nodo, CuentaBancaria *e) {//eleminar por letraIni
		if (nodo == nullptr) return false;
		else {
			aux2 = nodo->elemento;
			int letraBuscar=int(e->getnombre().front());
			int letraEncontrada= int(aux2->getnombre().front());
			int r = comparar(letraEncontrada, letraBuscar);
			if (r < 0) {
				return _eliminar(nodo->der, e);
			}
			else if (r > 0) {
				return _eliminar(nodo->izq, e);
			}
			else { // r==0 es porque se encontró el elemento e en el arbol
				if (nodo->der == nullptr && nodo->izq == nullptr) {//caso 1
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->izq == nullptr) { //caso 2
					nodo = nodo->der;
					return true;
				}
				else if (nodo->der == nullptr) { //caso 3
					nodo = nodo->izq;
					return true;
				}
				else { //caso 4
					Nodo<T> *aux = nodo->der; //Se establece buscar el menor elemento por la derecha
					while (aux->izq != nullptr)
					{
						aux = aux->izq; //Se obtiene la hoja menor
					}
					nodo->elemento = aux->elemento; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, aux->elemento); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}
	}
	//---------------------------------------------------------
	
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
		aux2 = new CuentaBancaria();
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

	CuentaBancaria _eliminarObtener() {//obtiene el elemento de la raiz del arbol
		aux = raiz->elemento;
		_eliminar(raiz, raiz->elemento);
		return aux;
	}

};