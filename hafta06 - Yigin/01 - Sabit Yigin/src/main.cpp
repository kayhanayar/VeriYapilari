#include<iostream>
#include<iomanip>
#include "Yigin.hpp"
using namespace std;



int main()
{
    Yigin y;
    y.ekle(11);
    y.ekle(22);
    y.ekle(33);
    y.ekle(44);
    y.ekle(55);
    y.ekle(66);
    y.ekle(77);
    cout<<y;
}