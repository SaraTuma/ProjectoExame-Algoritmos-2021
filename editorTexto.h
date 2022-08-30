/*
* PROJECTO - 3 de julho 2021
* Autor: Sara David Tuma
* Universidade: Católica de Angola
* Curso : Informática
* Ano: 2º
* Disciplina: Análise de algoritmos
* Professor : Manuel Menezes

* Sitação: A prática nos leva a perfeição, então pratique bastante!

* Este arquivo é como uma interface, apenas declaro tudo o que usarei no programa
*/

#ifndef EDITOR_H
#define EDITOR_H

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
#define FILE_NOTFOUND 14


//verificar numeros
#define NUMBERS_OK 0
#define NUMBER_INVALID 1
#define FIRST_INVALID 2
#define SECUND_INVALID 3
#define NUMBERS_INVALIDS 4

#define TAM 1000

//nao usei este enumerador
typedef enum { FALSE= 0, TRUE= 1 } Boolean;

// Tipo de Dados a ser exportados

// Estrutura da informacao
typedef struct
{
	int chave;
	char * frase;
}TInfo;

// Estrutura do atomo da lista
typedef struct Atomo
{
	TInfo info;
	struct Atomo *eprox;
	struct Atomo *dprox;
}TAtomo;

// Estrutura do atomo da pilha
typedef struct PAtomo
{
	TInfo info;
	Boolean remover;
	struct PAtomo * prox;
}PAtomo;

// Estrutura da lista
typedef struct
{
	int nElem;
	TAtomo * primeiro;
	TAtomo * ultimo;
}TLista;

// Estrutura da pilha
typedef struct
{
	int nElem;
	PAtomo * ptopo;
}TPilha;

//declarando a variavel global para a linha corrente
int static linhaCorrente = 0;



/**
* Procedimento : inicializarLista
* Objectivo : inicializar uma lista
* Parametros : lista - a lista declarada
* Devolve : lista inicializada
* Retorna : nada
*/
void inicializarLista (TLista *lista);
/**
* Procedimento : inicializarPilha
* Objectivo : inicializar uma pilha
* Parametros : pilha - a pilha declarada
* Devolve : pilha inicializada
* Retorna : nada
*/
void inicializarPilha (TPilha *pilha);
/**
* Função : vaziaLista
* Objectivo : verificar se uma lista esta vazia
* Parametros : lista - a lista declarada
* Devolve : nada
* Retorna : TRUE  ou FALSE
*/
Boolean vaziaLista (TLista lista); 
/**
* Função : vaziaPilha
* Objectivo : verificar se uma pilha esta vazia
* Parametros : pilha - a pilha declarada
* Devolve : nada
* Retorna :  TRUE  ou FALSE
*/
Boolean vaziaPilha (TPilha pilha);
/**
* Função : empilhar
* Objectivo : Empilhar uma informacao
* Parametros :
	* pilha - A pilha de atomos
	* x - A informacao
	* op - A opcao : TRUE or FALSE
* Devolve : A pilha alterada
* Retorna :  Codigo de erro
*/
int empilhar(TPilha *pilha, TInfo x,Boolean op);
/**
* Função : desempilhar
* Objectivo : Desempilhar uma informacao
* Parametros :
	* pilha - A pilha de atomos
* Devolve : A pilha alterada
* Retorna :  PAtomo desempilhado
*/
PAtomo * desempilhar(TPilha *pilha);
/**
* Procedimento : imprimirPilha
* Objectivo : imprimir a mensagem a pilha
* Parametros : a pilha
* Devolve : Pilha
* Retorna : nada
*/
void imprimirPilha(TPilha *pilha);
/*
*	Procedimento : executar
*	Objectivo : imprimir a mensagem do respectivo código de erro na tela
*	Parametros : o codigo de erro
*	Devolve : nada
*	Retorna : nada
*/
void executar ( int cod );

