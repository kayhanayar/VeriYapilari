#include "HuffmanDugum.hpp"

HuffmanDugum::HuffmanDugum(char karakter,int frekans)
{
    this->karakter = karakter;
    this->frekans = frekans;
    sol=sag=0;
}
ostream& operator<<(ostream& os, HuffmanDugum& dugum)
{
    os<<dugum.karakter<<":"<<dugum.frekans;
    return os;
}
bool HuffmanDugum::operator>(const HuffmanDugum& sag) 
{
    if(frekans>sag.frekans)
        return true;
    else
        return false;
}

bool HuffmanDugum::operator<(const HuffmanDugum& sag) 
{
     if(frekans<sag.frekans)
        return true;
    else
        return false;   
}
bool HuffmanDugum::operator==(const HuffmanDugum& sag)
{
    if(frekans==sag.frekans)
        return true;
    else
        return false;  
}
bool HuffmanDugum::operator!=(const HuffmanDugum& sag)
{
    if(frekans!=sag.frekans)
        return true;
    else
        return false;  
}
HuffmanDugum::HuffmanDugum()
{
    
}