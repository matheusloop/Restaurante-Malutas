#include "PedidoDelivery.h"

PedidoDelivery::PedidoDelivery(string endereco, Cliente dadosCliente, int tempoEntrega, float precoEntrega){

    this->endereco = endereco;
    this->dadosCliente = dadosCliente;
    this->tempoEntrega = tempoEntrega;
    this->precoEntrega = precoEntrega;

    incrementarBaseCodigo();
    codigoPedido = baseCodigo;
}

void PedidoDelivery::setEndereco(string endereco){
    
	this->endereco = endereco;
}

void PedidoDelivery::setTempoEntrega(int tempoEntrega){
    
	this->tempoEntrega = tempoEntrega;
}

void PedidoDelivery::setPrecoEntrega(float precoEntrega){
    
	this->precoEntrega = precoEntrega;
}

string PedidoDelivery::getEndereco() const{
    
	return endereco;
}

int PedidoDelivery::getTempoEntrega() const{
    
	return tempoEntrega;
}

float PedidoDelivery::getPrecoEntrega() const{
    return precoEntrega;
}

int PedidoDelivery::calcularTempoTotal(){

    int tempoTotal = 0;

    for(unsigned i = 0; i < refeicoesPedidas.size(); i++){

        if(refeicoesPedidas[i].calcularTempoPreparo() > tempoTotal){
            tempoTotal = refeicoesPedidas[i].calcularTempoPreparo();
        }
    }

    tempoTotal += tempoEntrega;

    return tempoTotal;
}

float PedidoDelivery::calcularPrecoTotalDelivery(){

    float precoTotal = 0;

    for(unsigned i = 0; i < refeicoesPedidas.size(); i++){

        precoTotal += refeicoesPedidas[i].calcularValorProduto();
    }

    precoTotal += precoEntrega;

    return precoTotal;
}