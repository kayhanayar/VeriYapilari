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
    cout<<"postOrder:";agac.postOrder();
    cout<<endl<<"preOrder:";agac.preOrder();
    cout<<endl<<"inOrder:";agac.inOrder();
    cout<<endl<<"1.ekle"<<endl;
    cout<<"2.ara"<<endl;
    cout<<"3.cikis"<<endl;
    int secim;
    cin>>secim;

    try
    {
      if(secim==1)
      {
        int eklenecek = rand()%100;
        cout<<"eklenecek:"<<eklenecek<<endl;
        agac.ekle(eklenecek);
      }
      else if(secim==3)
        break;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    

    
  }  
}