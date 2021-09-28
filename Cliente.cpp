#include "Cliente.h"

Cliente::Cliente(string nome, string cpf, string celular)
{

	setNome(nome);
	setCPF(cpf);
	setCelular(celular);
}

void Cliente::setNome(string nome)
{

	this->nome = nome;
}

void Cliente::setCPF(string cpf)
{

	this->cpf = cpf;
}

void Cliente::setCelular(string celular)
{

	this-> celular = celular;
}

string Cliente::getNome()const
{

	return nome;
}

string Cliente::getCPF()const
{

	return cpf;
}

string Cliente::getCelular()const
{

	return celular;
}