#include "Iterator.hpp"

Iterator::Iterator()
{
    aktifDugum = 0;
}
Iterator::Iterator(Dugum* aktifDugum)
{
    this->aktifDugum = aktifDugum;
}
bool Iterator::sonrakiVarmi()
{
    return aktifDugum->sonraki!=0;
}
bool Iterator::aktifMi()
{
    return aktifDugum!=0;
}
void Iterator::sonrakineGit()
{
    if(sonrakiVarmi())
        aktifDugum = aktifDugum->sonraki;
}
void Iterator::operator++(int right)
{
    if(sonrakiVarmi())
        aktifDugum = aktifDugum->sonraki;    
}
int Iterator::deger()
{
    return aktifDugum->veri;
}