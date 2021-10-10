#include<iostream>

using namespace std;
int main()
{
    int sayi1  = 15;
    int sayi2  = 15;
    int*p1= &sayi1;
    int*p2 = &sayi2;
    cout<<"sayi1:"<<sayi1<<endl;
    cout<<"sayi2:"<<sayi2<<endl;
    cout<<"p1=&sayi1:"<<&sayi1<<endl;
    cout<<"p2=&sayi2:"<<&sayi2<<endl;  

    //adresler karşılaştırılıyor
    if(p1==p2)
        cout<<"adresler esit"<<endl;
    //gosterilen veriler karsilastiriliyor
    if(*p1==*p2)
        cout<<"gosterilen veriler esit *p1==*p2 -->"<<*p1<<"=="<<*p2<<endl;
}