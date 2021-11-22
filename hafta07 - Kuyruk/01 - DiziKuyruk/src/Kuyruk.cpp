#include "Kuyruk.hpp"
#include <iomanip>
Kuyruk::Kuyruk()
{
    ilk=0;son = -1;
    veriler=0;
    veriSayisi=0;
    kapasite = 0;
    genislet(5);
}
Kuyruk::~Kuyruk()
{
    delete[] veriler;
}
bool Kuyruk::bosmu()
{
    if(veriSayisi==0)
        return true;
    return false;
}
bool Kuyruk::dolumu()
{
    if(veriSayisi!=0)
        return true;
    return false;
}
void Kuyruk::ekle(int veri)
{
    if(son==kapasite-1)
        genislet(kapasite);
    son++;
    veriSayisi++;
    veriler[son]=veri;
}
void Kuyruk::cikar()
{
    if(veriSayisi!=0)
    {
        ilk++;
        veriSayisi--;
    }
}
int Kuyruk::getir()
{
    if(veriSayisi!=0)
        return veriler[ilk];
    throw std::out_of_range("Kuyruk Bos");
}
void Kuyruk::genislet(int boyut)
{
    int *yeniAlan = new int[boyut+kapasite];
    int yeniIndex=0;
    for(int i=ilk;i<=son;i++)
    {
         yeniAlan[yeniIndex] = veriler[i];   
         yeniIndex++;        
    }
    if(veriler)
        delete[] veriler;
    son=veriSayisi-1;
    ilk=0;
    veriler = yeniAlan;
    kapasite += boyut;
}
ostream& operator<<(ostream& os,Kuyruk& kuyruk)
{
    cout<<kuyruk.son-kuyruk.ilk<<endl;
    if(kuyruk.veriSayisi==0)
        os<<"----KUYRUK BOS----"<<endl;
    else
    {
        if(kuyruk.veriSayisi==1)
            os<<setw(5)<<"ilk-son->";
        else
            os<<setw(5)<<"ilk ---->";
    }
    for(int i=kuyruk.ilk;i<=kuyruk.son;i++)
    {
        os<<setw(2)<<kuyruk.veriler[i]<<" :["<<i<<"]"<<endl;
        if(i==kuyruk.son-1)
            os<<"son ---->";
        else
            os<<setw(9)<<"    ";     
    }
    cout<<endl;
    return os;
}