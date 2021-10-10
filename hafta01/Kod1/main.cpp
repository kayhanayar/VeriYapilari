#include<iostream>

class Dikdortgen
{
public:
    Dikdortgen(int genislik,int yukseklik)
    {
        m_Genislik = genislik;
        m_Yukseklik= yukseklik;
    }
    Dikdortgen()
    {
        m_Genislik = 10;
        m_Yukseklik =20;
    }
    int genislik()
    {
        return m_Genislik;
    }
    int yukseklik()
    {
        return m_Yukseklik;
    }
private:
    int m_Genislik;
    int m_Yukseklik;
};

int main()
{
    Dikdortgen d1(40,60);
    
    using namespace std;

    cout<<"d1.genislik :"<<d1.genislik()<<endl;
    cout<<"d1.yukseklik:"<<d1.yukseklik()<<endl;

    cout<<"------------------------------------"<<endl;
    Dikdortgen d2;
    
    cout<<"d2.genislik :"<<d2.genislik()<<endl;
    cout<<"d2.yukseklik:"<<d2.yukseklik()<<endl;  
}