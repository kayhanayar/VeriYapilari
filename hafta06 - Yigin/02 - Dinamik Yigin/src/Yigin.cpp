#include "Yigin.hpp"
#include <iomanip>
Yigin::Yigin()
{
    tepe = -1;
    veriler=0;
    kapasite = 5;
    genislet(kapasite);
}
Yigin::~Yigin()
{
    delete[] veriler;
}
bool Yigin::bosmu()
{
    if(tepe==-1)
        return true;
    return false;
}
bool Yigin::dolumu()
{
    if(tepe==kapasite-1)
        return true;
    return false;
}
void Yigin::ekle(int veri)
{
    if(tepe==kapasite-1)
        genislet(kapasite);

    tepe++;
    veriler[tepe]=veri;
}
void Yigin::cikar()
{
    if(tepe!=-1)
    {
        tepe--;
    }
}
int Yigin::getir()
{
    if(tepe!=-1)
        return veriler[tepe];
    throw std::out_of_range("Yigin Bos");
}
void Yigin::genislet(int boyut)
{
    int *yeniAlan = new int[boyut+kapasite];
    for(int i=0;i<=tepe;i++)
    {
        
         yeniAlan[i] = veriler[i];   
        
    }
    if(veriler)
        delete[] veriler;
    veriler = yeniAlan;
    kapasite += boyut;
   
}
ostream& operator<<(ostream& os,Yigin& yigin)
{
    os<<setw(5)<<"---->";
    for(int i=0;i<=yigin.tepe;i++)
    {
        os<<yigin.veriler[yigin.tepe-i]<<endl;
        os<<setw(5)<<"    ";     
    }
    cout<<endl;
    return os;
}