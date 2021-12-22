all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/HeapSort.cpp -o ./lib/HeapSort.o
bagla:
	g++ ./lib/HeapSort.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program