#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
using namespace std;

class Kuyruk
{
public:
	Kuyruk();
	~Kuyruk();
	void ekle(int veri);
	void cikar();
    bool bosmu();
    bool dolumu();
	int getir();
    friend ostream& operator<<(ostream& os,Kuyruk& yigin);
private:
	void genislet(int boyut);
	int kapasite;
    int ilk;
	int son;
	int veriSayisi;
	int* veriler;
};

#endif