/*
*	Procedimento : executarImprimir
*	Objectivo : imprimir a mensagem do respectivo código de erro sobre numeros na tela
*	Parametros : o codigo de erro e oultimo numero da lista invalido
*	Devolve : nada
*	Retorna : nada
*/
void executarImprimir ( int cod , int nelem);

/**
*	Funcao : executarInvertido
*	Objectivo : imprimir a mensagem do respectivo código de erro sobre numeros na tela
*	Parametros : o codigo de erro
*	Devolve : nada
*	Retorna : nada
*/
void executarInvertido(int cod);

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
int verificarNumeros(TLista *lista,TPilha * pilha,int a, int b,int n,int op);
/**
*	Função : verificarNumerosInvertido
*	Objectivo : verificar se os numeros digitados sao validos
		imprimir naquele intervalo.
*	Parametros :
	* lista - a lista de atomos
	* a - primeiro numero digitado
	* b - segundo numero digitado
	* n - tamanho da lista
*	Devolve : lista
*	Retorna : codigo de erro
*/
int verificarNumerosInvertido(TLista *lista, int a, int b, int n);

/*
*	Funcao : imprimirLista
*	Objectivo : imprimir todas as informacoes de determinado intervalo
*	Parametros :
	* lista - a lista de atomos
	* ini - inicio do intervalo
	* fim - fim do intervalo
*	Devolve : nada
*	Retorna : codigo de erros
*/
int imprimirLista (TLista lista, int ini, int fim); 

/*
* Funcao : imprimirListainvertido
* Objectivo : imprimir todas as informacoes de forma invertida
* Parametros :
	* lista - a lista de atomos
	* ini - inicio do intervalo
	* fim - fim do intervalo
* Devolve : nada
* Retorna : codigo de erro
*/
int imprimirListainvertido(TLista lista, int ini, int fim);

/*
* Funcao : contaAntecessor
* Objectivo : contar o antecessor dos atomos
* Parametros :
	* paux - um determinado atomo
* Devolve : nada
* Retorna : numero de antecessores
*/
int contaAntecessor(TAtomo *paux);

/*
* Procedimento : localizarFrase
* Objectivo : imprimir e pintar a frase dada
* Parametros :
	* lista - a lista de atomos
	* frase - uma substring que devemos pintar
* Devolve : nada
* Retorna : nada
*/
int localizarFrase(TLista lista, char * frase);

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
int arrastarStringFim(char * str, int pos,int size);

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
int arrastarString(char * str, int pos,int size);

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
int afastarCaracteres(char * str, int qtd, int ini,int op);

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
int alterarFrase(TLista lista, char * substring, char * frase);

/*
* Função : removerFrase
* Objectivo : revover uma frase da linha corrente por uma frase dada
* Parametros :
	* lista - a lista de atomos
	* frase - a substring que devemos remover
* Devolve : frase da linha corrente removida
* Retorna : um código de erro
*/
int removerFrase(TLista * lista,TPilha * pilha, char * frase);

/*
* Função : recuperarLinha
* Objectivo : revover uma frase da linha corrente por uma frase dada
* Parametros :
	* lista - a lista de atomos
	* pilha - a pilha de atomos
	* paux - patomo que devemos recuperar
* Devolve : lista alterada
* Retorna : um código de erro
*/
int recuperarLinha(TLista * lista, TPilha * pilha,PAtomo * paux);

/*
* Função : recuperarFrase
* Objectivo : recuperar uma frase que foi removida
* Parametros :
	* lista - a lista de atomos
	* pilha - a pilha de atomos
	* paux - patomo que devemos recuperar
* Devolve : lista alterada
* Retorna : um código de erro
*/
int recuperarFrase(TLista * lista, TPilha * pilha,PAtomo * paux);

/*
* Função : recuperar
* Objectivo : recuperar uma frase ou linha que foi removida
* Parametros :
	* lista - a lista de atomos
	* pilha - a pilha de atomos
* Devolve : lista alterada
* Retorna : um código de erro
*/
int recuperar(TLista * lista, TPilha * pilha);

