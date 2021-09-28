#ifndef SISTEMARESTAURANTE_H
#define SISTEMARESTAURANTE_H

/**
  * Classe responsavel por ser o sistema do restaurante, exercendo a funcao
  * de ser o "coracao" de todo o projeto
  */
class SistemaRestaurante{

	private:

		vector<Prato> cardapio;
		vector<PedidoPresencial> pedidosPresenciais;
		vector<PedidoDelivery> pedidosDelivery;
		vector<PedidoPresencial> historicoPresencial;
		vector<PedidoDelivery> historicoDelivery;

		float dinheiroCaixa;
		const string senhaFuncionario;

	public:

		/**
         * Construtor da classe SistemaRestaurante
         */
		SistemaRestaurante();

		/**
         * Metodo set para armazenar o dinheiro do caixa do restaurante
         */
		void setDinheiroCaixa(float);
		
		/**
         * Metodo get para retornar o valor, do tipo floar, referente ao 
		 * dinheiro do caixa do restaurante
         */
		float getDinheiroCaixa() const;
		
		/**
         * Metodo get para retornar o vector, do tipo Prato, referente ao 
		 * aos pratos existentes no cardapio do restaurante
         */
		vector<Prato> getCardapio() const;
		
		/**
         * Metodo get para retornar o vector, do tipo PedidoPresencial, 
		 * referente aos pedidos presenciais existentes no restaurante
         */
		vector<PedidoPresencial> getPedidosPresenciais() const;
		
		/**
         * Metodo get para retornar o vector, do tipo PedidoDelivery, 
		 * referente aos pedidos delivery existentes no restaurante
         */
		vector<PedidoDelivery> getPedidosDelivery() const;
		
		/**
         * Metodo get para retornar o vector, do tipo PedidoPresencial, 
		 * referente ao historico dos pedidos presenciais atendidos pelo
		 * restaurante
         */
		vector<PedidoPresencial> getHistoricoPresencial() const;
		
		/**
         * Metodo get para retornar o vector, do tipo PedidoDelivery, 
		 * referente ao historico dos pedidos delivery atendidos pelo
		 * restaurante
         */
		vector<PedidoDelivery> getHistoricoDelivery() const;

		/**
         * Metodo para adicionar um prato no cardapio do restaurante, que vai
         * retornar a informacao, do tipo bool, referente a sua existencia ou nao
         */
		bool adicionarPrato(Prato);
		
		/**
         * Metodo para remover um prato do cardapio do restaurante, que vai
         * retornar a informacao, do tipo bool, referente a sua existencia ou nao
         */
		bool removerPrato(string);
		
		/**
         * Metodo para atualizar um prato no cardapio do restaurante, que vai
         * retornar a informacao, do tipo bool, referente a sua existencia ou nao
         */
		bool atualizarPrato(Prato, string);
		
		/**
         * Metodo que sera usado durante a ordenacao do cardapio, que vai
         * ordenar os pratos de acordo com o filtro escolhido. Esse metodo vai
         * justamente retornar um vector, do tipo Prato, com os pratos ordenados
         */
		vector<Prato> ordenarCardapio(string);

		/**
         * Metodo para adicionar um pedido presencial
         */
		void adicionarPedidoPresencial(PedidoPresencial);
		
		/**
         * Metodo para atender um pedido presencial, que vai retornar a 
		 * infomarcao, do tipo bool, sobre a existencia ou nao desse pedido no 
		 * sistema do restaurante
         * Lembrando que quando o pedido for atendido, sera adicionado ao
         * historico dos pedidos presenciais
         */
		bool atenderPedidoPresencial();
		
		/**
         * Metodo para remover um pedido presencial, que vai retornar a
         * informacao, do tipo bool, sobre a existencia ou nao desse pedido no 
		 * sistema do restaurante
         */
		bool removerPedidoPresencial(int);
		
		/**
         * Metodo para adicionar um pedido delivery
         */
		void adicionarPedidoDelivery(PedidoDelivery);
		
		/**
         * Metodo para atender um pedido delivery, que vai retornar a
         * informacao, do tipo bool, sobre a existencia ou nao desse pedido no 
		 * sistema do restaurante
         * Lembrando que quando o pedido for atendido, sera adicionado ao
         * historico dos pedidos delivery
         */
		bool atenderPedidoDelivery();
		
		/**
         * Metodo para remover um pedido delivery, que vai retornar a
         * informacao, do tipo bool, sobre a existencia ou nao desse pedido no 
		 * sistema do restaurante
         */
		bool removerPedidoDelivery(int);

		/**
         * Metodo que vai retornar o valor, do tipo inteiro, referente a posicao
         * do prato passado
         */
		int posicaoPrato(string);
		
		/**
         * Metodo que vai retornar o valor, do tipo inteiro, referente a posicao
         * do pedido presencial passado
         */
		int posicaoPedidoPresencial(int);
		
		/**
         * Metodo que vai retornar o valor, do tipo inteiro, referente a posicao
         * do pedido delivery passado
         */
		int posicaoPedidoDelivery(int);

		/**
         * Metodo que vai abrir o arquivo do cardapio
         */
		void abrirCardapio();
		
		/**
         * Metodo que vai salvar o arquivo do cardapio
         */
		void salvarCardapio();

		/**
         * Metodo que vai verificar se a senha inserida pelo funcionario esta
         * correta ou nao e vai retornar essa informacao, do tipo bool
         */
		bool verificarSenha(string);

		/**
         * Destrutor da classe SistemaRestaurante
         */
		~SistemaRestaurante();
};
#endif
