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

void Kuyruk::ekle(int veri)
{
    if(veriSayisi==kapasite)
        genislet(kapasite);
    son=(son+1)%kapasite;;
    veriSayisi++;
    veriler[son]=veri;
}
void Kuyruk::cikar()
{
    if(veriSayisi!=0)
    {
        ilk=(ilk+1)%kapasite;
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
    int oncekiIndex=ilk;
    for(int i=0;i<veriSayisi;i++)
    {
         yeniAlan[i] = veriler[oncekiIndex];   
         oncekiIndex=(oncekiIndex+1)%kapasite;        
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
    if(kuyruk.veriSayisi==0)
        os<<"----KUYRUK BOS----"<<endl;
    else
    {
        if(kuyruk.veriSayisi==1)
            os<<setw(5)<<"ilk-son->";
        else
            os<<setw(5)<<"ilk ---->";
    }
    int sira= kuyruk.ilk;
    for(int i=0;i<kuyruk.veriSayisi;i++)
    {
        os<<setw(2)<<kuyruk.veriler[sira]<<" :["<<sira<<"]"<<endl;
        sira=(sira+1)%kuyruk.kapasite;
        if(sira==kuyruk.son)
            os<<"son ---->";
        else
            os<<setw(9)<<"    ";     
       
    }
    cout<<endl;
    return os;
}