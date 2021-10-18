#include<iostream>
#include<iomanip>
#include "Dikdortgen.hpp"
using namespace std;



int main()
{
    //Dikdortgen gösteren işaretçilere ait bir dizi aşağıda gösterilmektedir.

    //dizi elemanlarının türü Dikdortgen*  yani Dikdortgen gösteren bir işaretçidir
    //aşağıda sadece bir işretçi dizisi oluşturduk. 
    //Herhangi bir dikdortgen nesnesi oluşturulmadı
    //burada dizi degiskeni işaretçi gösterdiği için soluna iki yıldız gelmiştir.
    //burada Dikdortgen* gösterdiği verinin türünü sonraki * degikeninde bir işaretçi olduğunu belirtmektedir.

    Dikdortgen* * dizi = new Dikdortgen*[5];
    cout<<"eger nesne olusturulsaydi kurucunun mesaji cikardi ama cikmadi"<<endl;

    //işaretçi dizisinin adresleri gösteriliyor

    cout<<endl<<setw(10)<<"dizi adresleri"<<endl;
    for(int i = 0;i<5;i++)
    {
       
        cout<<setw(10)<<"dizi+"<<i<<":"<<setw(10)<<dizi+i<<endl;
    }

    //Dizideki her bir işaretçi tek bir nesne gösterebileceği gibi 
    //bir nesne diziside gösterebilir
    //fakat oluşturulma işlemleri tek tek yapılması gerekir
    //örneğin aşağıdaki ilk işaretçiye bir Dikdortgen nesnesinin adresi atanıyor
    dizi[0] = new Dikdortgen();
    cout<<"-------------------"<<endl;
    //ikinci işaretçi ise bir dikdörtgen dizisi gösterecektir.
    //bu şekilde tanımlanabilmesine rağmen işaretçilerin aynı tür veriyi göstermesi
    //hatayı azaltacaktır. yani bir tanesi tek nesne gösteriyorsa hepsi tek nesne göstersin
    //yada bir tanesi dizi gösteriyorsa hepsi dizi göstersin
    dizi[1] = new Dikdortgen[5];

    cout<<"------------------"<<endl;


    //diğer 3 işaretçi hiç bir yeri göstermiyor

    //heap den alınan alanları serbest bırakmak istiyoruz
    //eğer direk işaretçi dizisini serbest bırakırsak hafıza gediği oluşur.
    //Çünkü 2 işaretçi heap üzerinden alan göstermekte
    //ilk olarak onları serbest bırakmamız gerekir

    delete dizi[0];
    delete [] dizi[1];
    //diğer işaretçiler herhangi bir yer göstermiyor. onları serbest bırakmayacağız
    //bütün diziyi serbest bıraktık.
    delete [] dizi;

    int* p =new int[]{1,2,3,4};
}