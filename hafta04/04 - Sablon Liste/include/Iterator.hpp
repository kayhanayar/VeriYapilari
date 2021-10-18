#ifndef Iterator_hpp
#define Iterator_hpp

#include "Dugum.hpp"
template<typename Tur>
class Iterator
{
public:
    Iterator()
    {
        aktifDugum = 0;
        
    }
    Iterator(Dugum<Tur>* aktifDugum)
    {
         this->aktifDugum = aktifDugum;
    }
    bool sonrakiVarmi()
    {
        return aktifDugum->sonraki!=0;
    }
    bool aktifMi()
    {
        return aktifDugum!=0;
    }
    void sonrakineGit()
    {
        if(sonrakiVarmi())
            aktifDugum = aktifDugum->sonraki;

    }
    int  deger()
    {

        return aktifDugum->veri;
    }
    void operator++(int)
    {
        if(sonrakiVarmi())
            aktifDugum = aktifDugum->sonraki;    
    }
    

    Dugum<Tur>* aktifDugum;


};

#endif
