#include<iostream>
#include<iomanip>
#include "BagliListe.hpp"
using namespace std;

class dortgen
{
public:
    dortgen()
    {
        cout << this << ":dortgen()" << endl;
    }
    ~dortgen()
    {
        cout << this << ":yokedici()" << endl;
    }
    dortgen(const dortgen& sag)
    {
        cout << this << ":kopya()" << endl;
    }
    int gen;
};

int main()
{
    BagliListe<dortgen>* liste = new BagliListe<dortgen>();

    
    liste->cikar();
}