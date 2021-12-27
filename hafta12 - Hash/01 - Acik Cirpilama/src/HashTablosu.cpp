#include "HashTablosu.hpp"
Dugum::Dugum(int veri)
{
    this->veri=veri;
    this->sonraki =nullptr;
}
HashTablosu::HashTablosu()
{
    for(int i=0;i<MAX;i++)
        elemanlar[i] = nullptr;
}
HashTablosu::~HashTablosu()
{
    for(int i=0;i<MAX;i++)
    {
        if(elemanlar[i]!=nullptr)
        {   
            Dugum*gec =elemanlar[i];
            while(gec)
            {
                Dugum* sil = gec;
                gec = gec->sonraki;
                delete sil;
            }
        }
    }
}

void HashTablosu::ekle(int veri) 
{
    if(bul(veri)) return;

    int index = hashFonksiyonu(veri);
    
    Dugum*gec = elemanlar[index];
    if(gec)
    {
        while(gec->sonraki!=nullptr)
            gec=gec->sonraki;
        gec->sonraki = new Dugum(veri);
    }
    else
    {
        elemanlar[index] = new Dugum(veri);
    }
}

void HashTablosu::cikar(int veri) 
{
    int index = hashFonksiyonu(veri);
    
    Dugum*gec = elemanlar[index];    

    if(gec)
    {
        if(gec->veri==veri)
        {
            Dugum* sil = gec;
            elemanlar[index] = sil->sonraki;
            delete sil;
        }
        else
        {
            if(gec->sonraki==nullptr)
                return;

            while(gec->sonraki!=nullptr)
            {
                if(gec->sonraki->veri==veri)
                {
                   
                    Dugum* sil = gec->sonraki;
                    gec->sonraki = sil->sonraki;
                    delete sil;
                    return;
                }
                gec=gec->sonraki;
            }
               
        }
    
    }

}

bool HashTablosu::bul(int veri) 
{
    int index = hashFonksiyonu(veri);
    
    Dugum* gec = elemanlar[index];

    while(gec!=nullptr)
    {
        if(gec->veri==veri)
            return true;
        gec=gec->sonraki;
    }
    return false;
}

ostream& operator<<(ostream& os,HashTablosu& tablo) 
{
    for(int i=0;i<MAX;i++)
    {
        if(tablo.elemanlar[i])
        {
            os<<i<<":"<<tablo.elemanlar[i]<<" | ";
            Dugum* gec= tablo.elemanlar[i];
            while(gec->sonraki!=nullptr)
            {
                os<<gec->veri<<":"<<gec->sonraki<<"->    ";
                gec=gec->sonraki;
            }
            os<<gec->veri<<":"<<gec->sonraki;
            cout<<endl<<"--------------------"<<endl;
        }
        
    }
    cout<<endl<<endl;
}

int HashTablosu::hashFonksiyonu(int anahtar) 
{
    return anahtar%MAX;
}
