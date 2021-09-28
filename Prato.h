#ifndef PRATO_H
#define PRATO_H

/**
  * Classe responsavel por armazenar todas as informacoes do prato disponivel
  * no restaurante que serao inseridas pelo funcionario
  */
class Prato{
	
	private:
		
		string nomePrato;
		string inforPrato;
		int tempoPreparo;
		string tipoPrato;
		bool vegetariano;
		float preco;
		string codigoPrato;

	public:
		
		/**
         * Construtor da classe Prato
         *
         * Nome do prato
         * Informacoes adicionais do prato
         * Tempo de preparo do prato
         * Tipo do prato
         * Se eh vegetariano
         * Preco do prato
         * Codigo do prato
         */
		Prato(string="", string="", int=0, string="",bool=false, float=0, string = "");
		
		/**
         * Metodo set para armazenar o nome prato disponível no restaurante
         */
		void setNomePrato(string);
		
		/**
         * Metodo set para armazenar as informacoes adicionais do prato 
		 * disponível no restaurante
         */
		void setInforPrato(string);
		
		/**
         * Metodo set para armazenar o tempo de preparo prato disponível no restaurante
         */
		void setTempoPreparo(int);
		
		/**
         * Metodo set para armazenar o tipo do prato disponível no restaurante
         */
		void setTipoPrato(string);
		
		/**
         * Metodo set para armazenar a informacao de o prato, disponível no 
		 * restaurante, ser vegetariano ou nao
         */
		void setVegetariano(bool);
		
		/**
         * Metodo set para armazenar o preco do prato disponível no restaurante
         */
		void setPreco(float);
		
		/**
         * Metodo set para armazenar o codigo do prato disponível no restaurante
         */
		void setCodigoPrato(string);

		/**
         * Metodo get para retornar a informacao, do tipo string, referente ao 
		 * nome do prato disponivel no restaurante
         */
		string getNomePrato() const;
		
		/**
         * Metodo get para retornar a informacao, do tipo string, referente aos 
		 * demais dados do prato disponivel no restaurante
         */
		string getInforPrato() const;
		
		/**
         * Metodo get para retornar o valor, do tipo inteiro, referente ao 
		 * tempo de preparo do prato disponivel no restaurante
         */
		int getTempoPreparo() const;
		
		/**
         * Metodo get para retornar a informacao, do tipo string, referente ao 
		 * tipo do prato disponivel no restaurante
         */
		string getTipoPrato() const;
		
		/**
         * Metodo get para retornar a informacao, do tipo bool, referente ao 
		 * prato disponivel no restaurante ser vegetariano ou nao
         */
		bool getVegetariano() const;
		
		/**
         * Metodo get para retornar o valor, do tipo float, referente ao 
		 * preco do prato disponivel no restaurante
         */
		float getPreco() const;
		
		/**
         * Metodo get para retornar a informacao, do tipo string, referente ao 
		 * codigo do prato disponivel no restaurante
         */
		string getCodigoPrato() const;
};
#endif