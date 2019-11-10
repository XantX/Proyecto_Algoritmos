#include <io.h>
#include <iostream>
#include <string>
#include "dirent.h"
using namespace System::IO;
using namespace std;
void Litar(string Dir) {//ruta
	DIR*directorio;
	struct dirent*elemto;
	string nombre;
	long size;
	if (directorio = opendir(Dir.c_str())) {
		while (elemto = readdir(directorio)) {
			nombre = elemto->d_name;
			
			if (nombre != "."&& nombre != "..") { cout << nombre <<" "<< size << endl; }
		}
	}
	closedir(directorio);
}
void init() {
	cout << "dime las ruta para escanear: " << endl;
		string dir;
		getline(cin, dir);
		Litar(dir);
}

int main() {
	init();
	cin.get();
	return 0;
}