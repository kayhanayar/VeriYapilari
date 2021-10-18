#include<iostream>
#include<iomanip>
using namespace std;

//asagidaki fonksiyon cagrıldığında
//kendisine verilen argüman değeri kada eleman alabilecek 
//bir dizi oluşturmakta ve dizinin içerisindeki
//elemanlara rastgele deger atamaktadır.
//işlem bittiğinde dizinin başlangıç adresi kullanıcıya döndürülmektedir.

int* diziOlusturRastgeleAta(int boyut)
{
    int * dizi = new int[boyut];
    for(int i=0;i<boyut;i++)
    {
        dizi[i] = rand()%100;
    }

    return dizi;
}
//aşağıdaki fonksiyon kendisine argüman olarak verilen dizinin adresi
//ile boyutunu kullanarak dizinin elemanlarını ve bulundukları adresleri
//ekrana çıkarmaktadır.
void diziAdresleriIleYazdir(int* dizi,int boyut)
{
    cout<<"adres     "<<setw(10)<<" -> deger"<<endl;
    for(int i = 0;i<boyut;i++)
    {
       
        cout<<dizi+i<<"-> "<<*(dizi+i)<<endl;
    }   
}

int main()
{

    //main içerisinde farklı bir kullanıcı olduğumuzu düşünmemiz gerekir
    //artık yukarıda tanımlanan fonksiyonların kullanıcılarıyız.
    //içerisinde yapılan işlemlerden çok sonuçları ile ilgileniyoruz.

    int boyut;
    cout<<"dizi boyut:";
    cin>>boyut;
    //önce dizi oluşturuluyor ve adresi getiriliyor

    int* dizi = diziOlusturRastgeleAta(boyut);

    //adres kullanılarak dizinin elemanları ekrana çıkartılıyor
    diziAdresleriIleYazdir(dizi,boyut);

    //işlem bittikten sonra heap den alınan alan serbest bırakılmalıdır.

    delete[] dizi;

}