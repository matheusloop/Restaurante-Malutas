#include "MenuFuncionario.h"

MenuFuncionario::MenuFuncionario(SistemaRestaurante &rest):restaurante(rest){
}

void MenuFuncionario::iniciar(){

	int op;
	string senhaDigitada;
	const int SAIR_MENU = 13;
	
	cout<<endl<<"----- Sistema Funcion�rio -----"<<endl<<endl;
	cout<<"Digite a senha de acesso: ";
	getline(cin, senhaDigitada);
  
	if(restaurante.verificarSenha(senhaDigitada)){

		do {
			system("cls");
			
			cout << "----> RESTAURANTE MALUTA'S <----" << endl;
			cout << "Listar Card�pio....[1]" << endl;
			cout << "Adicionar Prato....[2]" << endl;
			cout << "Remover Prato......[3]" << endl;
			cout << "Atualizar Pratos...[4]" << endl << endl;
			
			cout << "-----> PEDIDOS PRESENCIAIS <-----" << endl;
			cout << "Lista..............[5]" << endl;
			cout << "Atender Pedido.....[6]" << endl;
			cout << "Cancelar Pedido....[7]" << endl << endl;
			
			cout << "------> PEDIDOS DELIVERY <------" << endl;
			cout << "Lista..............[8]" << endl;
			cout << "Atender Pedido.....[9]" << endl;
			cout << "Cancelar Pedido...[10]" << endl << endl;
			
			cout << "Hist�rico.........[11]" << endl;
			cout << "Dinheiro em caixa.[12]" << endl;
			cout << "Sair do Menu......[13]" << endl << endl;
			cout << "Escolha: ";
			cin >> op;
			cin.ignore();
			
			realizarOpcaoFuncionario(op);
			
			cout << endl;
			system("pause");
			system("cls");
		} while (op != SAIR_MENU);
	}
	else{
		cout << endl << "Senha inv�lida" << endl;
		system("pause");
		system("cls");
	}
}

void MenuFuncionario::realizarOpcaoFuncionario(int op){

	system("cls");
	if (op == 1) {
		listarCardapio();
	} else if (op == 2) {
		adicionarPrato();
	} else if (op == 3) {
		removerPrato();
	} else if (op == 4) {
		atualizarPrato();
	} else if (op == 5) {
		listarPedidosPresenciais();
	} else if (op == 6) {
		atenderPedidoPresencial();
	} else if (op == 7) {
		cancelarPedidoPresencial();
	} else if (op == 8) {
		listarPedidosDelivery();
	} else if (op == 9) {
		atenderPedidoDelivery();
	} else if (op == 10) {
		cancelarPedidoDelivery();
	} else if (op == 11) {
		mostrarHistorico();
	} else if (op == 12) {
		verificarDinheiroCaixa();
	} else if (op == 13) {
		sairMenu();
	}
}

void MenuFuncionario::listarCardapio(){

	vector<Prato> pratos = restaurante.getCardapio();
	cout<<"------------- CARD�PIO -------------"<<endl<<endl;
	cout << fixed << setprecision(2);
	
	for(unsigned i = 0; i < pratos.size(); i++){
		cout<< "Prato: " << i+1 << endl;
		cout<<"Nome prato.......: "<<pratos[i].getNomePrato()<<endl;
		cout<<"Informa��es......: "<<pratos[i].getInforPrato()<<endl;
		cout<<"Tempo de preparo.: "<<pratos[i].getTempoPreparo()<<" minuto(s)"<<endl;
		cout<<"Tipo do prato....: "<<pratos[i].getTipoPrato()<<endl;
		cout<<"Vegetarianismo...: ";
	
		if(pratos[i].getVegetariano()){
		  cout<<"� vegetariano"<<endl;
		}
		else{
		  cout<<"N�o � vegetariano"<<endl;
		}
	
		cout<<setprecision(2)<<"Pre�o............: R$"<<pratos[i].getPreco()<<endl;
		cout<<"C�digo do Prato..: "<<pratos[i].getCodigoPrato()<<endl<<endl;
	}
}

