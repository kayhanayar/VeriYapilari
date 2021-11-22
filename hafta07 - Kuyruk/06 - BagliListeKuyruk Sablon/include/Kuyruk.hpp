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
    friend ostream& operator<<(ostream& os,Kuyruk& kuyruk)
	{
		
		if(kuyruk.ilk==0)
			os<<"----KUYRUK BOS----"<<endl;
		else
		{
			if(kuyruk.ilk==kuyruk.son)
				os<<setw(5)<<"ilk-son->";
			else
				os<<setw(5)<<"ilk ---->";
		}
		Dugum<Tur>*gec= kuyruk.ilk;
		while(gec!=0)
		{
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