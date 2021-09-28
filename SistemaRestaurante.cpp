#include "SistemaRestaurante.h"

SistemaRestaurante::SistemaRestaurante():senhaFuncionario("1234"){
	
	this->dinheiroCaixa = 0;

	abrirCardapio();

}

void SistemaRestaurante::setDinheiroCaixa(float dinheiroCaixa){
    
	this->dinheiroCaixa = dinheiroCaixa;
}

float SistemaRestaurante::getDinheiroCaixa() const{
    
	return dinheiroCaixa;
}

vector<Prato> SistemaRestaurante::getCardapio() const{
    
	return cardapio;
}

vector<PedidoPresencial> SistemaRestaurante::getPedidosPresenciais() const{
    
	return pedidosPresenciais;
}

vector<PedidoDelivery> SistemaRestaurante::getPedidosDelivery() const{
    
	return pedidosDelivery;
}

vector<PedidoPresencial> SistemaRestaurante::getHistoricoPresencial() const{
    
	return historicoPresencial;
}

vector<PedidoDelivery> SistemaRestaurante::getHistoricoDelivery() const{
    
	return historicoDelivery;
}

bool SistemaRestaurante::adicionarPrato(Prato prato){

	int posicao = posicaoPrato(prato.getCodigoPrato());
	
	if(posicao == -1){
		cardapio.push_back(prato);
		return true;
	}
	return false;

}

bool SistemaRestaurante::removerPrato(string codigoPrato){

    int posicao = posicaoPrato(codigoPrato);

    if(posicao != -1){
        cardapio.erase(cardapio.begin() + posicao);
        return true;
    }

    return false;
}

bool SistemaRestaurante::atualizarPrato(Prato prato, string codigoPrato){

    int posicao = posicaoPrato(codigoPrato);

    if(posicao != -1){
        cardapio[posicao] = prato;
        return true;
    }
    return false;
}

bool ordenarNomePrato(Prato prato1, Prato prato2){

    if(prato1.getNomePrato() < prato2.getNomePrato()){
        return true;
    }
    return false;
}

bool ordenarTempoPreparo(Prato prato1, Prato prato2){

    if(prato1.getTempoPreparo() < prato2.getTempoPreparo()){
        return true;
    }
    return false;
}

bool ordenarTipoPrato(Prato prato1, Prato prato2){

    if(prato1.getTipoPrato() < prato2.getTipoPrato()){
        return true;
    }
    return false;
}

bool ordenarVegetariano(Prato prato1, Prato prato2){

    if(prato1.getVegetariano() > prato2.getVegetariano()){
        return true;
    }
    return false;
}

bool ordenarPreco(Prato prato1, Prato prato2){

    if(prato1.getPreco() < prato2.getPreco()){
        return true;
    }
    return false;
}

vector<Prato> SistemaRestaurante::ordenarCardapio(string tipoOrdenacao){

    vector<Prato> cardapioAux = cardapio;

    //Ordena por nome
    if(tipoOrdenacao == "NomePrato"){
        sort(cardapioAux.begin(), cardapioAux.end(), ordenarNomePrato);
    }

    //Ordena por tempo de preparo
    else if(tipoOrdenacao == "TempoPreparo"){
        sort(cardapioAux.begin(), cardapioAux.end(), ordenarTempoPreparo);
    }

    //Ordena por tipo de prato
    else if(tipoOrdenacao == "TipoPrato"){
        sort(cardapioAux.begin(), cardapioAux.end(), ordenarTipoPrato);
    }

    //Ordena por vegetariano
    else if(tipoOrdenacao == "Vegetariano"){
        sort(cardapioAux.begin(), cardapioAux.end(), ordenarVegetariano);
    }

    //Ordena por preco
    else if(tipoOrdenacao == "Preco"){
        sort(cardapioAux.begin(), cardapioAux.end(), ordenarPreco);
    }

    return cardapioAux;
}

void SistemaRestaurante::adicionarPedidoPresencial(PedidoPresencial pedido){
    pedidosPresenciais.push_back(pedido);
}

bool SistemaRestaurante::atenderPedidoPresencial(){

	if(pedidosPresenciais.size() > 0){

        historicoPresencial.push_back(pedidosPresenciais[0]);

        dinheiroCaixa += pedidosPresenciais[0].calculaPrecoTotalPresencial();

        pedidosPresenciais.erase(pedidosPresenciais.begin());

        return true;
	}
	else{
        return false;
	}
}

