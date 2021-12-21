#include "IkiliAramaAgaci.hpp"
#include <iomanip>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok= 0;
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{

}
bool IkiliAramaAgaci::varmi(int veri) 
{
    varmi(veri,kok);
}
void IkiliAramaAgaci::ekle(int eklenecek)
{
    if(kok==0)
        kok=new Dugum(eklenecek);
    else
        ekle(eklenecek,kok);
}
void IkiliAramaAgaci::sil(int veri) 
{
	sil(veri,kok); 
}
int IkiliAramaAgaci::yukseklik() 
{
	return yukseklik(kok);
}
void IkiliAramaAgaci::preOrder() {
    preOrder(kok);
    cout<<endl;
}
void IkiliAramaAgaci::postOrder() {
	postOrder(0);
}
void IkiliAramaAgaci::inOrder() {
    inOrder(0);
}
void IkiliAramaAgaci::levelOrder(Dugum* aktif,int level) 
{
	if(aktif)
    {
        if(level==0)
        {
            boslukBirak(aktif->yukseklik);
            cout<<setw(5)<<aktif->veri;
        }
        else
        {

            if(aktif->sol)
                levelOrder(aktif->sol,level-1);
            else
            {
                 boslukBirak(aktif->yukseklik);
                 cout<<setw(5)<<"bos";
            }
                
         

            if(aktif->sag)
                levelOrder(aktif->sag,level-1);
            else
            {
                 boslukBirak(aktif->yukseklik);
                 cout<<setw(5)<<"bos";
            }
            
         
        }
    }
}
void IkiliAramaAgaci::levelOrder()
 {
        if(kok==0)
    return;
	queue<Dugum*> kuyruk;

    kuyruk.push(kok);

    int seviye=0;
    int yuksek = yukseklik();
    int kat=0;
    cout<<endl;
    while(!kuyruk.empty()&&seviye<=yuksek)
    {
       
        auto siradaki = kuyruk.front();
        kuyruk.pop();
      
        if(kat==0)
            boslukBirak(yuksek-seviye);
        if(siradaki)
            cout<<setw(2)<<siradaki->veri;
        else
            cout<<setw(2)<<"--";
        boslukBirak(yuksek-seviye+1);
        
        if(siradaki)
        {
            kuyruk.push(siradaki->sol);
            kuyruk.push(siradaki->sag);
        } 
        else
        {
            kuyruk.push(0);
            kuyruk.push(0);         
        }
        kat++;
        if(pow(2,seviye)==kat)
        {
            cout<<endl;    
            seviye++;
            kat=0;
             
        }

           
    }
}
void IkiliAramaAgaci::preOrder(Dugum* aktif) 
{
	if(aktif)
    {
        cout<<aktif->veri<<"  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}
void IkiliAramaAgaci::postOrder(Dugum* aktif) 
{
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->veri<<"  ";
    }	
}
void IkiliAramaAgaci::inOrder(Dugum* aktif) 
{
	if(aktif)
    {
        
        inOrder(aktif->sol);
        cout<<aktif->veri<<"  ";        
        inOrder(aktif->sag);
        
    }	
}
int IkiliAramaAgaci::yukseklik(Dugum* aktifDugum) 
{
	if(aktifDugum)
    {
        aktifDugum->yukseklik= 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
        return aktifDugum->yukseklik;
    }
    return -1;
}
void IkiliAramaAgaci::ekle(int veri,Dugum* aktifDugum) 
{
	if(aktifDugum->veri>veri)
    {
        if(aktifDugum->sol)
            ekle(veri,aktifDugum->sol);
        else
            aktifDugum->sol = new Dugum(veri);
    }
    else if(aktifDugum->veri<veri)
    {
        if(aktifDugum->sag)
            ekle(veri,aktifDugum->sag);
        else
            aktifDugum->sag= new Dugum(veri);
    }
    else
        return;
}

void IkiliAramaAgaci::silDonguile(Dugum* aktif,Dugum* ebeveyn) 
{
    
    Dugum* yeniDugum;
    if(!aktif->sag&&!aktif->sol)
    {
        yeniDugum = 0;
    }    
	else if(!aktif->sol) //sadece sağ düğüm var ise
    {
        yeniDugum = aktif->sag;
    }
    else if(!aktif->sag)
    {
        yeniDugum = aktif->sol;
    }
    else
    {
        Dugum* ebeveyn= aktif;

        Dugum* enbuyuk = aktif->sol;

        while(enbuyuk->sag!=0)
        {
            ebeveyn = enbuyuk;
            enbuyuk = enbuyuk->sag;
        }
        aktif->veri = enbuyuk->veri;

        ebeveyn->sag = enbuyuk->sol;
       
        delete enbuyuk;
        return ;
    }

    if(aktif==ebeveyn->sol)
        ebeveyn->sol = yeniDugum;
    else if(aktif==ebeveyn->sag)
    {
        ebeveyn->sag = yeniDugum;
    } 
    delete aktif;
}
void IkiliAramaAgaci::sil(int aranan,Dugum* &aktif) 
{
    if(aktif==0)        return;
	if(aktif->veri>aranan)
        sil(aranan,aktif->sol);
    else if(aktif->veri<aranan)
        sil(aranan,aktif->sag);
    else
    {
        if(aktif->sag&&aktif->sol)
        {
            aktif->veri = maxDeger(aktif->sol);
            sil(aktif->veri,aktif->sol);
        }
        else
        {
            Dugum* silinecek= aktif;
            if(aktif->sol==0)
                aktif= aktif->sag;
            else if(aktif->sag==0)
                aktif = aktif->sol;
            else 
                aktif =0;
            delete silinecek;      
        }
    }
}
int IkiliAramaAgaci::maxDeger(Dugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
void IkiliAramaAgaci::boslukBirak(int adet) {
     int baslangicBosluk = pow(2,adet)-1;
     for(int i=0;i<baslangicBosluk;i++)
	    cout<<"  ";
}
bool IkiliAramaAgaci::varmi(int aranan,Dugum* aktif)
{
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}

 ostream& operator<<(ostream& os,IkiliAramaAgaci& agac)
{
    /*
    int yukseklik = agac.yukseklik();
    for(int i=0;i<=yukseklik;i++)
    {
        agac.boslukBirak(yukseklik-i);
        agac.levelOrder(agac.kok,i);
        os<<endl;
    }
      */
     agac.levelOrder();  

    return os;  
}