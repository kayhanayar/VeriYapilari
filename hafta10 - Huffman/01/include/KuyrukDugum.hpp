#ifndef KuyrukDugum_hpp
#define KuyrukDugum_hpp
#include "HuffmanDugum.hpp"
class KuyrukDugum
{
public:
    KuyrukDugum(HuffmanDugum* veri)
    {
        this->veri = veri;
        sonraki=0;
    }
    HuffmanDugum* veri;
    KuyrukDugum* sonraki;
};

#endif