#include "kutuphane.hpp"
#include<iostream>
using namespace std;

void degistir(int*sayi1,int*sayi2)
{
    cout<<"degistir("<<sayi1<<","<<sayi2<<") cagrildi"<<endl;

    int gecici = *sayi1;
    *sayi1=*sayi2;
    *sayi2 = gecici;
}