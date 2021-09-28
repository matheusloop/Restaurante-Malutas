#ifndef PEDIDO_H
#define PEDIDO_H

/**
  * Classe responsavel por fazer a base do pedido escolhido pelo cliente
  */
class Pedido{
    
	protected:
        
		vector<Item> refeicoesPedidas;
        Cliente dadosCliente;
        int codigoPedido;

        static int baseCodigo;

    public:
       
        /**
         * Metodo set para armazenar o objeto, do tipo Cliente, que contem
		 * os dados do cliente
         */
	    void setDadosCliente(Cliente);
	    
	    /**
         * Metodo set para armazenar o vector, do tipo Item, que contem 
		 * as refeicoes, ou seja os pratos, escolhidas pelo cliente
         */
        void setRefeicoesPedidas(vector<Item>);

		/**
         * Metodo get para retornar o vector, do tipo Item, que contem 
		 * as refeicoes, ou seja os pratos, escolhidas pelo cliente
         */
        vector<Item> getRefeicoesPedidas()const;
        
        /**
         * Metodo get para retornar o objeto, do tipo Cliente, que contem 
		 * os dados do cliente
         */
		Cliente getDadosCliente() const;
        
		/**
         * Metodo get para retornar o valor, do tipo inteiro, referente ao 
		 * codigo do pedido gerado
         */
		int getCodigoPedido() const;
        
        /**
         * Metodo para incrementar, a cada novo pedido, o valor da variavel 
		 * static baseCodigo
		 * Gerando, assim, um novo valor a cada novo pedido realizado pelo cliente
         */
        static void incrementarBaseCodigo();
};
#endif