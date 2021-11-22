#include "Kuyruk.hpp"
#include <iomanip>
Kuyruk::Kuyruk()
{
    ilk=son=0;
}
Kuyruk::~Kuyruk()
{
    while(ilk!=0)
    {
        Dugum*gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}
bool Kuyruk::bosmu()
{
    if(ilk==0)
        return true;
    return false;
}

void Kuyruk::ekle(int veri)
{
    if(ilk==0)
    {
        ilk=new Dugum(veri);
        son= ilk;

    }
    else
    {
        Dugum*yeni = new Dugum(veri);
        son->sonraki = yeni;
        son = yeni;

    }
}
void Kuyruk::cikar()
{
    if(ilk!=0)
    {
        Dugum*gec = ilk->sonraki;
        delete ilk;
        ilk=gec;
        if(ilk==0)
            son=0;
    }
}
int Kuyruk::getir()
{
    if(ilk!=0)
        return ilk->veri;
    throw std::out_of_range("Kuyruk Bos");
}
ostream& operator<<(ostream& os,Kuyruk& kuyruk)
{
    cout<<kuyruk.son-kuyruk.ilk<<endl;
    if(kuyruk.ilk==0)
        os<<"----KUYRUK BOS----"<<endl;
    else
    {
        if(kuyruk.ilk==kuyruk.son)
            os<<setw(5)<<"ilk-son->";
        else
            os<<setw(5)<<"ilk ---->";
    }
    Dugum*gec= kuyruk.ilk;
    while(gec!=0)
    {
        os<<setw(2)<<gec->veri<<" : "<<gec->sonraki<<endl;
        if(gec->sonraki==kuyruk.son)
            os<<"son ---->";
        else
            os<<setw(9)<<"    ";   
        gec = gec->sonraki;  
    }

    os<<endl;
    return os;
}