#include <iostream>
#include <locale>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#include "Cliente.cpp"
#include "Prato.cpp"
#include "Item.cpp"
#include "Pedido.cpp"
#include "PedidoDelivery.cpp"
#include "PedidoPresencial.cpp"
#include "SistemaRestaurante.cpp"
#include "MenuCliente.cpp"
#include "MenuFuncionario.cpp"

int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	char op;
	SistemaRestaurante restaurante;
	
	while(true){
		cout << "----> RESTAURANTE MALUTA'S <----" << endl;
		cout << "Cliente     [1]" << endl;
		cout << "Funcionário [2]" << endl;
		cout << "Sair        [3]" << endl << endl;
		cout << "Escolha: ";
		cin >> op;
		cin.ignore();
		
		if(op == '1'){
			MenuCliente menuCliente(restaurante);
			menuCliente.iniciar();
		} else if(op == '2'){
			MenuFuncionario menuFuncionario(restaurante);
			menuFuncionario.iniciar();
		} else if(op == '3'){
			cout << endl << "Tenha um bom dia" << endl;	
		   	break;
		} else{
			cout << endl << "Opção inválida" << endl;
			system("pause");
			system("cls");
		}
			
	}
	
	return 0;
}