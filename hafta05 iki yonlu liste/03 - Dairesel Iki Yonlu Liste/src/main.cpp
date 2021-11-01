#include<iostream>
#include<iomanip>
#include "Liste.hpp"
using namespace std;



int main()
{
    BagliListe<int>* liste = new BagliListe<int>();

    liste->ekle(11);
    liste->ekle(22);
    liste->ekle(33);
    liste->ekle(44);
    liste->ekle(55);

    cout<<*liste;
    liste->cikar(2);
    cout<<*liste;
   
    
}