#include "IkiliAramaAgaci.hpp"
#include <iomanip>
#include<iostream>
using namespace std;
IkiliAramaAgaci::IkiliAramaAgaci()
{
    for(int i=0;i<MAX;i++)
        hucreDurumlari[i] = HUCRE_BOS;
}
// IkiliAramaAgaci::~IkiliAramaAgaci()
// {

// }
/* int IkiliAramaAgaci::bul(int veri) 
{
  
} */
void IkiliAramaAgaci::ekle(int eklenecek)
{
    int siradaki = 0;
    while(true)
    {
        
        if(siradaki>=MAX)
            break;
        if(!varmi(siradaki))
        {
            hucreler[siradaki] = eklenecek;
            hucreDurumlari[siradaki] = HUCRE_DOLU;
            break;
        }
        else if(eklenecek<hucreler[siradaki])
        {
            siradaki = sol(siradaki);
        }
        else if(eklenecek>hucreler[siradaki])
        {
            siradaki = sag(siradaki);
        }
        else
            break;
           
        
    }

}
/* void IkiliAramaAgaci::sil(int silinecek) 
{

}
int IkiliAramaAgaci::yukseklik() 
{

}*/
void IkiliAramaAgaci::preOrder()
{
	preOrder(0);
}
void IkiliAramaAgaci::postOrder() 
{
    postOrder(0);
}
void IkiliAramaAgaci::inOrder() 
{
    inOrder(0);   
}
void IkiliAramaAgaci::preOrder(int index) 
{
    if(index<MAX&&varmi(index))
    {
        cout<<hucreler[index]<<" - ";
        if(solVarmi(index))
            preOrder(sol(index));
        if(sagVarmi(index))
            preOrder(sag(index));
    }
}
void IkiliAramaAgaci::postOrder(int index) 
{
    if(index<MAX&&varmi(index))
    {
       
        if(solVarmi(index))
            postOrder(sol(index));
        if(sagVarmi(index))
            postOrder(sag(index));
         cout<<hucreler[index]<<" - ";
    }
}
void IkiliAramaAgaci::inOrder(int index) 
{
    if(index<MAX&&varmi(index))
    {
       
        if(solVarmi(index))
            inOrder(sol(index));
        cout<<hucreler[index]<<" - ";            
        if(sagVarmi(index))
            inOrder(sag(index));

         
    }	
}
/*
int IkiliAramaAgaci::yukseklik(int index) 
{

}
void IkiliAramaAgaci::sil(int silinecek,int index) 
{

}
int IkiliAramaAgaci::bul(int aranan,int index)
{

} */




int IkiliAramaAgaci::sol(int index)
{
    return 2*index+1;
}
int IkiliAramaAgaci::sag(int index)
{
    return 2*index+2;
}
int IkiliAramaAgaci::ebeveyn(int index)
{
    return (index-1)/2;
}

bool IkiliAramaAgaci::sagVarmi(int index) 
{
    if(index>=MAX)
        return  false;
	if(hucreDurumlari[sag(index)]==HUCRE_DOLU)
        return true;
    return false;
}

bool IkiliAramaAgaci::solVarmi(int index) 
{
    if(index>=MAX)
        return  false;
	if(hucreDurumlari[sol(index)]==HUCRE_DOLU)
        return true;
    return false;
}
bool IkiliAramaAgaci::varmi(int index)
{   
	if(index<MAX&&hucreDurumlari[index]==HUCRE_DOLU)
        return true;
    return false;
}

ostream& operator<<(ostream& os,IkiliAramaAgaci& agac)
{
    for(int i=0;i<MAX;i++)
    {
        os<<setw(3)<<i<<setw(3)<<"|";
    }
    os<<endl;
    for(int i=0;i<MAX;i++)
    {
        os<<setw(3)<<"---"<<setw(3)<<"---";
    }
    os<<endl;    
    for(int i=0;i<MAX;i++)
    {
        if(agac.varmi(i))
        {
            os<<setw(3)<<agac.hucreler[i]<<setw(3)<<"|";
        }
        else
        {
           os<<setw(3)<<"bos"<<setw(3)<<"|";
        }
        
    }
    os<<endl;

    return os;
}