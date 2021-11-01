#include "Yigin.hpp"
#include <iomanip>
Yigin::Yigin()
{
    tepe = -1;

}
bool Yigin::bosmu()
{
    if(tepe==-1)
        return true;
    return false;
}
bool Yigin::dolumu()
{
    if(tepe==MAX-1)
        return true;
    return false;
}
void Yigin::ekle(int veri)
{
    if(tepe<MAX-1)
    {
        tepe++;
        veriler[tepe]=veri;
    }
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