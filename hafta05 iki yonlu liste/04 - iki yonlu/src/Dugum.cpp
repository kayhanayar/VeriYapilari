#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
    this->veri = veri;

    onceki = sonraki = 0;
}
Dugum::~Dugum()
{
    cout<<this<<":adresindeki dugum Silindi"<<endl;
}