void MenuFuncionario::adicionarPrato(){

	cout << "------ ADICIONAR PRATO ------"<< endl;
	
	Prato prato = coletarDadosPrato();
	
	if(restaurante.adicionarPrato(prato)){
		cout << endl <<"Prato adicionado com sucesso!!"<<endl;
		restaurante.salvarCardapio();
	}
	else {
		cout << endl << "J� existe um prato com esse c�digo!!" << endl;
	}
}

void MenuFuncionario::removerPrato(){ //Pego da SistemaRestaurante
	
	string codigoPrato;
	
	cout << "------ REMOVER PRATO ------"<< endl << endl;
	cout << "Digite o c�digo do prato: ";
	getline(cin,codigoPrato);

	if(restaurante.removerPrato(codigoPrato)){
		cout << endl << "Prato removido com sucesso!!" << endl;
		restaurante.salvarCardapio();
	}
	else{
		cout << endl << "N�o existe um prato com esse c�digo" << endl;
	}
}

void MenuFuncionario::atualizarPrato(){

	string codigoPrato;
	
	cout << "------ ATUALIZAR PRATO ------" << endl << endl;
	cout << "Digite o c�digo do prato que voc� deseja atualizar: ";
	getline(cin,codigoPrato);
	
	Prato prato = coletarDadosPrato();
	
	if(restaurante.atualizarPrato(prato, codigoPrato)){
		cout << endl << "Prato atualizado com sucesso!!" << endl;
		restaurante.salvarCardapio();
	}
	else{
		cout << endl << "N�o existe um prato com esse c�digo" << endl;
	}
}

Prato MenuFuncionario::coletarDadosPrato(){

	int tempoPreparo;
	string nomePrato, infoPrato, tipoPrato, codigoPrato, vegetariano;
	float preco;
	
	cout << endl << "Digite os dados do prato"<<endl <<endl;
	cout << "Nome do prato.....: ";
	getline(cin, nomePrato);
	cout << "Info. do prato....: ";
	getline(cin, infoPrato);
	cout << "Tempo de preparo..: ";
	cin  >> tempoPreparo;
	cin.ignore();
	cout << "Tipo do prato.....: ";
	getline(cin, tipoPrato);
	cout << "Vegetariano [s/n].: ";
	cin  >> vegetariano;
	cout << "Pre�o.............: ";
	cin  >> preco;
	cin.ignore();
	cout << "C�digo do Prato...: ";
	getline(cin, codigoPrato);
	
	Prato prato(nomePrato, infoPrato, tempoPreparo, tipoPrato, vegetariano == "s" || vegetariano == "S", preco, codigoPrato);
	
	return prato;
}

void MenuFuncionario::listarPratosPedidos(vector<Item> pratosPedidos) const{

	cout << endl << "* PRATOS PEDIDOS *" << endl;
	
	for(unsigned i = 0; i < pratosPedidos.size(); i++){
		Prato prato = pratosPedidos[i].getRefeicao();
		int quantidade = pratosPedidos[i].getQuantidade();
		
		cout << i+1 << " - " << prato.getNomePrato() << ", " << quantidade << " Unidades" << endl;
	
	}
	
	cout << endl << "*************************" << endl;
}

void MenuFuncionario::listarPedidosPresenciais(){

	vector <PedidoPresencial> pedidosPresenciais = restaurante.getPedidosPresenciais();
	Cliente infoCliente;
	
	cout<<"------------- PEDIDOS PRESENCIAIS -------------"<<endl<<endl;
	
	for(unsigned i = 0; i < pedidosPresenciais.size(); i++){

		vector<Item> pratosPedidos = pedidosPresenciais[i].getRefeicoesPedidas();
		infoCliente = pedidosPresenciais[i].getDadosCliente();
		
		cout << endl << "Pedido Presencial: " << i+1 << endl;
		cout << "Nome do Cliente....: " <<infoCliente.getNome()<<endl;
		cout << "CPF do Cliente.....: " <<infoCliente.getCPF()<<endl;
		cout << "Celular do Cliente.: " <<infoCliente.getCelular()<<endl;
		cout << "N�mero de mesa.....: " <<pedidosPresenciais[i].getNumMesa()<<endl;
		cout << "Valor da gorjeta...: R$" <<pedidosPresenciais[i].getGorjetaGarcom()<<endl;
		cout << "C�digo do pedido...: " <<pedidosPresenciais[i].getCodigoPedido()<<endl;
		cout << "Tempo total........: " <<pedidosPresenciais[i].calculaTempoTotal() << " minuto(s)"<<endl;
		cout << "Pre�o total........: R$" <<pedidosPresenciais[i].calculaPrecoTotalPresencial()<<endl;
		cout << "C�digo do pedido...: " <<pedidosPresenciais[i].getCodigoPedido()<<endl;
		listarPratosPedidos(pratosPedidos);
	}
}

