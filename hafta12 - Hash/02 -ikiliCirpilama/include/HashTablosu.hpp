#ifndef HashTablosu_hpp
#define HashTablosu_hpp

#include<iostream>

const int MAX = 13;
const int YAKIN= 11;
using namespace std;


class HashTablosu
{
public:
    HashTablosu();
    
    void ekle(int veri);
    void cikar(int veri);
    bool bul(int veri);
    friend ostream& operator<<(ostream& os,HashTablosu& tablo);
private:
    int hash1(int anahtar);
    int hash2(int anahtar);
    int elemanlar[MAX];
    int elemanSayisi;
};


#endif








