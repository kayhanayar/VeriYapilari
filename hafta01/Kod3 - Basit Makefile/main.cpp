#include<iostream>
#include "Dikdortgen.hpp"

int main()
{
    Dikdortgen d1(40,60);
    
    using namespace std;

    cout<<"d1.genislik :"<<d1.genislik()<<endl;
    cout<<"d1.yukseklik:"<<d1.yukseklik()<<endl;

    cout<<"------------------------------------"<<endl;
    Dikdortgen d2;
    
    cout<<"d2.genislik :"<<d2.genislik()<<endl;
    cout<<"d2.yukseklik:"<<d2.yukseklik()<<endl;  
}