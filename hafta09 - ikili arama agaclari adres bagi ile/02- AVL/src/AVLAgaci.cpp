#include "AVLAgaci.hpp"
#include <iomanip>
#include<iostream>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok= 0;
}
AVLAgaci::~AVLAgaci()
{

}
bool AVLAgaci::varmi(int veri) 
{
    varmi(veri,kok);
}
void AVLAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}
void AVLAgaci::sil(int veri) 
{
	
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}
void AVLAgaci::preOrder() {
    preOrder(kok);
    cout<<endl;
}
void AVLAgaci::postOrder() {
	postOrder(0);
}
void AVLAgaci::inOrder() {
    inOrder(0);
}

void AVLAgaci::levelOrder(Dugum* aktif,int level) 
{
	if(aktif)
    {
        if(level==0)
        {
            cout<<setw(5)<<aktif->veri;
        }
        else
        {

            if(aktif->sol)
                levelOrder(aktif->sol,level-1);
            else
                cout<<setw(5)<<"bos";
         

            if(aktif->sag)
                levelOrder(aktif->sag,level-1);
            else
                cout<<setw(5)<<"bos";
            
         
        }
    }
}
void AVLAgaci::preOrder(Dugum* aktif) 
{
	if(aktif)
    {
        cout<<aktif->veri<<"  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}
void AVLAgaci::postOrder(Dugum* aktif) 
{
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->veri<<"  ";
    }	
}
void AVLAgaci::inOrder(Dugum* aktif) 
{
	if(aktif)
    {
        
        inOrder(aktif->sol);
        cout<<aktif->veri<<"  ";        
        inOrder(aktif->sag);
        
    }	
}
int AVLAgaci::yukseklik(Dugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
Dugum* AVLAgaci::ekle(int veri,Dugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new Dugum(veri);

	else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
Dugum* AVLAgaci::solaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
Dugum* AVLAgaci::sagaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int AVLAgaci::maxDeger(Dugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
bool AVLAgaci::varmi(int aranan,Dugum* aktif)
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

 ostream& operator<<(ostream& os,AVLAgaci& agac)
{
    int yukseklik = agac.yukseklik();
    for(int i=0;i<=yukseklik;i++)
    {
        agac.levelOrder(agac.kok,i);
        os<<endl;
    }
        

    return os;  
}