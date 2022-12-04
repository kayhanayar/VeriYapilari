#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class Kuyruk
{
public:
	Kuyruk();
	~Kuyruk();
	void ekle(int veri);
	void cikar();
    bool bosmu();
	int getir();
	int elemanSayisiGetir();
    friend ostream& operator<<(ostream& os,Kuyruk& kuyruk);
private:
	Dugum* 	ilk;
	Dugum*	son;
	int elemanSayisi;
};

#endif