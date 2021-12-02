compile: main.c figuras.c quadro.c Obra_de_arte.c
	gcc main.c figuras.c quadro.c Obra_de_arte.c -o run
run:
	./run