#include "Dikdortgen.hpp"
Dikdortgen::Dikdortgen(int genislik,int yukseklik)
{
    m_Genislik = genislik;
    m_Yukseklik= yukseklik;
}
Dikdortgen::Dikdortgen()
{
    m_Genislik = 10;
    m_Yukseklik =20;
}
int Dikdortgen::genislik()
{
    return m_Genislik;
}
int Dikdortgen::yukseklik()
{
    return m_Yukseklik;
}