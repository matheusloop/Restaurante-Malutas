#ifndef PEDIDOPRESENCIAL_H
#define PEDIDOPRESENCIAL_H

/**
  * Classe responsavel por realizar o pedido no formato presencial
  */
class PedidoPresencial: public Pedido{

	private:

		int numMesa;
		float gorjetaGarcom;

	public:

		/**
         * Construtor da classe PedidoDelivery
         *
         * Objeto do tipo Cliente
         * Numero da mesa do cliente
         * Gorjeta que vai ser dada ao garcom
         */
		PedidoPresencial(Cliente, int = 0, float = 0.0);

		/**
         * Metodo set para armazenar o numero da mesa do cliente
         */
		void setNumMesa(int);
		
		/**
         * Metodo set para armazenar a gorjeta que vai ser dada ao garcom
         * pelo cliente
         */
		void setGorjetaGarcom(float);

		/**
         * Metodo get para retornar o numero, do tipo inteiro, referente a 
		 * mesa do cliente
         */
		int getNumMesa()const;
		
		/**
         * Metodo get para retornar o valor, do tipo inteiro, referente a 
		 * gorjeta que vai ser dada ao garcom pelo cliente
         */
		float getGorjetaGarcom()const;

		/**
         * Metodo para retornar o valor, do tipo float, referente ao calculo
		 * do preco total do pedido presencial, levando em consideracao o valor
		 * do prato, a quantidade e, também, o valor da gorjeta
         */
		float calculaPrecoTotalPresencial();

		/**
         * Metodo para retornar o valor, do tipo inteiro, referente ao calculo
		 * do tempo total do pedido presencial
         */
		int calculaTempoTotal();
};
#endif