#include<iostream>
#include<iomanip>
#include "IkiliAramaAgaci.hpp"
using namespace std;



int main()
{
  IkiliAramaAgaci agac;
  while(true)
  {
    cout<<agac;
    cout<<"1.ekle"<<endl;
    cout<<"2.ara"<<endl;
    cout<<"3.enbuyukCikar"<<endl;
    cout<<"4.enbuyukGetir"<<endl;
    cout<<"5.cikis"<<endl;
    int secim;
    cin>>secim;
    try
    {
      if(secim==1)
      {
        agac.ekle(rand()%100);
      }
      else if(secim==2)
      {
        int aranan;
        cin>>aranan;
     
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