/*
* Função : tamanhoString
* Objectivo : contar os caracteres de uma string
* Parametro : a string que queremos saber o tamanho
* Devolve : nada
* Retorna : tamanho da string
*/
int tamanhoString(char * str);

/*
* Procedimento : imprimirInfo
* Objectivo : imprimir a informação de um atomo
* Parametro : a informação para imprimir
* Devolve : nada
* Retorna : nada
*/
void imprimirInfo(TInfo info); 

/*
* Funcão : buscarAtomo
* Objectivo : procurar o atomo que tem uma deteminada chave
* Parametros :
	* lista - a lista de atomos
	* ch - uma chave
* Devolve : nada
* Retorna : o atomo
*/
TAtomo *buscarAtomo(TLista lista, int ch);

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
int verificarLinhaCorrente(TAtomo * pdel1, TAtomo * pdel2);

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
int inserirAtomoLinha(TLista *lista1, TLista *lista2, int chave);

/*
* Função : inserirAtomoFimLista
* Objectivo : inserir determinado atomo no fim da lista
* Parametros :
	* lista - a lista de atomos
	* x - a informacao para o atomo
* Devolve : lista alterada
* Retorna : codigo de erro
*/
int inserirAtomoFimLista(TLista *lista, TInfo x);

/*
* Função : inserirAtomoLinha
* Objectivo : Converter uma string em um numero inteiro
* Parametros :
	* str - a string
* Devolve : nada
* Retorna : número inteiro
*/
int myAtoi(char *str);

/*
* Procedimento : lerFrase
* Objectivo : ler uma string com tamanho igual a 80
* Parametros :
	* str - a string
* Devolve : string alterada
* Retorna : nada
*/
void lerFrase(char *str);

/*
* Função : verifOperacao
* Objectivo : verificar comando digitado
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
* Devolve : string alterada
* Retorna : 1 ou 0
*/
Boolean verifOperacao(char * string1, char * string2);

/*
* Função : verifLocalizarAlterar
* Objectivo : verificar comando se o camando digitado é alterar ou localizar
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
* Devolve : string alterada
* Retorna : 1 ou 0
*/
Boolean verifLocalizarAlterar(char * string1, char * string2,int pos);

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
Boolean verifOperacaoPosicao(char * string1, char * string2,int pos);

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
int guardarNum(int ini, char car,char * str, char * str2);

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
void actualizarChave(TAtomo *paux,int qtd,int op);

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
void actualizarAtomos(TAtomo *paux,int qtd,int op);

/*
* Procedimento : iniciarEditor
* Objectivo : iniciar o editor de texto
* Parametro : nenhum
* Devolve : nada
* Retorna : nada
*/
int iniciarEditor();


/*
* Fração : verificarComandos
* Objectivo : verificar e executar comandos
* Parametros :
	* lista - a lista de atomos
	* pilha - a pilha de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int verificarComandos(TLista *lista,TPilha * pilha,char *frase);

/*
* Função : verifVirgula
* Objectivo : verificar se a string tem uma virgula
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : 1 ou 0
*/
Boolean verifVirgula(char * string);

/*
* Função : verifDigito
* Objectivo : verificar se a string tem um digito (um numero)
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : 1 ou 0
*/
Boolean verifDigito(char * string);

/*
* Função : verifDigitoPos
* Objectivo : verificar se a string tem um digito (um numero)
* Parametros :
	* string - a string
* Devolve : nada
* Retorna : a posição do caracter ou -1
*/
int verifDigitoPos(char * string);

/*
* Função : verifPercentagem
* Objectivo : verificar se a string tem uma percentagem
* Parametros :
	* i - posicao de inicio
	* string - a string
* Devolve : nada
* Retorna : a posição ou -1
*/
int verifPercentagem(int i,char * string);

/*
* Procedimento : removerEspacos
* Objectivo : remover espaços em branco na string
* Parametros :
	* str - a string
* Devolve : uma string alterada
* Retorna : nada
*/
void removerEspacos(char *str);

