#ifndef MENUFUNCIONARIO_H
#define MENUFUNCIONARIO_H

/**
  * Classe responsavel por fazer toda a interecao com o funcionario
  */
class MenuFuncionario{
	
	private:
		
		SistemaRestaurante& restaurante;	
	   	
	public:
		
		/**
         * Construtor da classe MenuFuncionario
         *
         * Endereco do objeto do tipo SistemaRestaurante
         */
		MenuFuncionario(SistemaRestaurante &);
		
		/**
         * Metodo que vai inicializar o menu para o funcionario
         */
		void iniciar();
		
		/**
         * Metodo interno que vai direcionar o sistema a realizar a opcao
		 * escolhida pelo funcionario
         */
		void realizarOpcaoFuncionario(int);
		
		/**
         * Metodo que vai listar o cardapio do restaurante para o funcionario
         */
		void listarCardapio();
		
		/**
         * Metodo que permite o funcionario adicionar um prato no cardapio
         * do restaurante
         */
		void adicionarPrato();
		
		/**
         * Metodo que permite o funcionario remover um prato do cardapio
         * do restaurante
         */
		void removerPrato();
		
		/**
         * Metodo que permite o funcionario atualizar um prato no cardapio
         * do restaurante
         */
		void atualizarPrato();
		
		/**
         * Metodo responsavel por coletar todos dados do prato existente no 
		 * cardapio do restaurante, que serao inseridos pelo funcionario, e
		 * retornar um objeto do tipo Prato
         */
		Prato coletarDadosPrato();
		
		/**
         * Metodo para listar todos os pratos presentes em um pedido
         */
		void listarPratosPedidos(vector<Item>) const;
		
		/**
         * Metodo para listar todos os pedidos presenciais existentes
         */
		void listarPedidosPresenciais();
		
		/**
         * Metodo para atender a um pedido presencial existente
         */
		void atenderPedidoPresencial();
		
		/**
         * Metodo para cancelar um pedido presencial existente
         */
		void cancelarPedidoPresencial();
		
		/**
         * Metodo para listar todos os pedidos delivery existentes
         */
		void listarPedidosDelivery();
		
		/**
         * Metodo para atender a um pedido delivery existente
         */
		void atenderPedidoDelivery();
		
		/**
         * Metodo para cancelar um pedido delivery existente
         */
		void cancelarPedidoDelivery();
		
		/**
         * Metodo para mostrar ao usuario o historico de pedidos
         */
		void mostrarHistorico();
		
		/**
         * Metodo para verificar a quantidade de dinheiro que tem no caixa
         * do restaurante
         */
		void verificarDinheiroCaixa();
		/**
         * Metodo que vai fechar o menu para o funcionario
         */
		void sairMenu();
};
#endif