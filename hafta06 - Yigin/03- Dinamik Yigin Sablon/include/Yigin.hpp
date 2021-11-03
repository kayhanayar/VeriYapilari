#ifndef Yigin_hpp
#define Yigin_hpp
#include<iostream>
using namespace std;

template<typename Tur>
class Yigin
{
public:
	Yigin()
	{
		tepe = -1;
		veriler=0;
		kapasite = 5;
		genislet(kapasite);
	}
	~Yigin()
	{
    	delete[] veriler;
	}
	void ekle(Tur veri)
	{
		if(tepe==kapasite-1)
			genislet(kapasite);

		tepe++;
		veriler[tepe]=veri;		
	}
	void cikar()
	{
		if(tepe!=-1)
		{
			tepe--;
		}
	}
    bool bosmu()
	{
		if(tepe==-1)
			return true;
		return false;
	}	
    bool dolumu()
	{
		if(tepe==kapasite-1)
			return true;
		return false;
	}
	Tur getir()
	{
		if(tepe!=-1)
			return veriler[tepe];
		throw std::out_of_range("Yigin Bos");
	}
    friend ostream& operator<<(ostream& os,Yigin& yigin)
	{
		os<<setw(5)<<"---->";
		for(int i=0;i<=yigin.tepe;i++)
		{
			os<<yigin.veriler[yigin.tepe-i]<<endl;
			os<<setw(5)<<"    ";     
		}
		cout<<endl;
		return os;
	}
private:
	void genislet(int boyut)
	{
		Tur *yeniAlan = new Tur[boyut+kapasite];
		for(int i=0;i<=tepe;i++)
		{
			
			yeniAlan[i] = veriler[i];   
			
		}
		if(veriler)
			delete[] veriler;
		veriler = yeniAlan;
		kapasite += boyut;
	
	}
	int kapasite;
    int tepe;
	Tur* veriler;
};

#endif