void MenuFuncionario::atenderPedidoPresencial(){
	
	cout << "------ ATENDER PEDIDO PRESENCIAL ------" << endl << endl;
	if(restaurante.atenderPedidoPresencial()){
		cout << endl << "Pedido Atendido com sucesso!!" << endl;
	}
	else{
		cout << endl << "Ocorreu um erro no atendimento!!" << endl;
	}
}

void MenuFuncionario::cancelarPedidoPresencial(){

	int codigo;
	cout << "------ CANCELAR PEDIDO PRESENCIAL ------" << endl << endl;
	cout << "Digite o codigo do pedido que voc� deseja cancelar: ";
	cin  >> codigo;
	
	if(restaurante.removerPedidoPresencial(codigo)){
		cout << endl << "Pedido cancelado com sucesso!!" << endl;
	}
	else{
		cout << endl << "Ocorreu um erro no cancelamento!!" << endl;
	}
}

void MenuFuncionario::listarPedidosDelivery(){

	vector<PedidoDelivery> pedidosDelivery = restaurante.getPedidosDelivery();
	Cliente infoCliente;
	
	cout << "-----------> PEDIDOS DELIVERY <-----------" << endl << endl;
	
	for(unsigned i = 0; i < pedidosDelivery.size(); i++){
		vector<Item> pratosPedidos = pedidosDelivery[i].getRefeicoesPedidas();
		infoCliente = pedidosDelivery[i].getDadosCliente();
		
		cout << fixed << setprecision(2);
		cout << endl << "PEDIDO: " << i+1 << endl << endl;
		cout << "Nome do Cliente....: " <<infoCliente.getNome()<<endl;
		cout << "CPF do Cliente.....: " <<infoCliente.getCPF()<<endl;
		cout << "Celular do Cliente.: " <<infoCliente.getCelular()<<endl;
		cout << "Endere�o...........: " <<pedidosDelivery[i].getEndereco()<<endl;
		cout << "Tempo de entrega...: " <<pedidosDelivery[i].getTempoEntrega()<<" minuto(s)"<<endl;
		cout << "Pre�o da entrega...: R$" <<pedidosDelivery[i].getPrecoEntrega()<<endl;
		cout << "Tempo total........: " <<pedidosDelivery[i].calcularTempoTotal() << " minuto(s)"<<endl;
		cout << "Pre�o total........: R$" <<pedidosDelivery[i].calcularPrecoTotalDelivery()<<endl;
		cout << "C�digo do pedido...: " <<pedidosDelivery[i].getCodigoPedido()<<endl;
		listarPratosPedidos(pratosPedidos);
	}
}

void MenuFuncionario::atenderPedidoDelivery(){

	cout << "------ ATENDER PEDIDO DELIVERY ------" << endl << endl;
	if(restaurante.atenderPedidoDelivery()){
		cout << endl << "Pedido Atendido com sucesso!!" << endl;
	}
	else{
		cout << endl << "Ocorreu um erro no atendimento!!" << endl;
	}
}

