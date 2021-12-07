#include "IkiliAramaAgaci.hpp"
#include <iomanip>
#include<iostream>
using namespace std;
IkiliAramaAgaci::IkiliAramaAgaci()
{
    hucreler= new int[MAX];
    for(int i=0;i<MAX;i++)
    {
        hucreDurumlari[i]=HUCRE_BOS;
    }
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{

}
int IkiliAramaAgaci::bul(int veri) 
{
    return bul(veri,0);
}
void IkiliAramaAgaci::ekle(int eklenecek)
{
    int siradaki = 0;
    while(true)
    {
        if(hucreDurumlari[siradaki]==HUCRE_BOS)
        {
            hucreler[siradaki]=eklenecek;
            hucreDurumlari[siradaki] = HUCRE_DOLU;
            break;
        }
        else if(eklenecek<hucreler[siradaki])//sola gidilecek
        {
            siradaki = sol(siradaki);
        }
        else if(eklenecek>hucreler[siradaki])
        {
            siradaki= sag(siradaki);
        }
        else
        {     //aynı eleman ağaçta var.
            return ;
        }
    }
}
void IkiliAramaAgaci::sil(int silinecek) 
{
	int index= bul(silinecek,index);
    if(index!=-1)
        sil(silinecek,index);
}
int IkiliAramaAgaci::yukseklik() 
{
	return yukseklik(0);
}
void IkiliAramaAgaci::preOrder() {
    preOrder(0);
}
void IkiliAramaAgaci::postOrder() {
	postOrder(0);
}
void IkiliAramaAgaci::inOrder() {
    inOrder(0);
}
void IkiliAramaAgaci::preOrder(int index) 
{
	if(index<MAX&&varmi(index))
    {
        cout<<hucreler[index]<<" - ";
        preOrder(sol(index));
        preOrder(sag(index));
    }
}
void IkiliAramaAgaci::postOrder(int index) 
{
	if(index<MAX&&varmi(index))
    {
        preOrder(sol(index));
        preOrder(sag(index));
        cout<<hucreler[index]<<" - ";
    }	
}
void IkiliAramaAgaci::inOrder(int index) 
{
	if(index<MAX && varmi(index))
    {
        inOrder(sol(index));
        cout<<hucreler[index]<<" - ";
        inOrder(sag(index));
       
    }		
}
int IkiliAramaAgaci::yukseklik(int index) 
{
	if(varmi(index))
    {
        return 1+max(   yukseklik(sol(index)),
                        yukseklik(sag(index)));
    }
    return -1;
}
void IkiliAramaAgaci::sil(int silinecek,int index) 
{
	hucreDurumlari[index] = HUCRE_BOS;


    if(!sagVarmi(index)&&solVarmi(index))
    {

    }
    else if(sagVarmi(index)&&!solVarmi(index))
    {

    }
}
int IkiliAramaAgaci::bul(int aranan,int index)
{
    while(true)
    {
        if(index>=MAX||!varmi(index)) 
            return -1;
        if(hucreler[index]==aranan&&varmi(index))
        {
            return index;
        }
        else if(aranan<hucreler[index])//sola gidilecek
        {
            index = sol(index);
        }
        else if(aranan>hucreler[index])
        {
            index= sag(index);
        }
    }
}




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
	if(hucreDurumlari[sag(index)]==HUCRE_DOLU)
        return true;
    return false;
}

bool IkiliAramaAgaci::solVarmi(int index) 
{
	if(hucreDurumlari[sol(index)]==HUCRE_DOLU)
        return true;
    return false;
}
bool IkiliAramaAgaci::varmi(int index)
{
	if(hucreDurumlari[index]==HUCRE_DOLU)
        return true;
    return false;
}

 ostream& operator<<(ostream& os,IkiliAramaAgaci& agac)
{
    for(int i=0;i<MAX;i++)
    {
        os<<setw(3)<<i<<setw(2)<<"|";
    }
    os<<endl;
    for(int i=0;i<MAX;i++)
    {
        if(agac.hucreDurumlari[i]!=IkiliAramaAgaci::HUCRE_BOS)
            os<<setw(3)<<agac.hucreler[i]<<setw(2)<<"|";
        else
          os<<setw(3)<<"bos"<<setw(2)<<"|";
    }
    os<<endl;  
    return os;  
}