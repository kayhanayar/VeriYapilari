all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
bagla:
	g++ ./lib/Kuyruk.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program