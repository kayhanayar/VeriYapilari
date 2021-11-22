all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
bagla:
	g++ ./lib/Liste.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program