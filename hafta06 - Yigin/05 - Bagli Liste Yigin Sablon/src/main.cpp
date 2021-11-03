#include "Yigin.hpp"

int main()
{
    Yigin<int> y;
    y.ekle(11);
    y.ekle(22);
    y.ekle(33);
    y.ekle(44);
    y.ekle(55);
    y.ekle(66);
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    cout<<y;
    y.cikar();
    cout<<y;  
    y.cikar();
    cout<<y;  
    y.ekle(66);
    cout<<y;   
    y.ekle(44);
    y.ekle(55);     
    cout<<y;                      
}