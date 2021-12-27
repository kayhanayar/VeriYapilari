all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/HashTablosu.cpp -o ./lib/HashTablosu.o
bagla:
	g++ ./lib/HashTablosu.o	./lib/main.o -o ./bin/program
calistir:
	./bin/program