#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class AVLAgaci
{
public:

	AVLAgaci();

	~AVLAgaci();
	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,AVLAgaci& kuyruk);
	int yukseklik();
	
	void preOrder();
	void postOrder();
	void inOrder();
	void boslukBirak(int adet);
private:
	int dengesizlikYonu(Dugum* aktif);
	Dugum* solaDondur(Dugum* dugum);
	Dugum* sagaDondur(Dugum* dugum);
	int minDeger(Dugum* aktif);	
	void levelOrder();
	void preOrder(Dugum* aktif);
	void postOrder(Dugum* index);
	void inOrder(Dugum* index);
	int yukseklik(Dugum* aktifDugum);
	Dugum* ekle(int veri,Dugum* aktifDugum);
	bool varmi(int aranan,Dugum* aktif);
	Dugum* sil(int veri,Dugum* aktif);
	int maxDeger(Dugum* aktif);
	Dugum* kok;
};
//diger fonksiyonlar eklenecek
#endif