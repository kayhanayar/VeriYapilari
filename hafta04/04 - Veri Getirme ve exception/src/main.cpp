#include<iostream>
#include<iomanip>
#include<vector>
#include "BagliListe.hpp"
using namespace std;



int main()
{



    BagliListe<int>* liste = new BagliListe<int>();
    liste->ekle(11);
    liste->ekle(22);
    liste->ekle(33);
    liste->ekle(44);
    liste->ekle(55);
    try
    {
      cout<<liste->getir(0)<<endl;
      cout<<liste->getir(1)<<endl;
      cout<<liste->getir(2)<<endl;
      cout<<liste->getir(3)<<endl;
      cout<<liste->getir(4)<<endl;
       
    }
    catch(std::out_of_range& e)
    {
        cout<<e.what()<<endl;
    }

    

}