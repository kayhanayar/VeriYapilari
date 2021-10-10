#include "Dikdortgen.hpp"
#include<iostream>
Dikdortgen::Dikdortgen(int genislik,int yukseklik)
{
    //iki üye isareci icin heap hafızasından sırayla 2 tamsayı icin alan alınıyor
    //her alanın adresi ilgili isaretciye atanıyor
    m_Genislik = new int(genislik);
    m_Yukseklik = new int(yukseklik);
}
Dikdortgen::Dikdortgen()
{
    std::cout<<this<<" -> adresindeki nesne icin kurucu cagrildi"<<std::endl;
    m_Genislik = new int(rand()%100);
    m_Yukseklik = new int(rand()%100);
}
Dikdortgen::~Dikdortgen()
{
    delete m_Genislik;
    delete m_Yukseklik;
    std::cout<<this<<" -> adresindeki nesne icin yok edici cagrildi"<<std::endl;
}
int Dikdortgen::genislik()
{
    //isaretcinin gosterdiği asıl değer döndürülüyor
    return *m_Genislik;

}
int Dikdortgen::yukseklik()
{
    return *m_Yukseklik;
}
int* Dikdortgen::genislikAdresGetir()
{
    return m_Genislik;

}
int* Dikdortgen::yukseklikAdresGetir()
{
    return m_Yukseklik;
}