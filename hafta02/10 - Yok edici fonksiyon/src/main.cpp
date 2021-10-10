
#include<iostream>
#include "Dikdortgen.hpp"
using namespace std;
int main()
{
    Dikdortgen* d1= new Dikdortgen(22,44);

    cout<<d1->genislik()<<endl;
    cout<<d1->yukseklik()<<endl;
    //işimiz bittikten sonra heapten alınan alan serbest bırakmak istiyoruz
    
    
    delete d1;
    //d1 in gösterdiği nesne silinmeden önce nesnenin yok edici fonksiyonu çağrılacaktır.


}