#ifndef Dikdortgen_hpp
#define Dikdortgen_hpp

class Dikdortgen
{
public:
    Dikdortgen(int genislik,int yukseklik);

    Dikdortgen();

    int genislik();

    int yukseklik();

private:
    int m_Genislik;
    int m_Yukseklik;
};



#endif