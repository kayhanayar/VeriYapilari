#include<iostream>
#include<iomanip>
#include "Dikdortgen.hpp"
using namespace std;



int main()
{
    //Nesnelerden dizi oluştururken sınıfın varsayılan kurucusu çağrılacaktır
    //eğer varsayılan kurucunuz bulunmuyorsa derleyici hata verecektir.
    //aşağıdaki komut satırı sadece heap'den alan almaz. Nesnelerin kurucularını da çağırır
    Dikdortgen* dizi = new Dikdortgen[5];

    //her bir hücrenin adresi ekrana çıkartılıyor
    //dikkat ederseniz her bir adres arasında 4 bayttan fazla bir aralık var
    //eğer 32 bit derleyici ile derlerseniz işaretci boyutu 4 bayt olacaktır.
    //her bir nesne 2 işaretçi tuttuğuna göre nesneler hafızada 8'er bayt kaplar.
    cout<<setw(10)<<"dizi adresleri"<<endl;
    for(int i = 0;i<5;i++)
    {
       
        cout<<setw(10)<<"dizi+"<<i<<":"<<setw(10)<<dizi+i<<endl;
    }
    //işlem bittiğinde dizi serbest bırakılıyor
    //serbest bıraklın nesnelerin yok ediciside çağrılır.
    delete [] dizi;
    cout<<"isareci boyutu:"<<sizeof(int*)<<endl;
}