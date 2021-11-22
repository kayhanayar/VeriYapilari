#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include<iomanip>
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
		if(veriSayisi==kapasite)
			genislet(kapasite);
		son=(son+1)%kapasite;;
		veriSayisi++;
		veriler[son]=veri;
	}
	void cikar()
	{
		if(veriSayisi!=0)
		{
			ilk=(ilk+1)%kapasite;
			veriSayisi--;
		}
	}
    bool bosmu()
	{
		if(veriSayisi==0)
			return true;
		return false;
	}
	int getir()
	{
		if(veriSayisi!=0)
			return veriler[ilk];
		throw std::out_of_range("Kuyruk Bos");
	}
    friend ostream& operator<<(ostream& os,Kuyruk& kuyruk)
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
		int sira= kuyruk.ilk;
		for(int i=0;i<kuyruk.veriSayisi;i++)
		{
			os<<setw(2)<<kuyruk.veriler[sira]<<" :["<<sira<<"]"<<endl;
			sira=(sira+1)%kuyruk.kapasite;
			if(sira==kuyruk.son)
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
		int oncekiIndex=ilk;
		for(int i=0;i<veriSayisi;i++)
		{
			yeniAlan[i] = veriler[oncekiIndex];   
			oncekiIndex=(oncekiIndex+1)%kapasite;        
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