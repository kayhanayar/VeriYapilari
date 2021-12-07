#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>

using namespace std;
const int MAX = 100;
class IkiliAramaAgaci
{
public:
	enum HUCREDURUMU{
		HUCRE_BOS=0,
		HUCRE_DOLU=1
	};
	IkiliAramaAgaci();

	~IkiliAramaAgaci();
	int bul(int veri);
	void ekle(int veri);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,IkiliAramaAgaci& kuyruk);
	int yukseklik();
	void preOrder();
	void postOrder();
	void inOrder();
private:
	void preOrder(int index);
	void postOrder(int index);
	void inOrder(int index);
	int yukseklik(int index);
	int bul(int aranan,int index);
	void sil(int veri,int index);
	int sol(int index);
	int sag(int index);
	int ebeveyn(int index);
	bool sagVarmi(int index);
	bool solVarmi(int index);
	bool varmi(int index);

	int* hucreler;
	HUCREDURUMU hucreDurumlari[MAX];
};
//diger fonksiyonlar eklenecek
#endif