all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o	
bagla:
	g++ ./lib/Dugum.o	./lib/AVLAgaci.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program