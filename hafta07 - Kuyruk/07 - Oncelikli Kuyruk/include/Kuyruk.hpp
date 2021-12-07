#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;


template<typename Tur>
class Kuyruk
{
public:
	Kuyruk()
	{
		ilk=son=0;
	}
	~Kuyruk()
	{
		while(ilk!=0)
		{
			Dugum<Tur>* gec= ilk;
			ilk=ilk->sonraki;
			delete gec;
		}
	}
	void enYuksegiCikar()
	{
		Dugum<Tur>* onceki = enYukseginOncekiDugum();
		if(onceki)
		{
			if(onceki->sonraki==son)
				son=onceki;
			Dugum<Tur>* sil = onceki->sonraki;
			onceki->sonraki= sil->sonraki;
			delete sil;			
		}
		else
		{
			if(ilk==0)
				return;
			Dugum<Tur>* sil= ilk;
			ilk=ilk->sonraki;
			delete sil;
		}
	}
	Dugum<Tur>* enYukseginOncekiDugum()
	{
		if(ilk==0)	return 0;

		Dugum<Tur>* gec = ilk;
		Dugum<Tur>*onceki=0;
		Tur enBuyuk = gec->veri;
		
		while(gec->sonraki!=0)
		{
			if(gec->sonraki->veri>enBuyuk)
			{
				enBuyuk = gec->sonraki->veri;
				onceki = gec;
			}
			gec= gec->sonraki;
		}
		return onceki;
	}
	void ekle(Tur veri)
	{
		if(ilk==0)
		{
			ilk=new Dugum<Tur>(veri);
			son= ilk;

		}
		else
		{
			Dugum<Tur>*yeni = new Dugum<Tur>(veri);
			son->sonraki = yeni;
			son = yeni;

		}
	}
	void cikar()
	{
		if(ilk!=0)
		{
			Dugum<Tur>*gec = ilk->sonraki;
			delete ilk;
			ilk=gec;
			if(ilk==0)
				son=0;
		}
	}
    bool bosmu()
	{
		if(ilk==0)
			return true;
		return false;

	}
	Tur getir()
	{
		if(ilk!=0)
			return ilk->veri;
		throw std::out_of_range("Kuyruk Bos");
	}
	Tur enBuyukGetir()
	{
		Dugum<Tur>* onceki = enYukseginOncekiDugum();
	
		if(onceki)
			return onceki->sonraki->veri;
		if(ilk!=0)
			return ilk->veri;
		throw std::out_of_range("Kuyruk Bos");
	}
    friend ostream& operator<<(ostream& os,Kuyruk& kuyruk)
	{
		
		Tur enbuyuk = -1;
		if(kuyruk.ilk==0)
			os<<"----KUYRUK BOS----"<<endl;
		else
		{
			enbuyuk = kuyruk.enBuyukGetir();
			if(kuyruk.ilk==kuyruk.son)
				os<<setw(5)<<"ilk-son->";
			else
				os<<setw(5)<<"ilk ---->";
		}
		Dugum<Tur>*gec= kuyruk.ilk;
		while(gec!=0)
		{
			
			if(enbuyuk==gec->veri)
				os<<setw(2)<<gec->veri<<"*:*"<<gec->sonraki<<endl;
			else
			 	os<<setw(2)<<gec->veri<<" : "<<gec->sonraki<<endl;
			if(gec->sonraki==kuyruk.son)
				os<<"son ---->";
			else
				os<<setw(9)<<"    ";   
			gec = gec->sonraki;  
		}

		os<<endl;
		return os;
	}
private:
	Dugum<Tur>* ilk;
	Dugum<Tur>*	son;
};

#endif