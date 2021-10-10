#ifndef Dikdortgen_hpp
#define Dikdortgen_hpp

class Dikdortgen
{
public:
    Dikdortgen(int genislik,int yukseklik);
    ~Dikdortgen();
    int genislik();
    int yukseklik();

    //üye değişkenlerin adreslerini getiren metotlar
    int* genislikAdresGetir();
    int* yukseklikAdresGetir();
private:
    // degiskenlerimiz isaretciye cevrildi
    int *m_Genislik;
    int *m_Yukseklik;
};

#endif