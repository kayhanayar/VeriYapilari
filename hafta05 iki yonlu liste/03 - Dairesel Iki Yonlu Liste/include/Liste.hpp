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
         dugumSayisi = 0;
         
    }
    ~BagliListe()
    {
        Dugum<Tur>* gecici = ilk;

        for(int i=0;i<dugumSayisi;i++)
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
    void ekle(int sira,const Tur& veri)
    {
        //sira 0 ise ve ilk düğüm yoksa
        if(sira==0&&ilk==0)
        {
            ilk = new Dugum<Tur>(veri);
            ilk->sonraki =ilk;
            ilk->onceki = ilk;
        }
        else
        {
            Dugum<Tur>* aktifDugum = dugumGetir(sira);

            if(aktifDugum==0) return;

            Dugum<Tur>* yeni = new Dugum<Tur>(veri);

            Dugum<Tur>* onceki = aktifDugum->onceki;
            
            aktifDugum->onceki = yeni;
            yeni->sonraki = aktifDugum;
            yeni->onceki = onceki;
            
            if(onceki)
                onceki->sonraki = yeni;
            else
            {
                ilk = yeni;
                ilk->onceki=yeni;
                ilk->sonraki=yeni;
            }
                
        }

        dugumSayisi++;
    }
    void ekle(const  Tur& veri)
    {
       
        Dugum<Tur>* yeni = new Dugum<Tur>(veri);

        if(ilk==0)
        {
            ilk = yeni;
            ilk->sonraki = yeni;
        }
        else
        {
            Dugum<Tur>* gec = ilk;
            
            while(gec->sonraki!=ilk)
                gec=gec->sonraki;
            
            gec->sonraki=yeni;
            yeni->onceki=gec;
            yeni->sonraki = ilk;
            ilk->onceki=yeni;
        }
        dugumSayisi++;
    }

    friend ostream& operator<<(ostream& os,const BagliListe& liste)
    {
        using namespace std;
        Dugum<Tur>* gecici = liste.ilk;
        cout<<"-------------------------------"<<endl; 
        cout<<setw(10)<<"Adres:"<<setw(10)<<"Veri:"<<setw(15)<<"onceki:"<<setw(15)<<"Sonraki:"<<endl; 
        cout<<"-------------------------------"<<endl;  
        for(int i=0;i<liste.dugumSayisiGetir();i++)
        {
            cout<<setw(10)<<gecici<<setw(10)<<gecici->veri<<setw(15)<<gecici->onceki<<setw(15)<<gecici->sonraki<<endl;
            cout<<"-------------------------------"<<endl;
            gecici= gecici->sonraki;  
        }
        return os;
    }
    void cikar()
    {
        if(ilk==0)  return;

        if(ilk->sonraki==ilk)
        {
            delete ilk;
            ilk=0;
        }
        else
        {
            Dugum<Tur>* gecici = sondanBirOncekiGetir();
            delete gecici->sonraki;
            gecici->sonraki = ilk;
            ilk->onceki = gecici;
        }
        dugumSayisi--;
    }
    void cikar(int sira)
    {


        Dugum<Tur>* silinecek = dugumGetir(sira);
        
        if(silinecek==0) return;

        //sirayı daha önce kontrol ettiğimiz için
        //fonksiyonun var olan bir düğümü getirdiğinden eminiz

        Dugum<Tur>* onceki = silinecek->onceki;
        Dugum<Tur>* sonraki = silinecek->sonraki;

        if(sonraki!=ilk)
            sonraki->onceki = onceki;
        else
            ilk->onceki= onceki;

        if(onceki)
            onceki->sonraki = sonraki;
        else
        {
            Dugum<Tur>* son = dugumGetir(dugumSayisi-1);
            son->sonraki = ilk->sonraki;
            ilk = sonraki;  
            ilk->onceki = son;          
        }
            
        delete silinecek;
        dugumSayisi--;
    }
    //nesnenin const referans olarak verildiği fonksiyonlarda
    //sadece const olarak tanımlanmış fonksiyonlar çağrılabilir
    //operator << fonksiyonu içerisinde listenin sadece aşağıdaki fonksiyonu 
    //çağrılabilir. Çünkü sadece bu fonksiyon const.
    int dugumSayisiGetir() const
    {
        return dugumSayisi;
    }
private:
    Dugum<Tur>* sondanBirOncekiGetir()
    {
        if(ilk==0)
            return 0;
        if(ilk->sonraki==0)
            return ilk;
        
        Dugum<Tur>* gec= ilk;
        while(gec->sonraki->sonraki!=ilk)
            gec=gec->sonraki;

        return gec;
    }
    Dugum<Tur>* dugumGetir(int sira)
    {
        if(sira<0||sira>=dugumSayisi)
            return 0;
        
        Dugum<Tur>* gec= ilk;
        
        for(int i=0;i<sira;i++)
        {
            gec=gec->sonraki;
        }
        return gec;
    }


    Dugum<Tur>* ilk;
    int dugumSayisi;
};

#endif