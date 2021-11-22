#include<iostream>
#include<iomanip>
#include "Kuyruk.hpp"
using namespace std;



int main()
{
  Kuyruk kuyruk;
  while(true)
  {
    cout<<kuyruk;
    cout<<"1.ekle"<<endl;
    cout<<"2.cikar"<<endl;
    cout<<"3.cikis"<<endl;
    int secim;
    cin>>secim;

    if(secim==1)
    {
      kuyruk.ekle(rand()%100);
    }
    else if(secim ==2)
      kuyruk.cikar();
    else if(secim==3)
      break;
    
  }  
}