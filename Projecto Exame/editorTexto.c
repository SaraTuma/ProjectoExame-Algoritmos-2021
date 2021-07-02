/*
* PROJECTO - 2 de julho 2021
* Autor: Sara David Tuma
* Universidade: Católica de Angola
* Curso : Informática
* Ano: 2º
* Disciplina: Análise de algoritmos
* Sitação: A prática nos leva a perfeição, então pratique bastante!

* Neste arquivo apenas implemento as funções e procedimentos (C)
*/
#include "editorTexto.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
* procedimento : inicializarLista
* Objectivo : inicializar uma lista
* Parametros : lista - a lista declarada
* Devolve : lista inicializada
* Retorna : nada
*/
void inicializarLista (TLista *lista)
{
	lista->nElem=0;
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}

/**
* Função : vaziaLista
* Objectivo : verificar se uma lista esta vazia
* Parametros : lista - a lista declarada
* Devolve : nada
* Retorna : 1 ou 0
*/
int vaziaLista (TLista lista)
{
	return (lista.primeiro==NULL); 
}

/*
Procedimento : executar
Objectivo : imprimir a mensagem do respectivo código de erro na tela
Parametros : o codigo de erro
Devolve : nada
Retorna : nada
*/
void executar ( int cod )
{
	static char * msg[ ] = { "", "Editor vazio (Adicione linhas primeiro)", "Linha invalida",
	"Falta virgula", "Delimitador ocorre somente 2 vezes", "Comandos devem comecar com $",
	"Palavra nao encontrada", "Delimitador ocorre somente 1 vez" ,"posicões invalidas",
	"Falta número","não é comando valido!","Falta o delimitador %","Não há espaço suficiente na frase!",
	"Linha corrente não encontrada!"};
	if(cod==10) printf (" %s\n",  msg[cod] );
	else if(cod!=0){
		printf ("\nERRO: %s\n",  msg[cod] );
	}
		
}

/*
Procedimento : executarImprimir
Objectivo : imprimir a mensagem do respectivo código de erro sobre numeros na tela
Parametros : o codigo de erro e oultimo numero da lista invalido
Devolve : nada
Retorna : nada
*/
void executarImprimir ( int cod , int nelem)
{
	static char * msg[ ] = { "","o ultimo numero do texto igual a ", "Primeiro numero invalido", 
	"Segundo numero invalido","Numeros invalidos"};
	if(cod>0 && cod<=4){
		if(cod==1) printf("\nERRO: %s %d\n", msg[cod],nelem);
		else
			printf ("\nERRO: %s\n",  msg[cod] );
	}
	
}

/**
* Função : verificarNumeros
* Objectivo : verificar se os numeros digitados sao validos,
	remover ou imprimir naquele intervalo.
* Parametros :
	* lista - a lista de atomos
	* a - primeiro numero digitado
	* b - segundo numero digitado
	* n - tamanho da lista
	* op - opcao : 1 para imprimir  e 0 para remover
* Devolve : se op=0, lista com alguns elementos removidos, caso contrario nada
* Retorna : codigo de erro
*/
int verificarNumeros(TLista *lista,int a, int b,int n,int op)
{
	if(a==0) return FIRST_INVALID;
	if(b==0) return SECUND_INVALID;
	if(b>n) return NUMBER_INVALID;
	if(a>b || b<a) return NUMBERS_INVALIDS;
	if(a<=0 || a>n) return FIRST_INVALID;
	if(b<=0 ) return SECUND_INVALID;
	if(op==1)
		imprimirLista(*lista,a,b);
	else{
		if(a==b) removerAtomoChave(lista,a);
		else removerAtomosLista(lista,a,b);
	} 
}

/*
* Procedimento : imprimirLista
* Objectivo : imprimir todas as informacoes de determinado intervalo
* Parametros :
	* lista - a lista de atomos
	* ini - inicio do intervalo
	* fim - fim do intervalo
* Devolve : nada
* Retorna : nada
*/

