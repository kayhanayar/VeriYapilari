#ifndef Yigin_hpp
#define Yigin_hpp
#include "Dugum.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;
template<typename Tur>
class Yigin
{
public:
    Yigin()
    {
        tepe=0;
    }
    void ekle(Tur veri)
    {
        Dugum<Tur>* yeni = new Dugum<Tur>(veri);
        if(tepe!=0)
            yeni->sonraki=tepe;
        tepe= yeni;
    }
    void cikar()
    {
        if(tepe!=0)
        {
            Dugum<Tur>*silinecek = tepe;
            tepe=tepe->sonraki;
            delete silinecek;
        }
        
    }
    friend ostream& operator<<(ostream& os,Yigin& yigin)
    {
        cout<<setw(5)<<"---->";
        Dugum<Tur>* aktif = yigin.tepe;
        while(aktif!=0)
        {
            cout<<setw(5)<<aktif->veri<<endl<<setw(5)<<"     ";
            aktif=aktif->sonraki;
        }
        cout<<endl;
        return os;
    }
    Tur getir()
    {
        if(tepe!=0)
            return tepe->veri;
        throw std::out_of_range("Yigin::Getir(): Yigin Bos");
    }

private:
    Dugum<Tur>* tepe;
};

#endif