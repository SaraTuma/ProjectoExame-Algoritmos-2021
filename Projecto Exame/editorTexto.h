/*
* PROJECTO - 2 de julho 2021
* Autor: Sara David Tuma
* Universidade: Católica de Angola
* Curso : Informática
* Ano: 2º
* Disciplina: Análise de algoritmos
* Sitação: A prática nos leva a perfeição, então pratique bastante!

* Este arquivo é como uma interface, apenas declaro tudo o que usarei no programa
*/

#ifndef LISTALIG_H
#define LISTALIG_H



// Códigos de Erro

#define OK 		0
#define LIST_EMPTY 1
#define LINE_NOTFOUND 2
#define FALTA_VIRGULA 3
#define OCORRE_2V 4
#define COMANDO_INVALIDO 5
#define FRASE_NOTFOUND 6
#define OCORRE_1V 7
#define INVALIDS_POSSISIONS 8
#define FALTA_NUMERO 9
#define COMANDO_ERRADO 10
#define FALTA_PERCENTAGEM 11
#define NO_SPACE 12
#define NOT_FOUND_LINE 13


//verificar numeros
#define NUMBERS_OK 0
#define NUMBER_INVALID 1
#define FIRST_INVALID 2
#define SECUND_INVALID 3
#define NUMBERS_INVALIDS 4

#define TAM 80

// Tipo de Dados a ser exportados
// Estrutura de Dados
typedef struct
{
	int chave;
	char frase[TAM];
}TInfo;


typedef struct Atomo
{
	TInfo info;
	struct Atomo *eprox;
	struct Atomo *dprox;
}TAtomo;

typedef struct
{
	int nElem;
	TAtomo * primeiro;
	TAtomo * ultimo;
}TLista;

//nao usei este enumerador
typedef enum { FALSE= 0, TRUE= 1 } Boolean;

//declarando a variavel global para a linha corrente
int static linhaCorrente = 0;

// Funções exportadas
// Todas os metodos do programa
 
void executar ( int cod );
void executarImprimir ( int cod , int nelem);
void inicializarLista (TLista *lista);
int vaziaLista (TLista lista); 
int inserirAtomoFim(TLista *lista, TInfo x); 
int inserirAtomoInicio(TLista *lista, TInfo x);
int inserirAtomoLinha(TLista *lista1, TLista *lista2, int chave);
void imprimirLista (TLista lista, int ini, int fim); 
void imprimir(TLista lista);
void imprimirInfo(TInfo info); 
int separar(TLista *lista1, TLista *lista2, int ch); 
TAtomo *buscarAtomo(TLista lista, int ch);
void testeBusca(TLista lista);

int myAtoi(char *str);

void lerFrase(char *str);

int verifOperacao(char string1[], char string2[]);

int verifOperacaoPosicao(char * string1, char string2[],int pos);

int guardarNum(int ini, char car,char str[], char str2[]);

void actualizarChave(TAtomo *paux,int qtd,int op);

void actualizarAtomos(TAtomo *paux,int qtd,int op);

void iniciarEditor();

int inserirAtomosInicio(TLista *lista1, TLista *lista2);

int verificarComandos(TLista *lista,char *frase);

int verificarNumeros(TLista *lista,int a, int b,int n,int op);

int verifVirgula(char string[]);

int verifDigito(char string[]);

int verifDigitoPos(char string[]);

int verifPercentagem(int i,char string[]);

void removerEspacos(char *str);

void removerAtomoChave(TLista *lista,int chave);

void removerAtomosLista(TLista *lista,int chave1,int chave2);

int contarAtomosAteAtomo(TAtomo * pdel1, TAtomo * pdel2);

void localizarFrase(TLista lista, char * frase);

int alterarFrase(TLista lista, char * substring, char * frase);

int executarComandoPercentagens(TLista *lista,char *frase);

int executarComandoDigitos(TLista *lista,char *frase);

int tamanhoString(char * str);

void removerCaracteres(char * str, int pos,int size);

void arrastarString(char * str, int pos,int size);

void copiarString(char * str1,char *str2);

void copiarStringCaracter(char * str1,char *str2,int pos);

void converterMinuscula(char * str);

#endif