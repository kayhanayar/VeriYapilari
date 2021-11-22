#ifndef Dugum_hpp
#define Dugum_hpp
template<typename Tur>
class Dugum
{
public:
    Dugum(Tur veri)
    {
        this->veri = veri;
        sonraki=0;
    }
    Tur veri;
    Dugum* sonraki;
};

#endif