#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>
using namespace std;

class Dugum
{
public:
    Dugum(int veri);
    ~Dugum();
    int veri;
    Dugum* sonraki;
    Dugum* onceki;
};


#endif