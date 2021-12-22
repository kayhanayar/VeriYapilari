all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Huffman.cpp -o ./lib/Huffman.o
	g++ -c -I "./include" ./src/HuffmanDugum.cpp -o ./lib/HuffmanDugum.o	
bagla:
	g++ ./lib/HuffmanDugum.o	./lib/Huffman.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program