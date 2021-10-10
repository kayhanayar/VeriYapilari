#include<iostream>

using namespace std;
//öz yineleme fonksiyonun kendisini çağırması olarak adlandırılabilir
//bu tür fonksiyonların bir noktada kendini çağırmasını bırakması gerekir
//aksi taktirde stack overflow. yani yığın hafızasında taşma olur.
//her fonksiyon çağrısı yığından yer almaktadır. Bu işlem sonsuza kadar devam edemez

int faktoriyel(int sayi)
{
    cout<<"faktoriyel("<<sayi<<") cagrildi!!"<<endl;
    //öz yinelemenin duracağı nokta
    if(sayi==1)
        return 1;

    //fonksiyon kendisini tekrardan çağıyor.
    //çağıran fonksiyon çağrılanı bekleyecektir.
    //çağrılan döndüğünde getirdiği değer ile işlem yapılacak
    //ve fonksiyon sonucu döndürecektir
    //kime ? kendisini çağırana
    //unutmayın aynı kod tekrar terar çağrılabilir
    return sayi*faktoriyel(sayi-1);
}

int main()
{
    //sonucu incelerseniz faktoriyel 5 için çağrılıyor
    //fakat sonuç ekrana daha sonra çıkartılıyor
    //Bunun sebebi faktoriyel(5) dönüş yapmadan önce
    //faktoriyel(4) fonksiyonunu çağırmıştır. o biteden kaldığı noktadan devam edemez
    //faktoriyel(1) öz yinelemenin durduğu noktadır.
    cout<<"5! = "<<faktoriyel(5);

}