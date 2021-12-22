#ifndef HeapSort_hpp
#define HeapSort_hpp
#include<iostream>
const int MAX = 100;
using  namespace std;
class HeapSort
{
public:
    HeapSort();
    
    void ekle(int veri);
    int getir();
    void cikar();
    
private:
    friend ostream& operator<<(ostream& os,HeapSort& heap);
    int ebeveynIndex(int index);
    int solCocukIndex(int index);
    int sagCocukIndex(int index);
    void yukariDuzenle(int index); //heapifyUp
    void asagiDuzenle(int index);
    int veriler[MAX];
    int elemanSayisi;
};

#endif