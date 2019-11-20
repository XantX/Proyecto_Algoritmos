#pragma once
#include <iostream>
#include <vcclr.h>

class CuentaBancaria {
private:
	std::string nombre;
	std::string direccion;
	long long peso;
	std::string tipo;//tipo de archivo
	long long Dinero_en_banco;
	int orden;
	gcroot<System::DateTime>fechaCreacion;

public:
	CuentaBancaria();
	CuentaBancaria(std::string nombre, std::string direccion, long long peso, std::string tipo, long long Dinero_en_banco, System::DateTime fechaCreacion, int orden);
	~CuentaBancaria();
	long long getDinero();
	long long getpeso();
	std::string getnombre();
	std::string getdireccion();
	std::string gettipo();
	System::DateTime Fecha();
	int getorden();

};
CuentaBancaria::CuentaBancaria() {

}
CuentaBancaria::CuentaBancaria(std::string nombre, std::string direccion, long long peso, std::string tipo, long long Dinero_en_banco, System::DateTime fechaCreacion, int orden){
	this->nombre = nombre;
	this->direccion = direccion;
	this->peso = peso;
	this->tipo = tipo;
	this->Dinero_en_banco=Dinero_en_banco;
	this->fechaCreacion = fechaCreacion;
	this->orden = orden;
}
CuentaBancaria::~CuentaBancaria() {
}
long long CuentaBancaria::getDinero() {
	return Dinero_en_banco;
}
long long CuentaBancaria::getpeso() {
	return peso;
}
std::string CuentaBancaria::getnombre() {
	return nombre;
}
std::string CuentaBancaria::getdireccion() {
	return direccion;
}
std::string CuentaBancaria::gettipo() {
	return tipo;
}
System::DateTime CuentaBancaria::Fecha(){
	return fechaCreacion;
}
int CuentaBancaria::getorden() {
	return orden;
}