#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>
using namespace std;
//Sablon sınıflarında butun tanım tek bir dosyada bulunmalıdır.
template<typename Tur>
class Dugum
{
public:
    Dugum(const Tur& veri)
    {
        this->veri = veri;
        sonraki = onceki = 0;
    }
    Tur veri;
    Dugum* sonraki;
    Dugum* onceki;

};

#endif