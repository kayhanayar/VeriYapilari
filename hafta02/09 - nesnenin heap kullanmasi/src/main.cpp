
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
    //d1'in gösterdiği nesnede heapten 2 adet alan almıştı
    //fakat onları serbest bırakmdan d1'i sildik.
    //hafıza gediği oluştu.

    //hafıza getiği oluşmaması için 14. satırdaki silme komutundan önce aşağıdakiler yazılması gerekirdi.
    //böylece nesnenin aldığı alanlar nesne silinmeden önce serbest bırakılmış olurdu.

    //delete d1->genislikAdresGetir();
    //delete d1->genislikAdresGetir();


}