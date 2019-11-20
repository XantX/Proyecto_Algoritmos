#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "Archivo.h"
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
	std::vector<CuentaBancaria*>arrcuentas;
	std::vector<CuentaBancaria>elementosEliminados;
	int comparar(int uno, int dos) {//
		return uno - dos;
	}
	//--------------------------------------------------------
	bool _eliminar(Nodo<T>*& nodo, CuentaBancaria *e) {//eleminar por letraIni
		if (nodo == nullptr) return false;
		else {
			aux2 = nodo->elemento;
			int letraBuscar = e->getorden();
			
			int letraEncontrada = aux2->getorden();

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
					Nodo<T> *auxN = nodo->der; //Se establece buscar el menor elemento por la derecha
					while (auxN->izq != nullptr)
					{
						auxN = auxN->izq; //Se obtiene la hoja menor
					}
					nodo->elemento = auxN->elemento; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, auxN->elemento); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}
	}
	//---------------------------------------------------------

	//---------------------------------------------------------
	void _buscarLetraini(Nodo<T>*nodo, std::string LetraIni) {//buscar por letra de inicio
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			int arbolElemt = int(aux->getnombre().front());
			int elemtbuscado = int(LetraIni.front());
			int result=comparar(arbolElemt, elemtbuscado);
			
			if (result==0) {
				
				arrcuentas.push_back(aux);
			}
					_buscarLetraini(nodo->der, LetraIni);
					_buscarLetraini(nodo->izq, LetraIni);
		}
	}
	//-------------------------------------------------------------

	void _buscarContiene(Nodo<T>*nodo, std::string linea) {//buscar por contiene
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			
			if (aux->getnombre().size()>aux->getnombre().find(linea)) {
				arrcuentas.push_back(aux);
			}
			_buscarContiene(nodo->der, linea);
			_buscarContiene(nodo->izq, linea);
		}
	}
	void _pesoMayor(Nodo<T>*nodo, CuentaBancaria *mayor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (mayor->getpeso()>aux->getpeso()) {
				arrcuentas.clear();
				arrcuentas.push_back(mayor);
				aux2 = mayor;
			}
				_pesoMayor(nodo->der, aux2);
				_pesoMayor(nodo->izq, aux2);
		
			
		}
	}
	void _Mayordinero(Nodo<T>*nodo, CuentaBancaria *mayor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (mayor->getDinero()>aux->getDinero()) {
				arrcuentas.clear();
				arrcuentas.push_back(mayor);
				aux2 = mayor;
			}
			_pesoMayor(nodo->der, aux2);
			_pesoMayor(nodo->izq, aux2);
		}
	}
	void _Menordinero(Nodo<T>*nodo, CuentaBancaria *Menor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (Menor->getDinero()>aux->getDinero()) {
				arrcuentas.clear();
				arrcuentas.push_back(Menor);
				aux2 = Menor;
			}
			_pesoMayor(nodo->der, aux2);
			_pesoMayor(nodo->izq, aux2);
		}
	}
	void _pesoMenor(Nodo<T>*nodo, CuentaBancaria *menor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (menor->getpeso()<aux->getpeso()) {
				arrcuentas.clear();
				arrcuentas.push_back(menor);
				aux2 = menor;
			}
			_pesoMenor(nodo->der, aux2);
			_pesoMenor(nodo->izq, aux2);

		}
	}
	void _fechaAntigua(Nodo<T>*nodo, CuentaBancaria *menor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (menor->Fecha()<aux->Fecha()) {
				arrcuentas.clear();
				arrcuentas.push_back(menor);
				aux2 = menor;
			}
			_fechaAntigua(nodo->der, aux2);
			_fechaAntigua(nodo->izq, aux2);

		}
	}
	void _fechaMasreciente(Nodo<T>*nodo, CuentaBancaria *mayor) {
		if (nodo == nullptr) {
			return;
		}
		else {
			aux = nodo->elemento;
			aux2 = aux;
			if (mayor->Fecha()>aux->Fecha()) {
				arrcuentas.clear();
				arrcuentas.push_back(mayor);
				aux2 = mayor;
			}
			_fechaMasreciente(nodo->der, aux2);
			_fechaMasreciente(nodo->izq, aux2);
		}
	}
	//----------------------------------------------------------
	void rotarIzq(Nodo<T>*&nodo) {
		Nodo<T>*auxN = nodo->der;
		nodo->der = auxN->izq;
		auxN->izq = nodo;
		nodo = auxN;
	}
	void rotarDer(Nodo<T>*&nodo) {
		Nodo<T>*auxN = nodo->izq;
		nodo->izq = auxN->der;
		auxN->der = nodo;
		nodo = auxN;
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
			_insertarInicioLetra(raiz, e);
			break;
		case 2:
			_insertarFecha(raiz, e);
			break;
		case 3:
			_insertarTamaño(raiz, e);
			break;
		}
	}
	int Alturader() {
		return _AlturaDer(raiz);
	}
	int Alturaizq() {
		return _AlturaIzq(raiz);
	}
	std::vector<CuentaBancaria*> arreglo() {
		return arrcuentas;
	}
	CuentaBancaria* _eliminarObtener() {//obtiene el elemento de la raiz del arbol
		aux = raiz->elemento;
		_eliminar(raiz, raiz->elemento);
		return aux;
	}

	void BucarIni(std::string LetraIni) {
		arrcuentas.clear();
		_buscarLetraini(raiz, LetraIni);
	}
	void BuscarContiene(std::string Linea) {
		arrcuentas.clear();
		_buscarContiene(raiz, Linea);
		
	}
	void pesoMayor() {
		arrcuentas.clear();
		_pesoMayor(raiz,raiz->elemento);
	}
	void pesoMenor() {
		arrcuentas.clear();
		_pesoMenor(raiz,raiz->elemento);
	}
	void Mayordinero() {
		arrcuentas.clear();
		_Mayordinero(raiz, raiz->elemento);
	}
	void Menordinero() {
		arrcuentas.clear();
		_Menordinero(raiz, raiz->elemento);
	}
	void FechaAntigua() {
		arrcuentas.clear();
		_fechaAntigua(raiz, raiz->elemento);
	}
	void FechaReciente() {
		arrcuentas.clear();
		_fechaMasreciente(raiz,raiz->elemento);
	}
	bool is_full() {
		if (raiz != nullptr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool is_empty() {
		if (raiz==nullptr) {
			return 1;
		}
		else {
			return 0;
		}
	}
};