#include<iostream>
#include<iomanip>
#include "Radix.hpp"
using namespace std;



int main()
{
  int sayilar[] = {167,32,19,356,478,951,5,98,301,7,490};
  Radix *radix = new Radix(sayilar,11);
  int *siraliSayilar = radix->sirala();

  for(int i=0;i<11;i++)
    cout<<setw(5)<<siraliSayilar[i];
  cout<<endl;
  
}