void MenuFuncionario::cancelarPedidoDelivery(){
	
	int codigo;
	
	cout << "------ CANCELAR PEDIDO DELIVERY ------" << endl << endl;
	cout << "Digite o codigo do pedido que voc� deseja cancelar: ";
	cin  >> codigo;
	cin.ignore();
	
	if(restaurante.removerPedidoDelivery(codigo)){
		cout << endl << "Pedido cancelado com sucesso!!" << endl;
	}
	else{
		cout << endl << "Ocorreu um erro no cancelamento!!" << endl;
	}
}

void MenuFuncionario::mostrarHistorico(){

	cout<<"------ HIST�RICO DE PEDIDOS ------"<<endl<<endl;
	
	vector<PedidoDelivery> historicoDelivery = restaurante.getHistoricoDelivery();
	Cliente infoCliente;
	
	cout << endl << "-----------> HIST�RICO DELIVERY <-----------" << endl;
	
	for(unsigned i = 0; i < historicoDelivery.size(); i++){
		vector<Item> pratosPedidos = historicoDelivery[i].getRefeicoesPedidas();
		infoCliente = historicoDelivery[i].getDadosCliente();
		
		cout << fixed << setprecision(2);
		cout << endl << "PEDIDO DELIVERY: " << i+1 << endl << endl;
		cout << "Nome do Cliente....: " <<infoCliente.getNome()<<endl;
		cout << "CPF do Cliente.....: " <<infoCliente.getCPF()<<endl;
		cout << "Celular do Cliente.: " <<infoCliente.getCelular()<<endl;
		cout << "Endere�o...........: " <<historicoDelivery[i].getEndereco()<<endl;
		cout << "Tempo de entrega...: " <<historicoDelivery[i].getTempoEntrega()<<" minuto(s)"<<endl;
		cout << "Pre�o da entrega...: R$" <<historicoDelivery[i].getPrecoEntrega()<<endl;
		cout << "Tempo total........: " <<historicoDelivery[i].calcularTempoTotal() << " minuto(s)"<<endl;
		cout << "Pre�o total........: R$" <<historicoDelivery[i].calcularPrecoTotalDelivery()<<endl;
		cout << "C�digo do pedido...: " <<historicoDelivery[i].getCodigoPedido()<<endl;
		listarPratosPedidos(pratosPedidos);
	}

	vector<PedidoPresencial> historicoPresencial = restaurante.getHistoricoPresencial();
	
	cout << endl << "-----------> HIST�RICO PRESENCIAL <-----------" << endl;
	
	for(unsigned i = 0; i < historicoPresencial.size(); i++){
		vector<Item> pratosPedidos = historicoPresencial[i].getRefeicoesPedidas();
		infoCliente = historicoPresencial[i].getDadosCliente();
		
		cout << fixed << setprecision(2);
		cout << endl << "PEDIDO PRESENCIAL: " << i+1 << endl << endl;
		cout << "Nome do Cliente....: " <<infoCliente.getNome()<<endl;
		cout << "CPF do Cliente.....: " <<infoCliente.getCPF()<<endl;
		cout << "Celular do Cliente.: " <<infoCliente.getCelular()<<endl;
		cout << "N�mero de mesa.....: " <<historicoPresencial[i].getNumMesa()<<endl;
		cout << "Valor da gorjeta...: R$" <<historicoPresencial[i].getGorjetaGarcom()<<endl;
		cout << "Tempo total........: " <<historicoPresencial[i].calculaTempoTotal() << " minuto(s)"<<endl;
		cout << "Pre�o total........: R$" <<historicoPresencial[i].calculaPrecoTotalPresencial()<<endl;
		cout << "C�digo do pedido...: " <<historicoPresencial[i].getCodigoPedido()<<endl;
		listarPratosPedidos(pratosPedidos);
	}
}

void MenuFuncionario::verificarDinheiroCaixa(){

  cout<<"A quantia atual dispon�vel no caixa � de: R$ "<<fixed<<setprecision(2)<<restaurante.getDinheiroCaixa()<<endl;
}

void MenuFuncionario::sairMenu(){
	
	cout<<"O sistema ser� fechado..."<<endl;
	cout<<"N�s do MALUTA'S agradecemos a sua prefer�ncia e aguardamos o seu retorno!"<<endl;
	cout<<"Obrigado!"<<endl;
}