void imprimirLista(TLista lista, int ini, int fim)
{
	
	printf("\n-----------------------------------");
	
	for (TAtomo *paux = lista.primeiro; paux != NULL; paux = paux->dprox)
	{
		if (paux -> info.chave <= fim && paux -> info.chave >= ini) {
			imprimirInfo(paux->info);
		}
	}
	printf("-------------------------------------\n");
}

/*
* Procedimento : localizarFrase
* Objectivo : imprimir e pintar a frase dada
* Parametros :
	* lista - a lista de atomos
	* frase - uma substring que devemos pintar
* Devolve : nada
* Retorna : nada
*/
void localizarFrase(TLista lista, char * frase)
{
	printf("\n-----------------------------------");
	int pos;
	int cont=0;
	int size = tamanhoString(frase);
	for (TAtomo *paux = lista.primeiro; paux != NULL; paux = paux->dprox)
	{
		//Para imprimir os tracos - ou ->
		if(paux->info.chave==linhaCorrente)
			printf("\n%d --> ",paux->info.chave);
		else
			printf("\n%d - ",paux->info.chave);
		//percorrer cada frase
		for(int i=0;paux->info.frase[i]!='\0';i++){
			cont=0; pos=i;
			//percorrer cada letra da frase
			for(int j=0;j<size; j++,pos++){
				if(paux->info.frase[pos]=='\0')
					break;
				//se for igual vou somando "cont"
				if(paux->info.frase[pos]!=frase[j])
					break;
				else
					cont++;
			}
			//se encontrei a substring completa, vou pintar
			if(cont==size){
				pos=i;
				while (pos<size+i)
				{
					printf("\033[31;1m%c\033[0m",paux->info.frase[pos]);
					pos++;
				}
				i=(i+size)-1;
				//caso contrario vou imprimir o caracter daquela posicao [i]
			}else
				printf("%c",paux->info.frase[i]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}

/*
* Procedimento : arrastarStringFim
* Objectivo : remover caracteres na string dada
* Parametros :
	* str - uma string
	* pos - posicão onde devemos começar a remover
	* size - tamanho da string
* Devolve : uma string alterada
* Retorna : nada
*/
void arrastarStringFim(char * str, int pos,int size){
	while(size>=pos){
		str[pos]=str[pos+1];
		pos++;
	}
}

/*
* Procedimento : arrastarString
* Objectivo : arrastar caracteres para deixar espaco para a nova string
* Parametros :
	* str - uma string
	* pos - posicão onde devemos começar a arrastar
	* size - tamanho da string
* Devolve : uma string alterada
* Retorna : nada
*/
void arrastarString(char * str, int pos,int size){
	while(size>=pos){
		str[size+1]=str[size];
		size--;
	}
}

/*
* Procedimento : afastarCaracteres
* Objectivo : arrastar ou remover caracteres de uma string
* Parametros :
	* str - uma string
	* qtd - quantidade de caracteres
	* ini - posicão de inicio
	* op - opção : 1 arrastar e 2 remover
* Devolve : uma string alterada
* Retorna : nada
*/
void afastarCaracteres(char * str, int qtd, int ini,int op){
	int size = tamanhoString(str);
	//str[size+qtd]='\0';
	int i=1;
	while(i<=qtd){
	
		if(op==1){
			//arrastar e deixar espaco para nova string
			arrastarString(str,ini,size);
			size++;
		}
		if(op==2){
			//remover caracteres
			arrastarStringFim(str,ini,size);
		}	
		
		i++;
	}
	
}

/*
* Função : alterarFrase
* Objectivo : alterar uma substring da linha corrente por uma frase dada
* Parametros :
	* lista - a lista de atomos
	* substring - a substring que devemos alterar
	* frase - uma substring que devemos pintar
* Devolve : frase da linha corrente alterada
* Retorna : um código de erro
*/
int alterarFrase(TLista lista, char * substring, char * frase)
{
	// alterar apenas a linha corrente : esta na descricao do projecto
	int pos;
	int aux=0;
	int cont=0;
	
	int sizeF = tamanhoString(frase);
	int sizeS = tamanhoString(substring);
	TAtomo * paux = buscarAtomo(lista,linhaCorrente);
	if(paux==NULL){
		return NOT_FOUND_LINE;
	} 
	int tam=0;
	int encontrei=0;

	for(int i=0;paux->info.frase[i]!='\0';i++){
			cont=0; pos=i;
			for(int j=0;j<sizeS; j++,pos++){
				//substitui o break - o prof nao gosta dele
				if(paux->info.frase[pos]=='\0')
					break;
				//se for igual vou somando "cont"
				if(paux->info.frase[pos]!=substring[j])
					break;
				else
					cont++;
			}
			//se encontrei a substring completa, vou alterar
			if(cont==sizeS){
				pos=i;
				// o limite da busca e sempre a 2* string
				tam=sizeF+i;
				//antes de substituir devo analizar os tamanhos das strings
                if(sizeF==0)
                    afastarCaracteres(paux->info.frase,sizeS,i,2);
				else if(sizeF>sizeS) 
					afastarCaracteres(paux->info.frase,sizeF-sizeS,sizeS+i,1);
				else if(sizeF<sizeS)
					afastarCaracteres(paux->info.frase,sizeS-sizeF,sizeF+i,2);
				aux=0;
				//onde adiciono a segunda frase
				while (pos<tam)
				{
					paux->info.frase[pos]=frase[aux];
					pos++; aux++;
				}
				// a ideia e pular os caracteres alterados e so
				//verificar os restantes
				//espero que entendam!
				if(sizeF!=0)
					i=(i+sizeF)-1;
				encontrei=1;
			}
	}
	//aqui verifico se encontrei pelo menos uma vez ou nao
	if(encontrei==0) return FRASE_NOTFOUND;
	else return OK;
}

/*
* Função : tamanhoString
* Objectivo : contar os caracteres de uma string
* Parametro : a string que queremos saber o tamanho
* Devolve : nada
* Retorna : tamanho da string
*/
int tamanhoString(char * str){
	int tam=0;
	for (; str[tam] !='\0'; tam++);
	return tam;
}

/*
* Procedimento : imprimirInfo
* Objectivo : imprimir a informação de um atomo
* Parametro : a informação para imprimir
* Devolve : nada
* Retorna : nada
*/
void imprimirInfo(TInfo info)
{
	if(info.chave==linhaCorrente)
		printf("\n\r%d -> %s\n", info.chave, info.frase);
	else	printf("\n%d - %s\n", info.chave, info.frase);
}

/*
* Funcão : buscarAtomo
* Objectivo : procurar o atomo que tem uma deteminada chave
* Parametros :
	* lista - a lista de atomos
	* ch - uma chave
* Devolve : nada
* Retorna : o atomo
*/
TAtomo *buscarAtomo(TLista lista, int ch)
{
	for(TAtomo *paux=lista.primeiro; paux!=NULL; paux=paux->dprox)
		if(paux->info.chave == ch)
			return paux;
	return NULL; 
}

/*
* Procedimento : removerAtomoChave
* Objectivo : remover o atomo que tem uma determinada chave
* Parametros :
	* lista - a lista de atomos
	* chave - uma chave
* Devolve : uma lista alterada
* Retorna : nada
*/
void removerAtomoChave(TLista *lista,int chave)
{
	TAtomo *pdel= buscarAtomo(*lista, chave);
	if(pdel!=NULL){
		if(pdel==lista->primeiro && pdel==lista->ultimo){
			inicializarLista(lista);
		}
		else if(pdel==lista->ultimo){
			lista->ultimo=pdel->eprox;
			lista->ultimo->dprox=NULL;
			
		}else if(pdel==lista->primeiro){
			lista->primeiro=pdel->dprox;
			lista->primeiro->eprox=NULL; 
		}else{
			pdel->dprox->eprox=pdel->eprox;
			pdel->eprox->dprox=pdel->dprox;
		}
		if(pdel->info.chave==linhaCorrente){
			if(pdel->eprox==NULL) linhaCorrente=0;
			else linhaCorrente=pdel->eprox->info.chave;
		}
		free(pdel);
		lista->nElem--;	
		if(lista->nElem<=0) inicializarLista(lista);
		actualizarAtomos(pdel->dprox,1,0);
	}
}

/*
* Função : contarAtomosAteAtomo
* Objectivo : contar atomos entre dois atomos especificos
* Parametros :
	* pdel1 - primeiro atomo
	* pdel2 - segundo atomo
* Devolve : nada
* Retorna : numero de atomos entre eles, incluindo eles
*/
int contarAtomosAteAtomo(TAtomo * pdel1, TAtomo * pdel2){
	int cont=0;
	if(pdel1!=NULL && pdel2!=NULL){
		while(pdel1!=pdel2){
			cont+=1;
			pdel1=pdel1->dprox;
		}
		cont+=1;
	}
	return cont;
}

/*
* Função : verificarLinhaCorrente
* Objectivo : verificar se o atomoda linha corrente,
	esta entre dois atomos especificos
* Parametros :
	* pdel1 - primeiro atomo
	* pdel2 - segundo atomo
* Devolve : nada
* Retorna : 1 ou 0
*/
int verificarLinhaCorrente(TAtomo * pdel1, TAtomo * pdel2){
	if(pdel1!=NULL && pdel2!=NULL){
		while(pdel1!=pdel2){
			if(pdel1->info.chave==linhaCorrente)
				return 1;
			pdel1=pdel1->dprox;
		}
		if(pdel2->info.chave==linhaCorrente)
			return 1;
	}
	return 0;
}

/*
* Procedimento : removerAtomosLista
* Objectivo : remover os atomos que estao entre dois atomos
	especificos, incluindo eles
* Parametros :
	* lista - a lista de atomos
	* chave1 - primeira chave
	* chave2 - segunda chave
* Devolve : lista alterada
* Retorna : nada
*/
void removerAtomosLista(TLista *lista,int chave1,int chave2)
{
	TAtomo *paux=NULL,*pdel1= buscarAtomo(*lista, chave1);
	TAtomo *pdel2= buscarAtomo(*lista, chave2);
	int cont=contarAtomosAteAtomo(pdel1,pdel2);
	actualizarAtomos(pdel2->dprox,cont,0);
	//printf("elementos para remover: %d\n",cont);
	if(pdel1!=NULL && pdel2!=NULL){ 
		paux=pdel1;
		if(pdel1==lista->primeiro && pdel2==lista->ultimo){
			inicializarLista(lista);
		}
		else if(pdel1==lista->primeiro){
			lista->primeiro=pdel2->dprox;
			lista->primeiro->eprox=NULL; 
		} else if(pdel2==lista->ultimo){
			lista->ultimo=pdel1->eprox;
			lista->ultimo->dprox=NULL; 
		}
		else{
			pdel1->eprox->dprox=pdel2->eprox;
			pdel2->dprox->eprox=pdel1->eprox;
		}

		if(verificarLinhaCorrente(pdel1,pdel2)){
			if(pdel1->eprox==NULL) linhaCorrente=0;
			else linhaCorrente=pdel1->eprox->info.chave;
		}
		lista->nElem-=cont;	
		if(lista->nElem<=0) inicializarLista(lista);
		paux=pdel1;
		while(paux!=pdel2){
			pdel1=pdel1->dprox;
			free(paux);
			paux=pdel1;
		}
		free(pdel2);	
	}
}

/*
* Função : inserirAtomoFim
* Objectivo : inserir determinado atomo no fim da lista
* Parametros :
	* lista - a lista de atomos
	* x - a informacao para o atomo
* Devolve : lista alterada
* Retorna : codigo de erro
*/
int inserirAtomoFim(TLista *lista, TInfo x)
{
	TAtomo *pnovo = (TAtomo*)malloc(sizeof(TAtomo)); 
	if (pnovo==NULL)
		return NO_SPACE; 
	pnovo->info = x; 
	pnovo->dprox=NULL; 
	lista->nElem++;
	if(vaziaLista(*lista))
		lista->primeiro = pnovo; 
	else
	{
		pnovo->eprox = lista->ultimo;
		lista->ultimo->dprox = pnovo; 
	}
		
	lista->ultimo = pnovo; 
	pnovo->info.chave=lista->nElem;
	return OK; 
}

/*
* Função : inserirAtomosInicio
* Objectivo : inserir atomos de uma lista no inicio de outra
* Parametros :
	* lista1 - lista destino
	* lista2- lista origem
* Devolve : lista alterada
* Retorna : codigo de erro
*/
int inserirAtomosInicio(TLista *lista1, TLista *lista2){
	if(vaziaLista(*lista2)) return LIST_EMPTY;
	actualizarAtomos(lista1->primeiro,lista2->nElem,1);
	if (vaziaLista(*lista1))
	{
		lista1->primeiro = lista2->primeiro;
		lista1->ultimo = lista2->ultimo;
	}
	else{
		lista1->primeiro->eprox=lista2->ultimo;
		lista2->ultimo->dprox=lista1->primeiro;
		lista1->primeiro=lista2->primeiro;
	}
	lista1->nElem = lista1->nElem + lista2->nElem;
	linhaCorrente=lista2->ultimo->info.chave;
	return OK;
}

/*
* Função : inserirAtomoLinha
* Objectivo : inserir atomos de uma lista em outra, depois de uma determinada chave
* Parametros :
	* lista1 - lista destino
	* lista2- lista origem
	* chave - a chave
* Devolve : lista alterada
* Retorna : codigo de erro
*/
int inserirAtomoLinha(TLista *lista1, TLista *lista2, int chave)
{	if(vaziaLista(*lista2)) return LIST_EMPTY;
	if (vaziaLista(*lista1))
	{
		lista1->primeiro = lista2->primeiro;
		lista1->ultimo = lista2->ultimo;
	}
	else
	{
		TAtomo *p = lista2->primeiro;
		actualizarAtomos(p,linhaCorrente,1);
		TAtomo *prox, *paux = buscarAtomo(*lista1, chave);
		if (paux == NULL)
			return NO_SPACE;
		actualizarAtomos(paux->dprox,lista2->nElem,1);
		prox = paux->dprox;
		if (paux == lista1->ultimo)
		{
			lista1->ultimo->dprox = lista2->primeiro;
			lista2->primeiro->eprox = lista1->ultimo;
			lista1->ultimo = lista2->ultimo;
		}
		else
		{
			paux->dprox = lista2->primeiro;
			lista2->primeiro->eprox = paux;
			lista2->ultimo->dprox = prox;
			prox->eprox = lista2->ultimo;
		}
	}
	lista1->nElem = lista1->nElem + lista2->nElem;
	linhaCorrente=lista2->ultimo->info.chave;
	return OK;
}


/*
* Função : inserirAtomoLinha
* Objectivo : Converter uma string em um numero inteiro
* Parametros :
	* str - a string
* Devolve : nada
* Retorna : número inteiro
*/
int myAtoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
		res = res * 10 + str[i] - '0';
	return sign * res;
}

/*
* Procedimento : lerFrase
* Objectivo : ler uma string com tamanho igual a 80
* Parametros :
	* str - a string
* Devolve : string alterada
* Retorna : nada
*/
void lerFrase(char *str)
{

	//printf("\n");
	/* Ler os dados */
	scanf("%80[^\n]", str);
	/* Limpar o buffer */
	scanf("%*[^\n]");
	scanf("%*c");
	/* Voltar ao passo 1. */
}

/*
* Procedimento : converterMinuscula
* Objectivo : alterar os caracteres da string para minusculos
* Parametros :
	* str - a string
* Devolve : string alterada
* Retorna : nada
*/
void converterMinuscula(char * str){
	int i = 0;
	while (str[i] != '\0') {
		str[i] = tolower(str[i]);
		i++;
	}
}

/*
* Função : verifOperacao
* Objectivo : verificar comando digitado
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
* Devolve : string alterada
* Retorna : 1 ou 0
*/
int verifOperacao(char string1[], char string2[])
{
	char copia[TAM];
	copiarString(string1,copia);
	converterMinuscula(copia);
	removerEspacos(copia);
	int i = 0;
	while (copia[i] != '\0')
	{
		if (copia[i] != string2[i])
			return 0;
		i++;
	}
	return 1;
}

/*
* Procedimento : copiarString
* Objectivo : copiar caracteres de uma string
* Parametros :
	* str1 - a string origem
	* str2 - a string destino
* Devolve : uma string alterada
* Retorna : nada
*/
void copiarString(char * str1,char *str2){
	int i=0,j=0;
	while(str1[i]!='\0'){
		if(str1[i]!=' ')
			str2[j++]=str1[i];
		i++;
	}
	str2[j]='\0';
}

/*
* Procedimento : copiarString
* Objectivo : copiar caracteres de uma string ate determinado caracter
* Parametros :
	* str1 - a string origem
	* str2 - a string destino
	* pos - a posicao do caracter
* Devolve : uma string alterada
* Retorna : nada
*/
void copiarStringCaracter(char * str1,char *str2,int pos){
	int i=0,j=0;
	while(str1[i]!=str1[pos]){
		if(str1[i]!=' ')
			str2[j++]=str1[i];
		i++;
	}
	str2[j]='\0';
}

/*
* Função : verifLocalizarAlterar
* Objectivo : verificar comando se o camando digitado é alterar ou localizar
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
* Devolve : string alterada
* Retorna : 1 ou 0
*/
int verifLocalizarAlterar(char string1[], char string2[],int pos)
{
	char copia[TAM];
	copiarStringCaracter(string1,copia,pos);
	converterMinuscula(copia);
	removerEspacos(copia);
	//imprimirFrase(copia);
	int i = 0;
	if(pos>-1){
		while (copia[i] != copia[pos])
		{
			//printf(" %c ",string1[i]);
			if (copia[i] != string2[i])
				return 0;
			i++;
		}
		return 1;
	}
	else return 0;
}

/*
* Função : verifOperacaoPosicao
* Objectivo : verificar o comando digitado
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
	* pos - a posicao do caracter
* Devolve : string alterada
* Retorna : 1 ou 0
*/
int verifOperacaoPosicao(char string1[], char string2[],int pos)
{
	char copia[TAM];
	copiarStringCaracter(string1,copia,pos);
	converterMinuscula(copia);
	removerEspacos(copia);
	//imprimirFrase(copia);
	int i = 0;
	if(pos>-1){
		while (copia[i] != copia[pos])
		{
			//printf(" %c ",string1[i]);
			if (copia[i] != string2[i])
				return 0;
			i++;
		}
		return 1;
	}
	else return 0;
}

/*
* Função : verifDigitoPos
* Objectivo : verificar se a string tem um digito (um numero)
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : a posição do caracter ou -1
*/
int verifDigitoPos(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{

		//criar funcao is digit

		if( isdigit(string[i]))
			return i;
		i++;
	}
	return -1;
}

/*
* Função : verifDigito
* Objectivo : verificar se a string tem um digito (um numero)
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : 1 ou 0
*/
int verifDigito(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		if( !isdigit(string[i]))
			return 0;
		i++;
	}
	return 1;
}

/*
* Função : verifVirgula
* Objectivo : verificar se a string tem uma virgula
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : 1 ou 0
*/
int verifVirgula(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ',')
			return 1;
		i++;
	}
	return 0;
}

