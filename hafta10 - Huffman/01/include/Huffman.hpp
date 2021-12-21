#ifndef Huffman_hpp
#define Huffman_hpp

#include<iostream>
#include "HuffmanDugum.hpp"
using namespace std;

class Huffman
{
public:

	Huffman();
	~Huffman();
	
	void olustur(string yazi);

	void kodlariYazdir(HuffmanDugum* aktif,string kod);
	
private:

	HuffmanDugum* kok;
};
//diger fonksiyonlar eklenecek
#endif