#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

/**
  * Classe responsavel por fazer toda a interecao com o cliente
  */
class MenuCliente{

	private:

		SistemaRestaurante &restaurante;

	public:

		/**
         * Construtor da classe MenuCliente
         *
         * Endereco do objeto do tipo SistemaRestaurante
         */
		MenuCliente(SistemaRestaurante &);

		/**
         * Metodo que vai inicializar o menu para o cliente
         */
		void iniciar();
		
		/**
         * Metodo interno que vai direcionar o sistema a realizar a opcao
		 * escolhida pelo cliente
         */
		void realizarOpcao(int);
		
		/**
         * Metodo que permite o cliente visualizar o cardapio do restaurante
         */
		void verCardapio();
		
		/**
         * Metodo que vai mostrar as opcoes de filtros de ordenacao, solicitando 
		 * ao cliente a escolha de qual dos filtros sera o escolhido para
		 * ordenar o cardapio, e vai retornar um vector, do tipo Prato, que vai
		 * ter o cardapio ordenado da forma escolhida pelo cliente
         */
		vector<Prato> selecionarOrdenacao();
		
		/**
         * Metodo que vai exibir o cardapio ordenado para o cliente, ou seja, 
		 * vai printar o vector formado no método anterior
         */
		void listarCardapio(vector<Prato>);
		
		/**
         * Metodo que vai realizar o pedido presencial, chamando internamente 
		 * outros dois metodos para receber todas as informacoes necessarias 
		 * do cliente
         */
		void realizarPedidoPresencial();
		
		/**
         * Metodo que vai realizar o pedido delivery, chamando internamente 
		 * outros dois metodos para receber todas as informacoes necessarias 
		 * do cliente
         */
		void realizarPedidoDelivery();
		
		/**
         * Metodo que vai coletar os dados do cliente e que retorna um objeto
         * do tipo Cliente
         */
		Cliente coletarDadosCliente();
		
		/**
         * Metodo que vai coletar os dados do/s prato/s pedido/s pelo cliente 
		 * e que retorna um vector do tipo Item
         */
		vector<Item> escolherPratos();
		
		/**
         * Metodo que vai finalizar o menu para o cliente
         */
		void sairMenu();
};
#endif