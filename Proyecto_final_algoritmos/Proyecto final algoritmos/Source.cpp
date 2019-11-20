#include <iostream>
#include "Interfaz.h"
#include "Arbol.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::IO;

std::string Convertir(String^dato){
	msclr::interop::marshal_context context;
	std::string standardString = context.marshal_as<std::string>(dato);
	return standardString;
}
//----------------------------------------------------------------
void imprimirObjeto(CuentaBancaria * cuenta) {
	std::cout << "--------------------------------" << std::endl;
	std::cout << cuenta->getnombre();
	std::cout << "archivo tipo: " << cuenta->gettipo();
	std::cout << "dinero en la cuenta: " << cuenta->getDinero() << std::endl;
	Console::WriteLine("Fecha de creacion: {0}", cuenta->Fecha());
	std::cout << "Direccion: " << cuenta->getdireccion();
}
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
		CuentaBancaria *CuentaNueva=new CuentaBancaria(nombre, direccion, f->Length, tipo, 245713, f->CreationTimeUtc);

		nuevo->Insertar(CuentaNueva, caso);
		//setear cantidad de dinero
	}
}


int main() {
	AVL<CuentaBancaria>*nuevo = new AVL<CuentaBancaria>();
	std::string Dir;
	std::cout << "Dime la ruta para escaner: " << std::endl;
	getline(std::cin, Dir);
	String^dir = gcnew String(Dir.c_str());
	Listar(dir,1,nuevo);// casos para la indexacion
	system("cls");
	Diseņo();

	int opcion;
	std::cin >> opcion;

	switch (opcion)
	{
	case 1:
		system("cls");
		DiseņoNombre();
		break;
	case 2:
		system("cls");
		
		break;
	case 3:
		system("cls");
		DiseņoPeso();
		break;
	case 4:
		system("cls");
		DiseņoDinero();
		break;
	case 5:
		system("cls");
		return 0;
		break;
	}

	std::cin.ignore();
	std::cin.get();
	return 0;
}