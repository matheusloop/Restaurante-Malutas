#ifndef ITEM_H
#define ITEM_H

/**
  * Classe responsavel por armazenar os dados do prato escolhido pelo cliente
  */
class Item{

	private:
		
		Prato refeicao;
		int quantidade;

	public:

		/**
         * Construtor da classe Item
         *
         * Objeto do tipo Prato
         * Quantidade do prato escolhido
         */
		Item(Prato, int = 0);

		/**
         * Metodo set para armazenar o prato escolhido pelo cliente
         */
		void setRefeicao(Prato);
		
		/**
         * Metodo set para armazenar a quantidade do prato escolhido pelo cliente
         */
		void setQuantidade(int);

        /**
         * Metodo get para retornar o objeto, do tipo Prato, referente ao 
		 * prato escolhido
         */
		Prato getRefeicao()const;
		
		/**
         * Metodo get para retornar o valor, do tipo inteiro, equivalente 
		 * a quantidade do prato escolhido
         */
		int getQuantidade()const;

		/**
         * Metodo para retornar o valor, do tipo inteiro, equivalente 
		 * ao tempo de preparo do prato escolhido
         */
		int calcularTempoPreparo();
		
		/**
         * Metodo para retornar o valor, do tipo float, equivalente 
		 * ao valor do prato escolhido levando em consideracao a quantidade
		 * do prato pedida pelo cliente
         */
		float calcularValorProduto();
 };
#endif