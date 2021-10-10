all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Dikdortgen.cpp -o ./lib/Dikdortgen.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/Dikdortgen.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program