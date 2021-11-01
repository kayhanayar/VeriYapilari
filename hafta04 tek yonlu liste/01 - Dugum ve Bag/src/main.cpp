#include<iostream>
#include<iomanip>
#include "Dugum.hpp"
using namespace std;



int main()
{
    Dugum* d1 = new Dugum(11);
    Dugum* d2 = new Dugum(22);
    Dugum* d3 = new Dugum(33);
    Dugum* d4 = new Dugum(44);
    Dugum* d5 = new Dugum(55);

    d1->sonraki = d2;
    d2->sonraki = d4;
    d4->sonraki = d3;
    d3->sonraki =d5;

    Dugum* gecici = d1;

    cout<<"while(gecici->sonraki!=0) oldugunda :";
    while(gecici->sonraki!=0)//son düğümde de içeri girecek.
    {
        cout<<gecici->veri<<"->";
        gecici = gecici->sonraki;
    }

    cout<<endl;
    
    gecici = d1; //gecici tekrar ilk düğümü gösteriyor. başa döndük.

    cout<<"while(gecici!=0) oldugunda :";
    while(gecici!=0)//son düğümde de içeri girecek.
    {
        cout<<gecici->veri<<"->";
        gecici = gecici->sonraki;
    }
}