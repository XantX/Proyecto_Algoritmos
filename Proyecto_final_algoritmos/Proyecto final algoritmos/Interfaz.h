#pragma once
#include <iostream>
#include "Archivo.h"
void Diseño() {
	std::cout << "Seleccion una opcion"<<std::endl;
	std::cout <<"   Buscar por: "<<std::endl;
	std::cout <<"   Nombre" << std::endl;
	std::cout <<"   Fecha de creacion" << std::endl;
	std::cout <<"   Peso de archivo" << std::endl;
	std::cout <<"   Dinero en cuenta" << std::endl;
	std::cout <<"--------opcion-------->";
	//system("cls");
}
void imprimirObjeto(CuentaBancaria * cuenta) {
	std::cout <<"--------------------------------"<<std::endl;
	std::cout <<cuenta->getnombre();
	std::cout <<"archivo tipo: "<<cuenta->gettipo();
	std::cout <<"dinero en la cuenta: "<<cuenta->getDinero() << std::endl;
	Console::WriteLine("Fecha de creacion: {0}" ,cuenta->Fecha());
	std::cout <<"Direccion: "<<cuenta->getdireccion;
}