bool SistemaRestaurante::removerPedidoPresencial(int codigoPedido){

    int posicao = posicaoPedidoPresencial(codigoPedido);

    if(posicao != -1){
        pedidosPresenciais.erase(pedidosPresenciais.begin() + posicao);

        return true;
    }
    else{
        return false;
    }
}

void SistemaRestaurante::adicionarPedidoDelivery(PedidoDelivery pedido){
    pedidosDelivery.push_back(pedido);
}

bool SistemaRestaurante::atenderPedidoDelivery(){

    if(pedidosDelivery.size() > 0){

        historicoDelivery.push_back(pedidosDelivery[0]);

        dinheiroCaixa += pedidosDelivery[0].calcularPrecoTotalDelivery();

        pedidosDelivery.erase(pedidosDelivery.begin());

        return true;
	}
	else{
        return false;
	}
}

bool SistemaRestaurante::removerPedidoDelivery(int codigoPedido){

    int posicao = posicaoPedidoDelivery(codigoPedido);

    if(posicao != -1){
        pedidosDelivery.erase(pedidosDelivery.begin() + posicao);

        return true;
    }
    else{
        return false;
    }
}

int SistemaRestaurante::posicaoPrato(string codigoPrato){

	for (unsigned i = 0;  i < cardapio.size(); i++){
		if(cardapio[i].getCodigoPrato() == codigoPrato){

			return i;

		}
	}

	return -1;
}

int SistemaRestaurante::posicaoPedidoPresencial(int codigoPedido){

	for (unsigned i = 0;  i < pedidosPresenciais.size(); i++){
		if(pedidosPresenciais[i].getCodigoPedido() == codigoPedido){

			return i;
		}

	}

	return -1;
}

int SistemaRestaurante::posicaoPedidoDelivery(int codigoPedido){

	for (unsigned i = 0;  i < pedidosDelivery.size(); i++){
		if(pedidosDelivery[i].getCodigoPedido() == codigoPedido){
			return i;
		}
	}
	
	return -1;
}

bool SistemaRestaurante::verificarSenha(string senhaDigitada){

	bool existe = false;

	if (senhaFuncionario == senhaDigitada) {
      existe = true;
    }

	return existe;
}

void SistemaRestaurante::abrirCardapio(){

	string nomePrato, inforPrato, tipoPrato, codigoPrato;
	int tempPrep;
	bool vegetariano;
	float preco;
	
	ifstream arquivoCardapio;
	arquivoCardapio.open("CardapioRestaurante.txt");

	if(arquivoCardapio.is_open()){

    	while(!arquivoCardapio.eof()){
	        getline(arquivoCardapio, nomePrato);
	        getline(arquivoCardapio, inforPrato);
	        arquivoCardapio>>tempPrep;
	        arquivoCardapio.ignore();
	        getline(arquivoCardapio, tipoPrato);
	        arquivoCardapio>>vegetariano;
	        arquivoCardapio>>preco;
	        arquivoCardapio.ignore();
	        getline(arquivoCardapio, codigoPrato);
	
	        Prato novoItem(nomePrato, inforPrato, tempPrep, tipoPrato, vegetariano, preco, codigoPrato);
	
	        cardapio.push_back(novoItem);
		}
	}

	arquivoCardapio.close();
}

void SistemaRestaurante::salvarCardapio(){

	ofstream arquivoCardapio;
	arquivoCardapio.open("CardapioRestaurante.txt");
	
	if(arquivoCardapio.is_open()){

	    for(unsigned i = 0; i < cardapio.size(); i++){
	
	    	if(i != 0){
	          arquivoCardapio << endl;
			}
	
	      arquivoCardapio << cardapio[i].getNomePrato();
	      arquivoCardapio << endl << cardapio[i].getInforPrato();
	      arquivoCardapio << endl << cardapio[i].getTempoPreparo();
	      arquivoCardapio << endl << cardapio[i].getTipoPrato();
	      arquivoCardapio << endl << cardapio[i].getVegetariano();
	      arquivoCardapio << endl << cardapio[i].getPreco();
	      arquivoCardapio << endl << cardapio[i].getCodigoPrato();
	    }
	}

	arquivoCardapio.close();
}

SistemaRestaurante::~SistemaRestaurante(){

	salvarCardapio();
}