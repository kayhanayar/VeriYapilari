#include<iostream>

using namespace std;
int main()
{
    int sayilar[] = {1,2,3,4,5,6};

    //ilk eleman 0 indisi ile erişilir
    cout<<"sayilar[0]="<<sayilar[0]<<endl;
    //son elemana boyut-1 yani 6-1=5 değeri ile erişilir.
    cout<<"sayilar[5]="<<sayilar[5]<<endl;


    // indis dizinin sınırını aştı.
    //fakat c++ derleyicisi böyle bir durumu kontrol etmeden kodunuzu derleyecektir.
    //programı çalıştırdığınızda aşağıdaki satır bilinmeyen bir davranış üretecektir.
    //yani işlem sonucunda ne olacağı bilinmemektir.
    cout<<"sayilar[6]="<<sayilar[6]<<endl; 

    //aynı şekilde aşağıdaki satırda da indis sınırı aşıldı.
    //C++ derleyicisi hata vermeyecektir.
    //fakat program çalıştığında beklenmedik sonuçlar oluşabilir.
    cout<<"sayilar[-1]="<<sayilar[-1]<<endl; 

    //c++ programcının kullandığı indis değerlerini kontrol etmemektedir.
    //Böylesi bir kontrol mekanizması elde edilen makine kodunun performansını düşürebilir.
    //sorumluluk programcıdadır.

}