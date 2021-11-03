#include "Yigin.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

Yigin::Yigin()
{
    tepe=0;
}
void Yigin::ekle(int veri)
{
    Dugum* yeni = new Dugum(veri);
    if(tepe!=0)
        yeni->sonraki=tepe;
    tepe= yeni;
}
void Yigin::cikar()
{
    if(tepe!=0)
    {
        Dugum* silinecek = tepe;
        tepe=tepe->sonraki;
        delete silinecek;
    }
    
}
ostream& operator<<(ostream& os,Yigin& yigin)
{
    cout<<setw(5)<<"---->";
    Dugum* aktif = yigin.tepe;
    while(aktif!=0)
    {
        cout<<setw(5)<<aktif->veri<<endl<<setw(5)<<"     ";
        aktif=aktif->sonraki;
    }
    cout<<endl;
    return os;
}
int Yigin::getir()
{
    if(tepe!=0)
        return tepe->veri;
    throw std::out_of_range("Yigin::Getir(): Yigin Bos");
}