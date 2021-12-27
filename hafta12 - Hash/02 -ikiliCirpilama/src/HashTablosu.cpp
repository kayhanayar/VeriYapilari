#include "HashTablosu.hpp"

HashTablosu::HashTablosu()
{
    for(int i=0;i<MAX;i++)
        elemanlar[i] = -1;
}


void HashTablosu::ekle(int veri) 
{
    if(elemanSayisi>=MAX)
        return;

    int index= hash1(veri);
    if(elemanlar[index]!=-1)
    {
        int adim = hash2(veri);
        int tur=1;
        while(true)
        {
            int yeniIndex = (index+tur*adim)%MAX;
            if(elemanlar[yeniIndex]==-1)
            {
                elemanlar[yeniIndex] = veri;
                break;
            }
            tur++;
        }
    }
    else
    {
        elemanlar[index]=veri;
    }
    elemanSayisi++;
}
//...devamı gelecek
void HashTablosu::cikar(int veri) 
{
    if(elemanSayisi==0)
        return;
    int index= hash1(veri);
    //aradığımız eleman direk ilgili indekste bulundu.
    if(elemanlar[index]==veri)
    {
        elemanlar[index] = -1;
        elemanSayisi--;
    
    }
    else
    {
        //aradığımız eleman ilk indeksinde bulunamadı
        //ileri konumlara yerleştirilmiş olmalı.
         int adim=hash2(veri);
         int tur=1;//bir elemanı zaten taradık
         while(tur<=elemanSayisi)
         {
            int yeniIndex= (index+tur*adim)%MAX;
            if(elemanlar[yeniIndex]==veri)
            {
                elemanlar[yeniIndex]=-1;
                elemanSayisi--;
                break;
            }
            tur++;
         }
    }

}

bool HashTablosu::bul(int veri) 
{

}

int HashTablosu::hash1(int anahtar) {
    return anahtar%MAX;
}
int HashTablosu::hash2(int anahtar) {
    return YAKIN -(anahtar%YAKIN);
}
ostream& operator<<(ostream& os,HashTablosu& tablo) 
{
 	for (int i = 0; i < MAX; i++) 
	{ 
		if (tablo.elemanlar[i] != -1) 
			cout<<"["<<i<<"]\t:"<<tablo.elemanlar[i]<<endl; 
		else
			cout<<"["<<i<<"]\t:"<<endl; 
	} 
    return os;
}


