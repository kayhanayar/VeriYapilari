#include<iostream>

using namespace std;
int main()
{
     int sayilar[] = {1,2,3,4,5,6};
     int*p;

     //bir dizinin başlangıç adresini aşağıdaki gibi bir işaretçi içerisine atayabiliriz
    //adres operatörü kullanılmadan derleyici dizinin ilk adresini işaretçiye atayacaktır.
    //dikkat dizinin ismi bir işaretçi değildir.
    p = sayilar;

    //aşağıdaki satır dizinin ilk elemanını ekrana çıkartacaktır.
    //çünkü işaretçi dizinin ilk adresini tutuyor.
    //bu adreste bulunan tam sayı da dizinin ilk elemanı dır

    cout<<*p<<endl;

    //dizinin ikinci elemanınına işaretçi kullanarak aşağıdaki gibi erişebiliriz
    //[] operatörleri dizideki gibi kullanılabilir.
    //indis olarak 1 verildiği için. derleyici işaretçinin gösterdiği yeri değilde
    //hafızada bir sonraki (4 bayt sonra) tam sayıyı getirecektir.
    cout<<p[1]<<endl;

    //erişmenin diğer bir yolu da işaretçi aritmetiği kullanmaktır.
    //aşağıdaki satırda işaretçin tuttuğu adres yerine +1 yani bir sonraki tamsayının adresi getirilecektir
    //* operatörü ile de bu adresteki veri ekrana çıkartılacaktır.
    //sonuç olarak işaretçi ile yapılan toplama çıkarma işlemleri gösterilen verinin boyutu ile çarpılmaktadır.
    cout<<*(p+1)<<endl;

    cout<<"onceki p="<<p<<endl;
    //aşağıda işaretçinin tuttuğu değer bir arttırılıyor.
    //tabi arttırılma işlemi gösterilen verinin boyutu ile çarpılacak
    //yani işaretçinin tuttuğu adres +4 arttırılacak
    p++;
    //adresi tekrar ekrana çıkartalım.
    cout<<"++ dan sonraki p="<<p<<endl;
    //artık p işaretçisinin değeri değişti. dizinin başlangıcını değilde ikinci elemanını gösteriyor
    cout<<"*p="<<*p<<endl;



}