#ifndef Dikdortgen_hpp
#define Dikdortgen_hpp

#include "Nokta.hpp"
class Dikdortgen
{
public:
    Dikdortgen(int genislik,int yukseklik);

    Dikdortgen();

    int genislik();

    int yukseklik();
    
    Nokta pozisyon();

private:
    int m_Genislik;
    int m_Yukseklik;
    Nokta m_Pozisyon;
};



#endif