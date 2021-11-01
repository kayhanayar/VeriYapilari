#ifndef Yigin_hpp
#define Yigin_hpp
#include<iostream>
using namespace std;
const int MAX = 10;
class Yigin
{
public:
	Yigin();
	void ekle(int veri);
	void cikar();
    bool bosmu();
    bool dolumu();
	int getir();
    friend ostream& operator<<(ostream& os,Yigin& yigin);
private:
    int tepe;
	int veriler[MAX];
};

#endif