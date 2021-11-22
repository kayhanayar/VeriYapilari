#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include <iomanip>
using namespace std;

template<typename Tur>
class Kuyruk
{
public:
	Kuyruk()
	{
		ilk=0;son = -1;
		veriler=0;
		veriSayisi=0;
		kapasite = 0;
		genislet(5);
	}
	~Kuyruk()
	{
		delete[] veriler;
	}
	void ekle(Tur veri)
	{
		if(son==kapasite-1)
			genislet(kapasite);
		son++;
		veriSayisi++;
		veriler[son]=veri;
	}
	void cikar()
	{
		if(veriSayisi!=0)
		{
			ilk++;
			veriSayisi--;
		}
	}
    bool bosmu()
	{
		if(veriSayisi==0)
			return true;
		return false;
	}

	Tur getir()
	{
		if(veriSayisi!=0)
			return veriler[ilk];
		throw std::out_of_range("Kuyruk Bos");
	}
	friend ostream& operator<<(ostream& os,Kuyruk<Tur>& kuyruk)
	{
		if(kuyruk.veriSayisi==0)
			os<<"----KUYRUK BOS----"<<endl;
		else
		{
			if(kuyruk.veriSayisi==1)
				os<<setw(5)<<"ilk-son->";
			else
				os<<setw(5)<<"ilk ---->";
		}
		for(int i=kuyruk.ilk;i<=kuyruk.son;i++)
		{
			os<<setw(2)<<kuyruk.veriler[i]<<" :["<<i<<"]"<<endl;
			if(i==kuyruk.son-1)
				os<<"son ---->";
			else
				os<<setw(9)<<"    ";     
		}
		cout<<endl;
		return os;
	}
private:
	void genislet(int boyut)
	{
		Tur *yeniAlan = new Tur[boyut+kapasite];
		int yeniIndex=0;
		for(int i=ilk;i<=son;i++)
		{
			yeniAlan[yeniIndex] = veriler[i];   
			yeniIndex++;        
		}
		if(veriler)
			delete[] veriler;
		son=veriSayisi-1;
		ilk=0;
		veriler = yeniAlan;
		kapasite += boyut;
	}
	int kapasite;
    int ilk;
	int son;
	int veriSayisi;
	Tur* veriler;
};
#endif