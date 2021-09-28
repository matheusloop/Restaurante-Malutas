#include "Pedido.h"

int Pedido::baseCodigo = 0;

void Pedido::setDadosCliente(Cliente dadosCliente){
    
	this->dadosCliente = dadosCliente;
}

void Pedido::setRefeicoesPedidas(vector<Item> refeicoes){
    
	this->refeicoesPedidas = refeicoes;
}

vector<Item> Pedido::getRefeicoesPedidas() const{
	
	return refeicoesPedidas;
}

Cliente Pedido::getDadosCliente() const{
    
	return dadosCliente;
}

int Pedido::getCodigoPedido() const{
    
	return codigoPedido;
}

void Pedido::incrementarBaseCodigo(){

    baseCodigo += 1;
}