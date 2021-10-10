#include "Dikdortgen.hpp"
Dikdortgen::Dikdortgen(int genislik,int yukseklik)
{
    m_Genislik = genislik;
    m_Yukseklik= yukseklik;
    m_Pozisyon.setX(m_Genislik/2);
    m_Pozisyon.setY(m_Yukseklik/2);
}
Dikdortgen::Dikdortgen()
{
    m_Genislik = 10;
    m_Yukseklik =20;
    m_Pozisyon.setX(m_Genislik/2);
    m_Pozisyon.setY(m_Yukseklik/2);    
}
Nokta Dikdortgen::pozisyon()
{
    return m_Pozisyon;
}
int Dikdortgen::genislik()
{
    return m_Genislik;
}
int Dikdortgen::yukseklik()
{
    return m_Yukseklik;
}