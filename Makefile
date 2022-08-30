#Autor: Sara David Tuma 

#Compilar e Executar
#Remover os arquivos .o e Limpar a tela totalmente
all: compile
	./executavel
	rm -rf executavel *.o *.gch
	reset

#Compila e cria o executavel
compile: programa.o editorTexto.o
	gcc programa.o editorTexto.o -o executavel

#dependencias
programa.o: programa.c
	gcc -c programa.c

editorTexto.o: editorTexto.c
	gcc -c editorTexto.c