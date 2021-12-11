compile: main.c ./Figuras/figuras.c ./Quadro/quadro.c ./FiguraDog/Figura_dog.c ./CasaDog/CasinhaDog.c
	gcc main.c ./Figuras/figuras.c ./Quadro/quadro.c ./FiguraDog/Figura_dog.c ./CasaDog/CasinhaDog.c -o run
run:
	./run