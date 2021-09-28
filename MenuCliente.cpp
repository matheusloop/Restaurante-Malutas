#include "MenuCliente.h"

MenuCliente::MenuCliente(SistemaRestaurante &rest):restaurante(rest){}

void MenuCliente::iniciar(){

	int op;
	const int SAIR_MENU = 4;

	do{
		system("cls");
	  	cout<<"----> RESTAURANTE MALUTA'S <----"<<endl;
    	cout<<"Ver Cardápio...............[1]"<<endl;
    	cout<<"Fazer Pedido Presencial....[2]"<<endl;
    	cout<<"Fazer Pedido Delivery......[3]"<<endl;
    	cout<<"Fechar o sistema...........[4]"<<endl;

    	cout<<endl<<"O que deseja fazer: ";
        cin>>op;
        cin.ignore();

		realizarOpcao(op);

		cout<<endl;
        system("pause");
		system("cls");
	}while(op != SAIR_MENU);
}

void MenuCliente::realizarOpcao(int op){
    
	system("cls");
	if(op == 1) {
		verCardapio();
	}else if (op == 2) {
	  realizarPedidoPresencial();
	}else if (op == 3) {
	  realizarPedidoDelivery();
	}else if (op == 4) {
	  sairMenu();
	}
}

void MenuCliente::verCardapio(){
	
	vector<Prato> cardapioOrdenado;
	
	cardapioOrdenado = selecionarOrdenacao();
	listarCardapio(cardapioOrdenado);
}

vector<Prato> MenuCliente::selecionarOrdenacao(){
	char op;
	
	cout<<"-------- Ordenação --------"<<endl;

	cout<<"Nome do prato........[1]"<<endl;
	cout<<"Tempo de preparo.....[2]"<<endl;
	cout<<"Tipo do prato........[3]"<<endl;
	cout<<"Opções vegetarianas..[4]"<<endl;
	cout<<"Preço................[5]"<<endl;
	
	cout<<endl<<"Por qual opção acima deseja filtrar o cardápio: ";
	cin>>op;
	cin.ignore();

    if(op == '1'){
      return restaurante.ordenarCardapio("NomePrato");
    }
    else if(op == '2'){
      return restaurante.ordenarCardapio("TempoPreparo");
    }
    else if(op == '3'){
      return restaurante.ordenarCardapio("TipoPrato");
    }
    else if(op == '4'){
      return restaurante.ordenarCardapio("Vegetariano");
    }
    else if(op == '5'){
      return restaurante.ordenarCardapio("Preco");
    }
}

void MenuCliente::listarCardapio(vector<Prato> pratos){
	
	system("cls");
	cout<<"------------- CARDÁPIO -------------"<<endl;

	cout << fixed << setprecision(2);
	for(unsigned i = 0; i < pratos.size(); i++){

    cout << endl << "Prato: " << i+1 << endl;
    cout<<"Nome prato.......: "<<pratos[i].getNomePrato()<<endl;
    cout<<"Informações......: "<<pratos[i].getInforPrato()<<endl;
    cout<<"Tempo de preparo.: "<<pratos[i].getTempoPreparo()<<" minutos"<<endl;
    cout<<"Tipo do prato....: "<<pratos[i].getTipoPrato()<<endl;
	cout<<"Vegetarianismo...: ";
    
	if(pratos[i].getVegetariano()){
      cout<<"É vegetariano"<<endl;
    }
    else{
      cout<<"Não é vegetariano"<<endl;
    }

    cout<<setprecision(2)<<"Preço............: R$"<<pratos[i].getPreco()<<endl;
  }
}

void MenuCliente::realizarPedidoPresencial(){

    Cliente infoCliente;
    vector<Item> pratosSelecionados;
    int numMesa;
    float gorjetaGarcom;
	
    infoCliente = coletarDadosCliente();
    
    cout<<"Número de mesa: ";
    cin>>numMesa;
    cout<<"Qual o valor da gorjeta: ";
    cin>>gorjetaGarcom;
    cout<<endl;
    
    pratosSelecionados = escolherPratos();


    PedidoPresencial presencial(infoCliente, numMesa, gorjetaGarcom);
    presencial.setRefeicoesPedidas(pratosSelecionados);

    restaurante.adicionarPedidoPresencial(presencial);
}

void MenuCliente::realizarPedidoDelivery(){
    
	Cliente infoCliente;
    vector<Item> pratosSelecionados;
    string endereco;

    infoCliente = coletarDadosCliente();
    cout << "Endereço: ";
    getline(cin, endereco);
    cout << endl;
    pratosSelecionados = escolherPratos();

    PedidoDelivery delivery(endereco, infoCliente, 20, 5);
    delivery.setRefeicoesPedidas(pratosSelecionados);

    restaurante.adicionarPedidoDelivery(delivery);

}

Cliente MenuCliente::coletarDadosCliente(){
	
	string nome, cpf, celular;

	cout<<"----> INSIRA SEUS DADOS <----"<<endl;
	cout<<"Nome: ";
	getline(cin,nome);

	cout<<"CPF: ";
	getline(cin,cpf);

	cout<<"Celular: ";
	getline(cin,celular);

	Cliente cliente(nome,cpf,celular);

	return cliente;
}

vector<Item> MenuCliente::escolherPratos(){
	
	vector<Item> pratosSelecionados;
	vector<Prato> cardapioOrdenado;
	char sair;
	int quantidade;
	unsigned posicao;
	
	cardapioOrdenado = selecionarOrdenacao();
	
	while(true){
    	listarCardapio(cardapioOrdenado);

	    cout<<endl<<"Qual o prato escolhido? [1 - " << cardapioOrdenado.size() << "]: ";
	    cin>>posicao;
	    cin.ignore();
	
	    if(posicao > cardapioOrdenado.size() || posicao <= 0){
	        cout << endl << "Prato não encontrado" << endl;
	        cout << endl;
	        system("pause");
	        system("cls");
	        continue;
		}
	
	    cout<<endl<<"Qual a quantidade?: ";
	    cin>>quantidade;
	
	    Item refeicao(cardapioOrdenado[posicao-1], quantidade);
	    pratosSelecionados.push_back(refeicao);
	
	    cout<<endl<<"Finalizar Pedido?: ";
	    cin>>sair;
	
	    if(sair=='s'||sair=='S'){
	      cout << endl;
	      break;
	    }
	    
		cout << endl;
	    system("pause");
	    system("cls");
  }

  return pratosSelecionados;
}

void MenuCliente::sairMenu(){
	
	cout<<"O sistema será fechado..."<<endl;
	cout<<"Nós do MALUTA'S agradecemos a sua preferência e aguardamos o seu retorno!"<<endl;
	cout<<"Obrigado!"<<endl;
}