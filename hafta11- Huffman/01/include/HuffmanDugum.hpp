#ifndef HuffmanDugum_hpp
#define HuffmanDugum_hpp
#include<iostream>
using namespace  std;

class HuffmanDugum
{
public:
    HuffmanDugum();
    HuffmanDugum(char karakter,int frekans);
    
    char karakter;
    int frekans;
    HuffmanDugum* sol;
    HuffmanDugum* sag;


    friend ostream& operator<<(ostream& os, HuffmanDugum& dugum);
    bool operator>(const HuffmanDugum& sag);
    bool operator<(const HuffmanDugum& sag);
    bool operator==(const HuffmanDugum& sag);
    bool operator!=(const HuffmanDugum& sag);
};

#endif