#pragma once
#include <iostream>
#include "Arbol.h"
#include <string>
void imprimirObjeto(CuentaBancaria * cuenta) {
	std::cout << "--------------------------------" << std::endl;
	std::cout << cuenta->getnombre()<<std::endl;
	std::cout << "archivo tipo: " << cuenta->gettipo()<<std::endl;
	std::cout << "dinero en la cuenta: " << cuenta->getDinero() << std::endl;
	Console::WriteLine("Fecha de creacion: {0}", cuenta->Fecha());
	std::cout << "Direccion: " << cuenta->getdireccion() << std::endl;
	std::cout << "Peso " << cuenta->getpeso() <<" bytes"<< std::endl;
}
void Diseño() {
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
void DiseñoNombre(AVL<CuentaBancaria>*nueva) {
	std::cout << "Elige una opcion"<<std::endl;
	std::cout << "1) Buscar por letra inicial" << std::endl;
	std::cout << "2) Buscar por nombre" << std::endl;
	std::cout << "3) el nombre del archivo contiene:" << std::endl;
	int opcion;
	std::string ini;
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
		std::cout <<"dime la letra con la que inicia el archivo"<<std::endl;
		std::cin >> ini;
		nueva->BucarIni(ini);
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size();i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	case 2:
		std::cout << "dime el nombre del archivo" << std::endl;
		std::cin >> ini;
		nueva->BuscarContiene(ini);
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	case 3:
		std::cout << "dime una parte del nombre del archivo" << std::endl;
		std::cin >> ini;
		nueva->BuscarContiene(ini);
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	default:
		system("cls");
		std::cout << "presiona cualquier tecla para volver al menu" << std::endl;
		break;
	}
}
void DiseñoPeso(AVL<CuentaBancaria>*nueva) {
	std::cout << "Elige una opcion:" << std::endl;
	std::cout << "1) Peso mayor"<<std::endl;
	std::cout << "2) Peso menor"<<std::endl;
	std::cout << "----------opcion-------->" << std::endl;
	int opcion;
	std::cin >> opcion;

	switch (opcion)
	{
	case 1:
		nueva->pesoMayor();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	case 2:
		nueva->pesoMenor();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	default:
		system("cls");
		std::cout << "presiona cualquier tecla para volver al menu" << std::endl;
		break;
	}
}
void DiseñoDinero(AVL<CuentaBancaria>*nueva) {
	std::cout << "Elige una opcion:" << std::endl;
	std::cout << "1) mayor cantidad de dinero" << std::endl;
	std::cout << "2) menor contidad de dinero" << std::endl;
	std::cout << "----------opcion-------->" << std::endl;
	int opcion;
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
		nueva->Mayordinero();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	case 2:
		nueva->Menordinero();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	default:
		system("cls");
		std::cout << "eliga la opcion de la lista"<<std::endl;
		std::cout << "precione la tecla enter";
		break;
	}
}
void DiseñoFecha(AVL<CuentaBancaria>*nueva) {
	std::cout << "Elige una opcion:" << std::endl;
	std::cout << "1) Cuenta mas antigua" << std::endl;
	std::cout << "2) Cuenta mas nueva" << std::endl;
	std::cout << "----------opcion-------->" << std::endl;
	int opcion;
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
		nueva->FechaAntigua();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}

		break;
	case 2:
		nueva->FechaReciente();
		system("cls");
		std::cout << "Los archivos coincidentes son: " << std::endl;
		for (int i = 0; i < nueva->arreglo().size(); i++) {
			imprimirObjeto(nueva->arreglo()[i]);
		}
		break;
	default:
		system("cls");
		std::cout << "eliga la opcion de la lista" << std::endl;
		std::cout << "precione la tecla enter";
		break;
	}

}