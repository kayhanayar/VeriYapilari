#include "Dikdortgen.hpp"

Dikdortgen::Dikdortgen(int genislik,int yukseklik)
{
    //iki üye isareci icin heap hafızasından sırayla 2 tamsayı icin alan alınıyor
    //her alanın adresi ilgili isaretciye atanıyor
    m_Genislik = new int(genislik);
    m_Yukseklik = new int(yukseklik);
}
//yok edici fonksiyonun gövdesi yazılıyor
Dikdortgen::~Dikdortgen()
{
    //nesnenin aldığı alanlar serbest bırakılıyor
    delete m_Genislik;
    delete m_Yukseklik;
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