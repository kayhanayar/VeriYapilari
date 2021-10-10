#include "Dikdortgen.hpp"

Dikdortgen::Dikdortgen(int genislik,int yukseklik)
{
    m_Genislik = genislik;
    m_Yukseklik = yukseklik;
}
int Dikdortgen::genislik()
{
    return m_Genislik;

}
int Dikdortgen::yukseklik()
{
    return m_Yukseklik;
}
int* Dikdortgen::genislikAdresGetir()
{
    return &m_Genislik;

}
int* Dikdortgen::yukseklikAdresGetir()
{
    return &m_Yukseklik;
}