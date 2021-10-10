#include<iostream>
#include "Dikdortgen.hpp"
using namespace std;
int main()
{
    Dikdortgen* d1;

    //d1 henüz bir yeri göstermiyor fakat içerisinde belirsiz bir değer bulunabilir
    //C++ değişkenlere ilk değer atamaz. 
    //Dikkat d1 legal bir alanı gösterene kadar d1'in gösterdiği nesnenin elemanlarına erişmeyin.
    d1= new Dikdortgen(22,44);

    //d1 artık legal bir noktayı gösteriyor.
    //d1'in gösterdiği nesnenin elemanlarına erişiyoruz
    cout<<d1->genislik()<<endl;
    cout<<d1->yukseklik()<<endl;

    //d1'in gösterdiği nesne ile işimiz bitti. o yüzden onu serbest birakacagız

    delete d1;

    //d1 artık legal bir alanı göstermiyor. 
    //dikkat d1'in gösterdiği yere erişmeyin

    //Yiginda bir nesne olusturuldu
    Dikdortgen d2;

    //nesnenin  adresini d1 işaretçisine atıyoruz
    d1 = &d2;

    //d1 yığında bir nesneyi gösteriyor. 
    //Dikkkat!!!! d1 üstüne artık delete uygulanamaz. Deneyip görün.
    {
        Dikdortgen* d3= new Dikdortgen(44,55);
        cout<<"d3 etki alanina dikkat"

        //d3 isaretcisi bu etki alanı (süslü parantezler) bittiginde hafızadan silinir.
    }
    //önceki etki alanında heapden alan alında fakat serbest bırakılmadı.

    //hafıza gediği oluştu. o alanı artık bu uygulamada kullanamayız

}