#pragma once
#include "Arbol.h"
#include <string>

void interface() {

	std::string Dir;
	std::cout << "Dime la ruta para escaner: " << std::endl;
	getline(std::cin, Dir);
	String^dir = gcnew String(Dir.c_str());
	Listar(dir);

	system("cls");
}