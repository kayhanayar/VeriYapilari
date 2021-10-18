#ifndef Iterator_hpp
#define Iterator_hpp

#include "Dugum.hpp"

class Iterator
{
public:
    Iterator();
    Iterator(Dugum* aktifDugum);
    bool sonrakiVarmi();
    bool aktifMi();
    void sonrakineGit();
    int  deger();  
    void operator++(int);
    

    Dugum* aktifDugum;


};

#endif