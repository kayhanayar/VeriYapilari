#include<iostream>

using namespace std;
int main()
{
    //aşağıdaki dizi yığın hafızasında oluşturulmaktadır
    //o yüzden boyutu sabit olmalıdır. 
    //(c99) standartı ile değişen boyutlu diziler çıkmasına rağmen (c11) standartı ile bu özellik opsiyonel yapılmıştır.
    //bazı derleyicler izin vermesine rağmen kodunuz farklı platformlara adapte etmekte sıkıntı yaşayacaktır
    //o yüzden boyutu daima sabit verin.
    //dizinin elemanlarına ilk değer atanmadı
    int sayilar[6];

    //aşağıdaki diziyi oluştururken değerleride atanıyor
    //Böylece boyutuda atama anında verilmiş oluyor
    //6 eleman atanacak dizinin boyutu 6 olur.
    int d1[] = {2,3,4,5,6,7};

    //  d1=sayilar ;    şeklinde bir atama söz konusu değildir.
    //bütün elemanların tek tek atanması gerekir.
    sayilar[0] = d1[0];
    sayilar[1] = d1[1];
    sayilar[2] = d1[2];
    sayilar[3] = d1[3];
    sayilar[4] = d1[4];
    sayilar[5] = d1[5];
    //veya döngü kullanılabilir
    for(int i=0;i<6;i++)
        sayilar[i] = d1[i];


    //Değerlerini yazdırmak için
    for(int i=0;i<6;i++)
    {
        cout<<"sayilar["<<i<<"]="<<sayilar[i]<<endl;
    }

}