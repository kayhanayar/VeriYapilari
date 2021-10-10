#include<iostream>

using namespace std;
int main()
{
    // tam sayı ve ondalık değişkenlerin hafızada tutulması.
    //ikiside aynı değere sahip olmasına rağmen 
    //hafızadaki görüntüleri farklıdır.
    //tam sayılar direk ikili karşılıklarını alırlar.
    //ondalık sayıların temsil edilmesi farklıdır.
    
    int sayi = 15; //32 bit tamsayı
    /*
        adres   2-li veri
        1997    00001111
        1998    00000000
        1999    00000000
        2000    00000000

        Birleştirildiğinde : 00001111 00000000 00000000 00000000
    */
 
   float dsayi = 15.0f;
    /*
        adres   2-li veri
        1997    00000000
        1998    00000000
        1999    01110000
        2000    01000001

        Birleştirildiğinde : 00000000 00000000 01110000 01000001
    */

   //degiskenlerin hafıza kapladıkları alan gösterilmektedir.
   cout<<sizeof(sayi)<<endl;
   cout<<sizeof(dsayi)<<endl;
}