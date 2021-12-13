#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class IkiliAramaAgaci
{
public:

	IkiliAramaAgaci();

	~IkiliAramaAgaci();
	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,IkiliAramaAgaci& kuyruk);
	int yukseklik();
	void preOrder();
	void postOrder();
	void inOrder();
	
private:
	void levelOrder(Dugum* aktif,int level);
	void levelOrder();
	void preOrder(Dugum* aktif);
	void postOrder(Dugum* index);
	void inOrder(Dugum* index);
	int yukseklik(Dugum* aktifDugum);
	void ekle(int veri,Dugum* aktifDugum);
	bool varmi(int aranan,Dugum* aktif);
	void silDonguile(Dugum* aktif,Dugum* Ebeveyn);
	void sil(int aranan,Dugum* &aktif);
	int maxDeger(Dugum* aktif);
	int agacYukseklik;
	void boslukBirak(int adet);
	Dugum* kok;
};
//diger fonksiyonlar eklenecek
#endif