#pragma once
#include <iostream>
#include "Archivo.h"

void Dise�o() {
	std::cout << "Seleccion una opcion"<<std::endl;
	std::cout <<"  Buscar por: "<<std::endl;
	std::cout <<"   1)Nombre" << std::endl;
	std::cout <<"   2)Fecha de creacion" << std::endl;
	std::cout <<"   3)Peso de archivo" << std::endl;
	std::cout <<"   4)Dinero en cuenta" << std::endl;
	std::cout << "  5)Salir" << std::endl;
	std::cout <<"--------opcion-------->";
	//system("cls");
}
void Dise�oNombre() {
	std::cout << "Elige una opcion"<<std::endl;
	std::cout << "1) Buscar por letra inicial" << std::endl;
	std::cout << "2) Buscar por nombre" << std::endl;
	std::cout << "3) el nombre del archivo contiene:" << std::endl;
}

void Dise�oPeso() {
	std::cout << "Elige una opcion:" << std::endl;
	std::cout << "1) Peso mayor"<<std::endl;
	std::cout << "2) Peso menor"<<std::endl;
	std::cout << "3) Peso menor a" << std::endl;
	std::cout << "----------opcion-------->" << std::endl;
}
void Dise�oDinero() {
	std::cout << "Elige una opcion:" << std::endl;
	std::cout << "1) mayor cantidad de dinero" << std::endl;
	std::cout << "2) menor contidad de dinero" << std::endl;
	std::cout << "3) dinero menor a" << std::endl;
	std::cout << "----------opcion-------->" << std::endl;
}