/*
* Função : verifPercentagem
* Objectivo : verificar se a string tem uma percentagem
* Parametros :
	* i - posicao de inicio
	* string - a string
* Devolve : nada
* Retorna : a posição ou -1
*/
int verifPercentagem(int i,char string[])
{
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			return i;
		i++;
	}
	return -1;
}

/*
* Procedimento : removerEspacos
* Objectivo : remover espaços em branco na string
* Parametros :
	* str - a string
* Devolve : uma string alterada
* Retorna : nada
*/
void removerEspacos(char *str){ 
    int count=0,i;
    for(i=0;str[i];i++){
        if(str[i]!=' '){
            str[count++]=str[i];
        }
    }
    str[count]=0;
} 

/*
* Função : guardarNum
* Objectivo : guardar uma string que tem um numero, ate um determinado caracter
* Parametros :
	* i - posicao de inicio
	* car - o caracter
	* string - a string origem
	* str2 - a string destino
* Devolve : uma string alterada
* Retorna : a posição do caracter mais 1
*/
int guardarNum(int ini, char car,char str[], char str2[])
{
	int i = ini;
	int j = 0;
	for (; str[i] != car ; i++)
	{
			str2[j] = str[i];
			j++;
		//printf(" %c ",str[i]);
	}
	str2[j] = '\0';
	return i+1 ;
}

