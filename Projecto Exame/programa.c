/*
* PROJECTO - 2 de julho 2021
* Autor: Sara David Tuma
* Universidade: Católica de Angola
* Curso : Informática
* Ano: 2º
* Disciplina: Análise de algoritmos
* Sitação: A prática nos leva a perfeição, então pratique bastante!

* Programa cliente (Aqui apenas executo as funções)
*/
#include <stdio.h>
#include "editorTexto.h"

/**
* Procedimento : main
* Objectivo : procedimento principal, onde começa a execução do projecto
* Parametro : Nenhum
* Devolve : Nada
* Retorna : 0
*/
int main()
{
	/**
	*	Para executar e so digitar no terminal
	*	./compilar.sh
	*	ou
	*	make
	*/

	//Para limpar a tela (o terminar)
	printf("\33[H\33[2J");

	/*
	* Procedimento : iniciarEditor
	* Objectivo : iniciar o editor de texto
	* Parametro : Nenhum
	* Devolve : Nada
	* Retorna : Nada
	*/
	iniciarEditor();

	

	return 0;
}
