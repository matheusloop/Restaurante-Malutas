#include "Prato.h"

Prato::Prato(string nomePrato, string inforPrato, int tempoPreparo, string tipoPrato, bool vegetariano, float preco, string codigoPrato){
	
	this->nomePrato=nomePrato;
	this->inforPrato=inforPrato;
	this->tempoPreparo=tempoPreparo;
	this->tipoPrato=tipoPrato;
	this->vegetariano=vegetariano;
	this->preco=preco;
	this->codigoPrato=codigoPrato;
}

void Prato::setNomePrato(string nomePrato){
	
	this->nomePrato=nomePrato;
}

void Prato::setInforPrato(string inforPrato){
	
	this->inforPrato=inforPrato;
}

void Prato::setTempoPreparo(int tempoPreparo){
	
	this->tempoPreparo=tempoPreparo;
}

void Prato::setTipoPrato(string tipoPrato){
	
	this->tipoPrato=tipoPrato;
}

void Prato::setVegetariano(bool vegetariano){
	
	this->vegetariano = vegetariano;
}

void Prato::setPreco(float preco){
	
	this->preco=preco;
}

void Prato::setCodigoPrato(string codigoPrato){
    
	this->codigoPrato=codigoPrato;
}

string Prato::getNomePrato() const{
	
	return nomePrato;
}

string Prato::getInforPrato() const{
	
	return inforPrato;
}

int Prato::getTempoPreparo() const{
	
	return tempoPreparo;
}

string Prato::getTipoPrato() const{
	
	return tipoPrato;
}

bool Prato::getVegetariano() const{
	
	return vegetariano;
}

float Prato::getPreco() const{
	
	return preco;
}

string Prato::getCodigoPrato() const{
    
	return codigoPrato;
}