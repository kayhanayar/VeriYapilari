#ifndef Yigin_hpp
#define Yigin_hpp
#include "Dugum.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

class Yigin
{
public:
    Yigin();
    void ekle(int veri);

    void cikar();
    
    friend ostream& operator<<(ostream& os,Yigin& yigin);
    int getir();
private:
    Dugum* tepe;
};

#endif