#pragma once
#include "Archivo.h"
#include "Arbol.h"
template<typename T>
class iterador {
private:
	CuentaBancaria aux;
public:
	iterador() {
	}
	~iterador() {

	}
	CuentaBancaria dame( Nodo<T>*nodo) {
		aux = nodo->elemento;
		return aux;
	}
};
