#include "Huffman.hpp"
#include "Kuyruk.hpp"
#include <iomanip>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

Huffman::Huffman()
{
    kok= 0;
}
void Huffman::olustur(string yazi) 
{
	int frekanslar[256];
    for(int i=0;i<256;i++)
        frekanslar[i]=0;

    for(int i=0;i<yazi.length();i++)
    {
        frekanslar[yazi[i]]++;
    }
    /// Devamı diğer slayttta
    Kuyruk dugumler;
    for(int i=0;i<256;i++)
    {
        if(frekanslar[i]!=0)
        {
            dugumler.ekle(new HuffmanDugum((char)i,frekanslar[i]));
        }
    }
    cout<<dugumler;    
    
    while(dugumler.elemanSayisi()>1)
    {
        HuffmanDugum * sol=dugumler.enKucukGetir();
         dugumler.enKucuguCikar();
        HuffmanDugum * sag= dugumler.enKucukGetir();;
        dugumler.enKucuguCikar();
        cout<<"--"<<endl;
        HuffmanDugum* ebeveyn =new HuffmanDugum();
        ebeveyn->frekans= sol->frekans+sag->frekans;
        ebeveyn->karakter = '-';
        ebeveyn->sol = sol;
        ebeveyn->sag = sag;
        dugumler.ekle(ebeveyn);
        cout<<dugumler;
    }
    kok = dugumler.enKucukGetir();
    dugumler.enKucuguCikar();

    string kod="";
    kodlariYazdir(kok,kod);
}
Huffman::~Huffman()
{

}

void Huffman::kodlariYazdir(HuffmanDugum* aktif,string kod) 
{
	if(aktif->sol&&aktif->sag)
    {
        kodlariYazdir(aktif->sol,kod+'0');
        kodlariYazdir(aktif->sag,kod+'1');
    }
    else
    {
        cout<<aktif->karakter<<":"<<kod<<endl;
    }
}
