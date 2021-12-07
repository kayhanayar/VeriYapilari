all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
bagla:
	g++ ./lib/IkiliAramaAgaci.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program