#include <io.h>
#include <iostream>
#include <string>
#include "dirent.h"
#include <vector>

using namespace System;
using namespace System::IO;

void Litar(String^ Dir){//ruta

    // Make a reference to a directory.
	DirectoryInfo^ di = gcnew DirectoryInfo(Dir);

	// Get a reference to each file in that directory.
	array<FileInfo^>^fiArr = di->GetFiles();

	// Display the names and sizes of the files.
	Console::WriteLine("The directory {0} contains the following files:", di->Name);
	System::Collections::IEnumerator^ myEnum = fiArr->GetEnumerator();
	while (myEnum->MoveNext())
	{
		FileInfo^ f = safe_cast<FileInfo^>(myEnum->Current);
		Console::WriteLine("The size of {0} is {1} bytes.", f->Name, f->Length);
	}
}


int main() {
	std::string Dir;
	std::cout << "dime la direccion" << std::endl;
	getline(std::cin, Dir);
	String^dir=gcnew String(Dir.c_str());
	Litar(dir);

	std::cin.get();
	return 0;
}