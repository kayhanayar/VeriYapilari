#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include<iomanip>
#include "KuyrukDugum.hpp"
using namespace std;


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
			KuyrukDugum* gec= ilk;
			ilk=ilk->sonraki;
			delete gec;
		}
	}
	void enKucuguCikar()
	{
		KuyrukDugum* onceki = enKucukOnceki();
		if(onceki)
		{
			if(onceki->sonraki==son)
				son=onceki;
			KuyrukDugum* sil = onceki->sonraki;
			onceki->sonraki= sil->sonraki;
			delete sil;			
		}
		else
		{
			if(ilk==0)
				return;
			KuyrukDugum* sil= ilk;
			ilk=ilk->sonraki;
			delete sil;
		}
	}
	KuyrukDugum* enKucukOnceki()
	{
		if(ilk==0)	return 0;

		KuyrukDugum* gec = ilk;
		KuyrukDugum*onceki=0;
		HuffmanDugum* enKucuk = gec->veri;
		
		while(gec->sonraki!=0)
		{
			if((*gec->sonraki->veri)<(*enKucuk))
			{
				enKucuk = gec->sonraki->veri;
				onceki = gec;
			}
			gec= gec->sonraki;
		}
		return onceki;
	}
	void ekle(HuffmanDugum* veri)
	{
		if(ilk==0)
		{
			ilk=new KuyrukDugum(veri);
			son= ilk;

		}
		else
		{
			KuyrukDugum*yeni = new KuyrukDugum(veri);
			son->sonraki = yeni;
			son = yeni;

		}
	}
	void cikar()
	{
		if(ilk!=0)
		{
			KuyrukDugum*gec = ilk->sonraki;
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
	HuffmanDugum* getir()
	{
		if(ilk!=0)
			return ilk->veri;
		throw std::out_of_range("Kuyruk Bos");
	}
	HuffmanDugum* enKucukGetir()
	{
		KuyrukDugum* onceki = enKucukOnceki();
	
		if(onceki)
			return onceki->sonraki->veri;
		if(ilk!=0)
			return ilk->veri;
		throw std::out_of_range("Kuyruk Bos");
	}
    int elemanSayisi()
	{
		int es = 0;

		KuyrukDugum* gec= ilk;
		while(gec!=0)
		{
			es++;
			gec= gec->sonraki;
		}
		return es;
	}
	friend ostream& operator<<(ostream& os,Kuyruk& kuyruk)
	{
		
		HuffmanDugum* enkucuk ;
		if(kuyruk.ilk==0)
			os<<"----KUYRUK BOS----"<<endl;
		else
		{
			enkucuk = kuyruk.enKucukGetir();
			if(kuyruk.ilk==kuyruk.son)
				os<<setw(5)<<"ilk-son->";
			else
				os<<setw(5)<<"ilk ---->";
		}
		KuyrukDugum*gec= kuyruk.ilk;
		while(gec!=0)
		{
			
			if(*enkucuk==*gec->veri)
				os<<setw(2)<<*gec->veri<<"*:*"<<gec->sonraki<<endl;
			else
			 	os<<setw(2)<<*gec->veri<<" : "<<gec->sonraki<<endl;
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
	KuyrukDugum* ilk;
	KuyrukDugum*son;
};

#endif