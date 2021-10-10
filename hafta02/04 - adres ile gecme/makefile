all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Kutuphane.cpp -o ./lib/Kutuphane.o
bagla:
	g++ ./lib/Kutuphane.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program