#include <iostream>
#include <string>
#include "dirent.h"
using namespace std;
void Litar(string Dir) {//ruta
	DIR*directorio;
	struct dirent*elemto;
	string nombre;
	long numero;
	if (directorio = opendir(Dir.c_str())) {
		while (elemto = readdir(directorio)) {
			nombre = elemto->d_name;
			numero = elemto->d_type;
			if (nombre != "."&& nombre != "..") { cout << nombre <<" "<< numero << endl; }
		}
	}
	closedir(directorio);
}
void init() {
	cout << "ruta: " << endl;
		string dir;
		getline(cin, dir);
		Litar(dir);
}
int main() {
	init();
	cin.get();
	return 0;
}