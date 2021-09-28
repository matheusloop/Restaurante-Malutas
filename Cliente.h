#ifndef CLIENTE_H
#define CLIENTE_H

/**
  * Classe responsavel por armazenar os dados do cliente
  */
class Cliente{

	private:
		
		string nome;
		string cpf;
		string celular;

	public:
		
		/**
         * Construtor da classe Cliente
         *
         * Nome do cliente
         * CPF do cliente
         * Celular do cliente
         */
        Cliente(string = "", string = "", string = " ");

		/**
         * Metodo set para armazenar o nome do cliente
         */
		void setNome(string);
		
		/**
         * Metodo set para armazenar o CPF do cliente
         */
		void setCPF(string);
		
		/**
         * Metodo set para armazenar o celular do cliente
         */
		void setCelular(string);

        /**
         * Metodo get para retornar a string referente ao nome do cliente
         */
		string getNome()const;
		
		/**
         * Metodo get para retornar a string referente ao CPF do cliente
         */
		string getCPF()const;
		
		/**
         * Metodo get para retornar a string referente ao celular do cliente
         */
		string getCelular()const;
 };
 #endif