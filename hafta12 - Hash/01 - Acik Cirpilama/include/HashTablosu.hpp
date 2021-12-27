#ifndef HashTablosu_hpp
#define HashTablosu_hpp

#include<iostream>

const int MAX = 101;
using namespace std;
class Dugum
{
public:
    int veri;
    Dugum(int veri);
    Dugum* sonraki;
};

class HashTablosu
{
public:
    HashTablosu();
    ~HashTablosu();
    void ekle(int veri);
    void cikar(int veri);
    bool bul(int veri);
    friend ostream& operator<<(ostream& os,HashTablosu& tablo);
private:
    int hashFonksiyonu(int anahtar);
    Dugum* elemanlar[MAX];
};


#endif








