#ifndef PEDIDODELIVERY_H
#define PEDIDODELIVERY_H

/**
  * Classe responsavel por realizar o pedido no formato delivery
  */
class PedidoDelivery: public Pedido{
    
	private:
        
		string endereco;

        int tempoEntrega;// [min]
        float precoEntrega; //[R$]

    public:
        
        /**
         * Construtor da classe PedidoDelivery
         *
         * Endereco do cliente
         * Objeto do tipo Cliente
         * Tempo de entrega
         * Preco da entrega
         */
		PedidoDelivery(string, Cliente, int, float);

		/**
         * Metodo set para armazenar o endereco do cliente
         */
        void setEndereco(string);
        
        /**
         * Metodo set para armazenar o tempo de entrega do pedido delivery
         */
        void setTempoEntrega(int);
        
        /**
         * Metodo set para armazenar o preco da entrega do pedido delivery
         */
        void setPrecoEntrega(float);

		/**
         * Metodo get para retornar a informacao, do tipo string, referente 
		 * ao endereco do cliente
         */
        string getEndereco() const;
        
		/**
         * Metodo get para retornar o valor, do tipo inteiro, referente 
		 * ao tempo de entrega do pedido delivery
         */
		int getTempoEntrega() const;
        
		/**
         * Metodo get para retornar o valor, do tipo float, referente 
		 * ao preco da entrega do pedido delivery
         */
		float getPrecoEntrega() const;

		/**
         * Metodo para retornar o valor, do tipo inteiro, referente ao calculo
		 * do tempo total do pedido delivery
         */
        int calcularTempoTotal();
        
        /**
         * Metodo para retornar o valor, do tipo float, referente ao calor
		 * do preco total do pedido delivery, levando em consideracao o valor
		 * do prato, a quantidade e, também, o valor da entrega
         */
        float calcularPrecoTotalDelivery();
};
#endif