#include<iostream>
#include<iomanip>
#include "Kuyruk.hpp"
using namespace std;



int main()
{
  Kuyruk<int> kuyruk;
  while(true)
  {
    cout<<kuyruk;
    cout<<"1.ekle"<<endl;
    cout<<"2.cikar"<<endl;
    cout<<"3.enbuyukCikar"<<endl;
    cout<<"4.enbuyukGetir"<<endl;
    cout<<"5.cikis"<<endl;
    int secim;
    cin>>secim;
    try
    {
      if(secim==1)
      {
        kuyruk.ekle(rand()%100);
      }
      else if(secim ==2)
        kuyruk.cikar();
      else if(secim==3)
        kuyruk.enYuksegiCikar();
      else if(secim==4)
        cout<<kuyruk.enBuyukGetir()<<endl;
      else if(secim==5)
        break;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    

    
  }  
}