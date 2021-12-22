#include "Heapsort.hpp"
#include<exception>
#include<iomanip>
HeapSort::HeapSort()
{
	elemanSayisi=0;
}
int HeapSort::getir()
{
	if(elemanSayisi!=0)
		return veriler[0];
	throw std::out_of_range("HeapSort::getir()- Eleman yok");
}
void HeapSort::cikar()
{
	if(elemanSayisi!=0)
	{
		veriler[0]= veriler[elemanSayisi-1];
		elemanSayisi--;
		asagiDuzenle(0);
	}
	
}
void HeapSort::ekle(int veri)
{
	if(elemanSayisi<MAX)
	{
		veriler[elemanSayisi]=veri;
		elemanSayisi++;
		yukariDuzenle(elemanSayisi-1);
	}
}
void HeapSort::yukariDuzenle(int index)
{
	int ebeveyn = ebeveynIndex(index);

	if(veriler[index]<veriler[ebeveyn])
	{
		int gecici = veriler[index];
		veriler[index] = veriler[ebeveyn];
		veriler[ebeveyn] = gecici;
		yukariDuzenle(ebeveyn);

	}
}
void HeapSort::asagiDuzenle(int index)
{
	int solCocuk = solCocukIndex(index);
	int sagCocuk = sagCocukIndex(index);
	int enKucukIndex;
	if(sagCocuk>=MAX)//sağ çocuk yok mu?
	{
		if(solCocuk>=MAX)//sol da yok
		{
			return;
		}
		enKucukIndex =solCocuk;
	}
	else
	{
		if(veriler[solCocuk]<veriler[sagCocuk])
		{
			enKucukIndex= solCocuk;
		}
		else
		{
			enKucukIndex = sagCocuk;
		}
	}

	if(veriler[index]<veriler[enKucukIndex])
	{
		int gecici = veriler[index];
		veriler[index] = veriler[enKucukIndex];
		veriler[enKucukIndex] = gecici;
		asagiDuzenle(enKucukIndex);
	}
}
int HeapSort::ebeveynIndex(int index)
{
	return (index-1)/2;
}
int HeapSort::solCocukIndex(int index)
{
	return 2*index+1;
}
int HeapSort::sagCocukIndex(int index)
{
	return 2*index+2;
}

ostream& operator<<(ostream& os,HeapSort& heap)
{
	for(int i=0;i<heap.elemanSayisi;i++)
	{
		os<<setw(4)<<heap.veriler[i];
	}
	os<<endl;
	return os;
}