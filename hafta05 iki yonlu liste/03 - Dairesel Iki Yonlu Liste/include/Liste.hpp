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
		Dugum<Tur>* gec = dugumGetir(sira);
		if (gec)
		{
			Dugum<Tur>* yeniDugum = new Dugum<Tur>(veri);
			Dugum<Tur>* oncekiDugum = gec->onceki;
			if (gec == ilk)
				ilk = yeniDugum;
			oncekiDugum->sonraki = yeniDugum;
			yeniDugum->onceki = oncekiDugum;
			yeniDugum->sonraki = gec;
			gec->onceki = yeniDugum;
			dugumSayisi++;
		}
    }
    void ekle(const  Tur& veri)
    {
       
		Dugum<Tur>* yeni = new Dugum<Tur>(veri);

		if (ilk == 0)
		{
			ilk = yeni;
			ilk->onceki = ilk;
			ilk->sonraki = ilk;
		}
		else
		{
			Dugum<Tur>* gec = dugumGetir(dugumSayisi - 1);
			gec->sonraki = yeni;
			yeni->onceki = gec;
			yeni->sonraki = ilk;
			ilk->onceki = yeni;
		}
		dugumSayisi++;
    }

    friend ostream& operator<<(ostream& os,const BagliListe& liste)
    {
        using namespace std;
		Dugum<Tur>* gec = liste.ilk;
		os << setw(15) << "adres" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;

		for (int i = 0; i < liste.dugumSayisi; i++)
		{
			os << setw(15) << gec << setw(15) << gec->veri << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
			gec = gec->sonraki;
		}
		os << "----------------------" << endl;
		return os;
    }
    void cikar()
    {
		if (ilk == 0)return;
		if (ilk->sonraki == ilk)
		{
			delete ilk;
			ilk = 0;
		}
		else
		{
			Dugum<Tur>* gec = dugumGetir(dugumSayisi - 2);


			delete gec->sonraki;

			gec->sonraki = ilk;
			ilk->onceki = gec;
		}
		dugumSayisi--;
    }
    void cikar(int sira)
    {


        Dugum<Tur>* gec = dugumGetir(sira);

		if (gec)
		{
			 Dugum<Tur>* oncekiDugum = gec->onceki;
			 Dugum<Tur>* sonrakiDugum = gec->sonraki;

			oncekiDugum->sonraki = sonrakiDugum;
			sonrakiDugum->onceki = oncekiDugum;
			if (ilk->onceki == ilk)
				ilk = 0;
			if (gec == ilk)
				ilk = sonrakiDugum;
	
			delete gec;

			dugumSayisi--;
		}
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
	Dugum<Tur>* dugumGetir(int sira)
	{
		if (sira < 0 || sira >= dugumSayisi)
			return 0;
		Dugum<Tur>* gec = ilk;
		for (int i = 0; i < sira; i++)
			gec = gec->sonraki;

		return gec;

	}

    Dugum<Tur>* ilk;
    int dugumSayisi;
};

#endif