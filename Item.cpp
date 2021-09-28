#include "Item.h"

Item::Item(Prato refeicao, int quantidade){
	
	this->refeicao = refeicao;
	this->quantidade = quantidade;
}

void Item::setRefeicao(Prato refeicao){
	
	this->refeicao = refeicao;
}

void Item::setQuantidade(int quantidade){
	
	this->quantidade = quantidade;
}

Prato Item::getRefeicao()const{
	
	return refeicao;
}

int Item::getQuantidade()const{
	
	return quantidade;
}

int Item::calcularTempoPreparo(){
	
	return refeicao.getTempoPreparo();
}

float Item::calcularValorProduto(){
	
	return refeicao.getPreco() * quantidade;
}