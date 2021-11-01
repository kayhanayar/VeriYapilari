#include<iostream>
#include<iomanip>
#include "Yigin.hpp"
using namespace std;



int main()
{
    Yigin y;
    y.ekle(11);
     cout<<y;
    y.ekle(22);
      cout<<y;
    y.ekle(33);
    y.ekle(44);
    y.ekle(55);
    y.ekle(66);
    y.ekle(77);
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    y.cikar();
    cout<<y;
    y.ekle(99);
    cout<<y;

}