#include<iostream>
#include<iomanip>
#include "IkiliAramaAgaci.hpp"
using namespace std;



int main()
{
  IkiliAramaAgaci agac;
  int sayilar[]= {50,30,70,20,10,5,18,90,100,80,88,75,60,68,40,25,22,28};
  int sira=0;
  while(true)
  {

    cout<<agac;
    cout<<"1.ekle"<<endl;
    cout<<"2.sil"<<endl;
    cout<<"3.enbuyukCikar"<<endl;
    cout<<"4.enbuyukGetir"<<endl;
    cout<<"5.cikis"<<endl;
    int secim;
    cin>>secim;
    try
    {
      if(secim==1)
      {
        if(sira<18)
        {
          int eklenen = sayilar[sira++];
          cout<<"eklenen:"<<eklenen<<endl;
          agac.ekle(eklenen);
        }
        
      }
      else if(secim==2)
      {
        int aranan;
        cin>>aranan;
        agac.sil(aranan);
      }
      else if(secim==5)
        break;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    
  }  

}