/*
* Procedimento : actualizarChave
* Objectivo : actualizar o valore da chave de um determinado atomo
* Parametros :
	* paux - o atomo
	* qtd - a quantidade
	* op - opção 1 adicionar ou remover
* Devolve : chave alterada
* Retorna : nada
*/
void actualizarChave(TAtomo *paux,int qtd,int op)
{
	if(op==1){
		if(paux->info.chave==linhaCorrente)
			linhaCorrente+=qtd;
		paux->info.chave+=qtd;
	}
	else{
		if(paux->info.chave==linhaCorrente)
			linhaCorrente-=qtd;
		paux->info.chave-=qtd;
	}
}

/*
* Procedimento : actualizarAtomos
* Objectivo : actualizar os valores das chaves
* Parametros :
	* paux - o atomo de inicio
	* qtd - a quantidade
	* op - opção 1 adicionar ou remover
* Devolve : chaves alteradas
* Retorna : nada
*/
void actualizarAtomos(TAtomo *paux,int qtd,int op)
{
	if(paux!=NULL){
		for(;paux!=NULL;paux=paux->dprox)
			actualizarChave(paux,qtd,op);
	}
	
}

/*
* Fração : executarComandoPercentagens
* Objectivo : verificar e executar comando alterar ou localizar
* Parametros :
	* lista - a lista de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int executarComandoPercentagens(TLista *lista,char *frase){
	int ler=0;
	char operacao[TAM],palavra1[TAM],palavra2[TAM];
	int num1=0,num2=0;
	int percentagem = verifPercentagem(0,frase);
	
	if(verifLocalizarAlterar(frase,"$localizar",percentagem))
	{
		if(vaziaLista(*lista)) return LIST_EMPTY;
		if(percentagem==-1) return FALTA_PERCENTAGEM;
				percentagem= guardarNum(percentagem+1,'\0',frase, operacao);	
				printf("\n Frase : %s",operacao);
				int tam=tamanhoString(operacao);
				if(tam==0) return FRASE_NOTFOUND;
				if(tam>TAM) return NO_SPACE;
				else localizarFrase(*lista,operacao);
				return OK;
					
	}
	else if(verifLocalizarAlterar(frase,"$alterar",percentagem))
	{
		if(vaziaLista(*lista)) return LIST_EMPTY;
		if(percentagem==-1) return FALTA_PERCENTAGEM;
		percentagem= guardarNum(percentagem+1,'%',frase, palavra1);	
		if(verifPercentagem(percentagem,frase)==-1) return OCORRE_2V;
		percentagem= guardarNum(percentagem,'%',frase, palavra2);	
		int sizeS = tamanhoString(palavra1);
		int sizeF = tamanhoString(palavra2);
		if(sizeS==0) return FRASE_NOTFOUND;
		else if(sizeF>sizeS){
			
			if((TAM-sizeS)+sizeF < TAM)
				return NO_SPACE;
			else{
				return alterarFrase(*lista,palavra1,palavra2);
				}
						
		}else
			return alterarFrase(*lista,palavra1,palavra2);	
	}
	else
	return COMANDO_INVALIDO;
		
}

/*
* Fração : executarComandoDigitos
* Objectivo : verificar e executar comandos que tem numeros
* Parametros :
	* lista - a lista de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int executarComandoDigitos(TLista *lista,char *frase){
	int ler=0;
	char operacao[TAM];
	int num1=0,num2=0;
	int pos = verifDigitoPos(frase);
	if(verifOperacaoPosicao(frase,"$linha",pos))
	{
		if(vaziaLista(*lista)) return LIST_EMPTY;
		if(pos==-1) return FALTA_NUMERO;
		pos= guardarNum(pos,'\0',frase, operacao);	
		if(!verifDigito(operacao)) return INVALIDS_POSSISIONS;		
		pos = myAtoi(operacao);
		if(lista->nElem>=pos && pos>=0)
		{
			linhaCorrente=pos;
			return OK;
		}
		else{
			return LINE_NOTFOUND;
		}
					
	}
	else if(verifOperacaoPosicao(frase,"$imprimir",pos)){
		if(vaziaLista(*lista)) return LIST_EMPTY;
		if(pos==-1) return FALTA_NUMERO;
		if(verifVirgula(frase)){
			pos= guardarNum(pos,',',frase, operacao);
			// VERIFICAR SE DIGITOU ALGUMA LETRA ENTRE OS NUMEROS
			if(!verifDigito(operacao)) return INVALIDS_POSSISIONS;
			num1 = myAtoi(operacao);
			pos= guardarNum(pos,'\0',frase, operacao);
			if(!verifDigito(operacao)) return INVALIDS_POSSISIONS;
			num2 = myAtoi(operacao);
			//printf("pos1: %d -- pos2: %d\n",num1,num2);
			executarImprimir(verificarNumeros(lista,num1,num2,lista->nElem,1),lista->nElem);
			return OK;
					
		}else return FALTA_VIRGULA;
				
	}
	else if(verifOperacaoPosicao(frase,"$remover",pos))
			{
				if(vaziaLista(*lista)) return LIST_EMPTY;
				if(pos==-1) return FALTA_NUMERO;
				if(verifVirgula(frase)){
					pos= guardarNum(pos,',',frase, operacao);
					if(!verifDigito(operacao)) return INVALIDS_POSSISIONS;
					num1 = myAtoi(operacao);
					pos= guardarNum(pos,'\0',frase, operacao);
					if(!verifDigito(operacao)) return INVALIDS_POSSISIONS;
					num2 = myAtoi(operacao);
					//printf("pos1: %d -- pos2: %d\n",num1,num2);
					executarImprimir(verificarNumeros(lista,num1,num2,lista->nElem,0),lista->nElem);
					return OK;
					
				}	
				else  return FALTA_VIRGULA;	
				
			}else{
				printf("\nERRO: \"%s\"",frase);
				return COMANDO_ERRADO;
			}
}

/*
* Fração : verificarComandos
* Objectivo : verificar e executar comandos
* Parametros :
	* lista - a lista de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int verificarComandos(TLista *lista,char *frase){
	int pos = verifDigitoPos(frase);
	int percentagem = verifPercentagem(0,frase);
	return executarComandoDigitos(lista,frase);	
}

/*
* Procedimento : iniciarEditor
* Objectivo : iniciar o editor de texto
* Parametro : nenhum
* Devolve : nada
* Retorna : nada
*/
void iniciarEditor(){

	TLista lista, nova; 

	inicializarLista(&lista);
	inicializarLista(&nova);

	int run = 1, ler = 0, cont = 0;
	char posicao[TAM];
	TInfo x;
	int comando =0;

	while (run){
		//printf("linha corrente: %d\n",linhaCorrente);
		memset(x.frase,'\0',80);
		lerFrase(x.frase);

		if(x.frase[0] == '$'){
			if(ler){
				if(linhaCorrente==0){
					if(inserirAtomosInicio(&lista,&nova)==0){
						inicializarLista(&nova);
						ler=0;
					}
				}
				else if (inserirAtomoLinha(&lista, &nova,linhaCorrente) == 0)
				{
					inicializarLista(&nova);
					ler=0;
				}
			}
			comando = executarComandoPercentagens(&lista,x.frase);
			if(comando==COMANDO_INVALIDO){
				removerEspacos(x.frase);
				if (verifOperacao(x.frase, "$inserir"))
				{
					ler = 1;
				}
				else if (verifOperacao(x.frase, "$fim")){
					run = 0;
				}else if(verifOperacao(x.frase,"$clear")){
					printf("\33[H\33[2J");
				}
				else if (verifOperacao(x.frase, "$ultimo"))
				{
					if(!vaziaLista(lista))
						printf("%d\n", lista.ultimo->info.chave);
				}
				else{
						executar(verificarComandos(&lista,x.frase));
				}
			}
			else if(comando!=OK)
				executar(comando);
			
		}
		else if (ler == 1){
			
			if(inserirAtomoFim(&nova, x) != 0)
				printf("ERRO ao guardar");
		}
		else
		executar(COMANDO_INVALIDO);
	}
	
}