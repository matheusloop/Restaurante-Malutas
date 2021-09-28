#include "PedidoPresencial.h"

PedidoPresencial::PedidoPresencial(Cliente dadosCliente, int numMesa,float gorjetaGarcom){
	
	this->numMesa=numMesa;
	this->gorjetaGarcom=gorjetaGarcom;
	this->dadosCliente=dadosCliente;

	incrementarBaseCodigo();
    codigoPedido = baseCodigo;
}

void PedidoPresencial::setNumMesa(int numMesa){
	
	this->numMesa=numMesa;
}

void PedidoPresencial::setGorjetaGarcom(float gorjetaGarcom){
	
	this->gorjetaGarcom=gorjetaGarcom;
}

int PedidoPresencial::getNumMesa() const{
	
	return numMesa;
}

float PedidoPresencial::getGorjetaGarcom() const{
	
	return gorjetaGarcom;
}

float PedidoPresencial::calculaPrecoTotalPresencial(){
	
	float valor=0;
	
	for (unsigned i=0; i<refeicoesPedidas.size(); i++){
		valor += refeicoesPedidas[i].calcularValorProduto();
	}
	
	return valor+=gorjetaGarcom;
}

int PedidoPresencial::calculaTempoTotal(){
	
	int tempoTotal=0;
	
	for (unsigned j=0; j<refeicoesPedidas.size(); j++){
        if(tempoTotal < refeicoesPedidas[j].calcularTempoPreparo()){
			tempoTotal = refeicoesPedidas[j].calcularTempoPreparo();
        }
	}
	
	return tempoTotal;
}