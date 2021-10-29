#ifndef BagliListe_hpp
#define BagliListe_hpp
#include<exception>
#include "Dugum.hpp"
template<typename Tur>
class BagliListe
{
public:
    BagliListe()
    {
         ilk=0;
    }
    ~BagliListe()
    {
        Dugum<Tur>* gecici = ilk;

        while(gecici!=0)
        {
            Dugum<Tur>* silinecek = gecici;

            gecici= gecici->sonraki;
            delete silinecek;
        }


    }
    Tur&    ilkGetir()
    {
        if(ilk)
            return ilk->veri;
        throw std::out_of_range("BagliListe::ilkGetir(): dugum yok hatasi");
    }
    Tur& getir(int sira)
    {
        Dugum<Tur>* gec= dugumGetir(sira);

        if(gec!=0)
            return gec->veri;
        throw std::out_of_range("BagliListe::getir(): sira hatali");
            
    }
    
    void ekle(const  Tur& veri)
    {
       
        Dugum<Tur>* yeni = new Dugum<Tur>(veri);

        if(ilk==0)
        {
            ilk = yeni;
            return;
        }
        //iterator ilk düğümü tutuyor
        Dugum<Tur>* gec = ilk;
        
        while(gec->sonraki!=0)
            gec=gec->sonraki;
        
        gec->sonraki=yeni;
    }

    void yazdir()
    {
        using namespace std;
        Dugum<Tur>* gecici = ilk;
        cout<<"-------------------------------"<<endl; 
        cout<<setw(10)<<"Adres:"<<setw(10)<<"Veri:"<<setw(15)<<"Sonraki:"<<endl; 
        cout<<"-------------------------------"<<endl;  
        while(gecici!=0)
        {
            cout<<setw(10)<<gecici<<setw(10)<<gecici->veri<<setw(15)<<gecici->sonraki<<endl;
            cout<<"-------------------------------"<<endl;
            gecici= gecici->sonraki;  
        }
    }
    void cikar()
    {
        if(ilk==0)  return;

        if(ilk->sonraki==0)
        {
            delete ilk;
            ilk=0;
        }
        else
        {
            Dugum<Tur>* gecici = ilk;

            while(gecici->sonraki->sonraki!=0)
            {
                gecici=gecici->sonraki;
            }

            delete gecici->sonraki;
            gecici->sonraki = 0;
        }
    }
private:
    Dugum<Tur>* dugumGetir(int sira)
    {
        if(sira<0)
            return 0;
        Dugum<Tur>* gec= ilk;
        int sayac=0;
        while(gec!=0)
        {
            if(sayac==sira)
                return gec;
            gec=gec->sonraki;
            sayac++;
        }
        return gec;
    }
    Dugum<Tur>* ilk;
};

#endif