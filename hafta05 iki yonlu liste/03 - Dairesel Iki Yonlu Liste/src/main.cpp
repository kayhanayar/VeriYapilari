#include<iostream>
#include<iomanip>
#include "Liste.hpp"
using namespace std;



int main()
{
	BagliListe<int> liste;

	for (int i = 0; i < 5; i++)
		liste.ekle((i + 1) * 11);

	cout << liste;
	liste.ekle(4, 88);
	cout << liste;
   
    
}