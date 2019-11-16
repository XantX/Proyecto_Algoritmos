#include <iostream>
#include <string>
#include "Archivo.h"
#include "Arbol.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::IO;

std::string Convertir(String^dato){
	msclr::interop::marshal_context context;
	std::string standardString = context.marshal_as<std::string>(dato);
	return standardString;
}
void Listar(String^ Dir){//ruta
	
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
	AVL<CuentaBancaria>*nuevo=new AVL<CuentaBancaria>();

	while (myEnum->MoveNext())
	{
		FileInfo^ f = safe_cast<FileInfo^>(myEnum->Current);
		nombre = Convertir(f->Name);
		direccion = Convertir(f->DirectoryName);
		tipo = Convertir(f->Extension);
		CuentaBancaria CuentaNueva(nombre, direccion, f->Length, tipo, 245713, f->CreationTimeUtc);
		nuevo->Insertar(CuentaNueva);
		//setear cantidad de dinero
	}
}


int main() {
	std::string Dir;
	std::cout << "dime la direccion" << std::endl;
	getline(std::cin, Dir);
	String^dir=gcnew String(Dir.c_str());
	Listar(dir);

	std::cin.get();
	return 0;
}