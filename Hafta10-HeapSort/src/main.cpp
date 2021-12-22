#include<iostream>
#include<iomanip>
#include "Heapsort.hpp"
using namespace std;



int main()
{
  HeapSort heap;
  while(true)
  {
    cout<<heap;
    cout<<"1.ekle"<<endl;
    cout<<"2.cikar"<<endl;
    cout<<"3.enkucuguGetir"<<endl;
    cout<<"4.cikis"<<endl;
    int secim;
    cin>>secim;
    try
    {
      if(secim==1)
      {
        heap.ekle(rand()%100);
      }
      else if(secim ==2)
        heap.cikar();
      else if(secim==3)
        cout<<heap.getir()<<endl;
      else if(secim==4)
        break;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    

    
  }  
}