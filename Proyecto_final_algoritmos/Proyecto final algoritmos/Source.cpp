#include <iostream>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::IO;
#include "Interfaz.h"
int Flag=0;
int cantidadDeArchivos=0;


std::string Convertir(String^dato){
	msclr::interop::marshal_context context;
	std::string standardString = context.marshal_as<std::string>(dato);
	return standardString;
}
//----------------------------------------------------------------

//-------------------------------------------------------------------
void Listar(String^ Dir,int caso, AVL<CuentaBancaria>*nuevo){//ruta
	
    // Make a reference to a directory.
	DirectoryInfo^ di = gcnew DirectoryInfo(Dir);

	// Get a reference to each file in that directory.
	array<FileInfo^>^fiArr = di->GetFiles();

	// Display the names and sizes of the files.
	Console::WriteLine("The directory {0} contains the following files:", di->Name);
	System::Collections::IEnumerator^ myEnum = fiArr->GetEnumerator();
	std::string nombre;
	std::string direccion;
	std::string tipo;
	

	while (myEnum->MoveNext())
	{
		FileInfo^ f = safe_cast<FileInfo^>(myEnum->Current);
		nombre = Convertir(f->Name);
		direccion = Convertir(f->DirectoryName);
		tipo = Convertir(f->Extension);
		std::cout << nombre<<std::endl;
		CuentaBancaria *CuentaNueva=new CuentaBancaria(nombre, direccion, f->Length, tipo, 245713, f->CreationTimeUtc,cantidadDeArchivos+1);
		nuevo->Insertar(CuentaNueva, caso);
		cantidadDeArchivos++;
		//setear cantidad de dinero
	}
}

bool bandera(AVL<CuentaBancaria>*nuevo, AVL<CuentaBancaria>*copia) {
	Flag = 0;
	if (nuevo->is_full() && copia->is_empty()) {
		return Flag+1;
	}
	else {
		return Flag;
	}
}
void Cambio(AVL<CuentaBancaria>*nuevo, AVL<CuentaBancaria>*copia, int caso, void(*funcion)(AVL<CuentaBancaria>*)) {
	void(*pf)(AVL<CuentaBancaria>*);
	pf = funcion;
	if (bandera(nuevo, copia)) {
		for (int i = 0; i < cantidadDeArchivos; i++) {
			copia->Insertar(nuevo->_eliminarObtener(), caso);
		}
		(pf)(copia);
	}else {
		for (int i = 0; i < cantidadDeArchivos; i++) {
			nuevo->Insertar(copia->_eliminarObtener(), caso);
		}
		(pf)(nuevo);
	}
}
int main() {
	AVL<CuentaBancaria>*nuevo = new AVL<CuentaBancaria>();
	AVL<CuentaBancaria>*copia = new AVL<CuentaBancaria>();
	std::string Dir;
	std::cout << "Dime la ruta para escaner: " << std::endl;
	getline(std::cin, Dir);
	String^dir = gcnew String(Dir.c_str());
	Listar(dir, 1, nuevo);// casos para la indexacion
	system("cls");
	while (1) {
		system("pause");
		system("cls");
	Diseño();
	int opcion;
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
		system("cls");
		Cambio(nuevo, copia, opcion, DiseñoNombre);//implementado
		break;
	case 2:
		system("cls");
		Cambio(nuevo, copia, opcion, DiseñoFecha);
		break;
	case 3:
		system("cls");
		Cambio(nuevo, copia, opcion, DiseñoPeso);
		break;
	case 4:
		system("cls");
		Cambio(nuevo, copia, opcion, DiseñoDinero);
		break;
	case 5:
		system("cls");
		return 0;
		break;
	default:
		system("cls");
		std::cout << "eliga una opcion de la lista" << std::endl;
		std::cout << "precione cualquier tecla para voler a intentar";
		break;
	}
}
	std::cin.ignore();
	std::cin.get();
	return 0;
}