/*
* Funcao : removerAtomoChave
* Objectivo : remover o atomo que tem uma determinada chave
* Parametros :
	* lista - a lista de atomos
	* chave - uma chave
* Devolve : uma lista alterada
* Retorna : codigo de erro
*/
int removerAtomoChave(TLista *lista,int chave);

/*
* Funcao : removerAtomosLista
* Objectivo : remover os atomos que estao entre dois atomos
	especificos, incluindo eles
* Parametros :
	* lista - a lista de atomos
	* chave1 - primeira chave
	* chave2 - segunda chave
* Devolve : lista alterada
* Retorna : codigo de erro
*/
int removerAtomosLista(TLista *lista,int chave1,int chave2);

/*
* Função : contarAtomosAteAtomo
* Objectivo : contar atomos entre dois atomos especificos
* Parametros :
	* pdel1 - primeiro atomo
	* pdel2 - segundo atomo
* Devolve : nada
* Retorna : numero de atomos entre eles, incluindo eles
*/
int contarAtomosAteAtomo(TAtomo * pdel1, TAtomo * pdel2);

/*
* Função : executarComandoPercentagens
* Objectivo : verificar e executar comando alterar ou localizar
* Parametros :
	* lista - a lista de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int executarComandoPercentagens(TLista *lista,TPilha * pilha,char *frase);

/*
* Fração : executarComandoDigitos
* Objectivo : verificar e executar comandos que tem numeros
* Parametros :
	* lista - a lista de atomos
	* frase - a string digitada
* Devolve : nada
* Retorna : código de erro
*/
int executarComandoDigitos(TLista *lista,TPilha * pilha,char *frase);

/*
* Procedimento : removerEspacos
* Objectivo : remover espaços em branco na string
* Parametros :
	* str - a string
* Devolve : uma string alterada
* Retorna : nada
*/
void removerCaracteres(char * str, int pos,int size);

/*
* Procedimento : copiarString
* Objectivo : copiar caracteres de uma string
* Parametros :
	* str1 - a string origem
	* str2 - a string destino
* Devolve : uma string alterada
* Retorna : nada
*/
void copiarString(char * str1,char *str2);

/*
* Procedimento : copiarStringCaracter
* Objectivo : copiar caracteres de uma string ate determinado caracter
* Parametros :
	* str1 - a string origem
	* str2 - a string destino
	* pos - a posicao do caracter
* Devolve : uma string alterada
* Retorna : nada
*/
void copiarStringCaracter(char * str1,char *str2,int pos);

/*
* Procedimento : converterMinuscula
* Objectivo : alterar os caracteres da string para minusculos
* Parametros :
	* str - a string
* Devolve : string alterada
* Retorna : nada
*/
void converterMinuscula(char * str);

/*
* Procedimento : actualizarLista
* Objectivo : actualizar as chaves da lista
* Parametros :
	* lista - a lista
* Devolve : chaves alteradas
* Retorna : nada
*/
int actualizarLista(TLista * lista);

/*
* Função : verificarStrings
* Objectivo : verificar comando digitado
* Parametros :
	* string1 - a string principal
	* string2 - a string para comparar
* Devolve : string alterada
* Retorna : 1 ou 0
*/
Boolean verificarStrings(char * string1, char * string2);

/*
* Funcao : carregarFicheiro
* Objectivo : carregar a lista com os dados de um ficheiro de texto
* Parametros :
	* path - o caminho para o arquivo
	* lista - a lista
* Devolve : lista
* Retorna : codigo de erro
*/
int carregarFicheiro(char * path,TLista * lista);

/*
* Funcao : gravarFicheiro
* Objectivo : gravar em um ficheiro os dados de uma lista
* Parametros :
	* path - o caminho para o arquivo
	* lista - a lista
	* op - opcao de escrita
* Devolve : nada
* Retorna : codigo de erro
*/
int gravarFicheiro(char * path,TLista lista);

#endif