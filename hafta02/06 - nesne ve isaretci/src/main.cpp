#include<iostream>
#include "Dikdortgen.hpp"
using namespace std;
int main()
{
    //Dikdortgen yigin hafızasında oluşturulur. Neden?
    Dikdortgen d1(15,20);
    
    //Dikdortgen gösteren isaretci tanimlaniyor
    Dikdortgen* p1= &d1;

    cout<<"&p                       :"<<p1<<endl;
    cout<<"p->genislikAdresGetir()  :"<<p1->genislikAdresGetir()<<endl;
    cout<<"p->yukseklikAdresGetir() :"<<p1->yukseklikAdresGetir()<<endl;
}