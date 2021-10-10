#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    //dizizler heap alanında oluşturulduğu zaman
    //boyutları çalışma anında belirlenebilir

    int boyut;
    cout<<"dizi boyutu girin:";
    cin>>boyut;

    //heapden dizi alanı isteniyor
    //boyut kadar tamsayı barındıracak bir alan isteniyor
    //new operatörü işlem bittiğinde alınan alanın başlangıç adresini getirir
    //bu adres soldaki işaretçiye atanır.
    int* dizi = new int[boyut];

    for(int i=0;i<boyut;i++)
    {
        //rand() fonksiyonu rastgele değer getirir
        //getirilen değeri %100 işlemine tabi tutarsak yani 100'e modunu alırsak
        //diziye atanan sayıları 0-100 arasında olmasını sağlarız
        dizi[i] = rand()%100;
    }

    //Aşağıdaki döngü ile dizinin her bir hücresinin başlangıç adresi ile
    //o adreste bulunan veri ekrana çıkartılmaktadır.
    cout<<setw(10)<<"adres"<<setw(10)<<"deger"<<endl;
    for(int i = 0;i<boyut;i++)
    {
       
        cout<<setw(10)<<dizi+i<<setw(10)<<*(dizi+i)<<endl;
    }

    //dizi ile işimiz bittiğinde serbest bırakmamız gerekir
    //diziler serbest bırakılırken delete operatöründen sonra [ ] operatörleri kullanılmaktadır.
    delete [] dizi;

}