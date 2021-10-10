#include<iostream>

using namespace std;
int main()
{
    int sayi  = 15;

    cout<<"sayi:"<<sayi<<endl;

    cout<<"&sayi:"<<&sayi<<endl;

    //işaretçi tanımlanırken türden sonra * operatörü kullanılır.
    //tür işaretçinin gösterdiği veriyi temsil eder
    //işaretçinin tuttuğu adreste bulunan verinin türü
    int* isaretci = &sayi;

    //işaretcinin içerisindeki değer ekrana çıkartılmaktadır.
    //sayi değişkeninin bulunduğu adres

    cout<<"isaretci:"<<isaretci<<endl;

    //işaretçinin gösterdiği veri ekrana çıkmaktadır.
    cout<<"*isaretci:"<<*isaretci<<endl;

    //gösterilen veri 1 arttırılıyor
    (*isaretci)++;

    cout<<"sayi:"<<sayi<<endl;
}