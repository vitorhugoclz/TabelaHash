/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"funcoes_hashing.h"
#include<stdio.h>
#include<string.h>

/**
 * Gera a posicao a ser gravada na hash usando o metodo da divisao.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_divisao(int chave, int TABLE_SIZE) {
	if (chave < 0)
		chave *= -1;
	return chave % TABLE_SIZE;
}

/**
 * Gera a posicao a ser gravada na hash usando o metodo da multiplicacao.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_multiplicacao(int chave, int TABLE_SIZE) {
	if (chave < 0)
		chave *= -1;
	double A = 0.7834729723;
	double val = chave * A;
	val = val - (int) val;
	return (int) (val * TABLE_SIZE);
}

/**
 * Gera a posicao a ser gravada na hash usando o metodo da dobra.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_dobra(int chave, int TABLE_SIZE) {
	if (chave < 0)
		chave *= -1;
	if (chave < TABLE_SIZE)
		return chave;

	int numeros[10];
	int inicio = 0;
	int fim = 0;
	int div = chave;
	do {
		int resto = div % 10;
		numeros[inicio] = resto;
		if (numeros[inicio])
			fim = inicio;
		inicio++;
		div = div / 10;
	} while (inicio < 10);
	inicio = 0;

	while (chave > TABLE_SIZE) {
		while (fim > inicio) {
			numeros[inicio] = (numeros[inicio] + numeros[fim]) % 10;
			numeros[fim] = 0;
			inicio++;
			fim--;
		}
		inicio = 0;
		chave = 0;
		int fator = 1;
		while (inicio <= fim) {
			chave += numeros[inicio] * fator;
			fator *= 10;
			inicio++;
		}
		inicio = 0;
	}

	return chave;
}

/**
 * Gera a partir da string um valor inteiro, de modo a poder
 * ser usada em alguma das outras funcoes de hashing.
 * @param str string que se deseja obter a chave.
 * @return valor inteiro obtido à partir da string passada.
 */
int valor_string(char * str){
	int i, valor = 7;
	int tam = strlen(str);
	for(i = 0; i < tam; i++){
		valor = 31 * valor + (int) str[i];
	}
	return valor;
}
