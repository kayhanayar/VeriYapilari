all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/dugum.cpp -o ./lib/dugum.o
	g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o

bagla:
	g++ ./lib/dugum.o ./lib/Yigin.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program