#ifndef Dugum_hpp
#define Dugum_hpp
//Sablon sınıflarında butun tanım tek bir dosyada bulunmalıdır.
template<typename Tur>
class Dugum
{
public:
    Dugum(Tur veri)
    {
        this->veri;
        sonraki = 0;
    }
    Tur veri;
    Dugum* sonraki;

};

#endif