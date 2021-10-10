#include<iostream>
#include "kutuphane.hpp"
using namespace std;
int main()
{
	int sayi1 = 15;
	int sayi2 = 30;

	cout << "sayi1:" << sayi1 << endl;
	cout << "sayi2:" << sayi2 << endl;
	cout << "&sayi1:" << &sayi1 << endl;
	cout << "&sayi2:" << &sayi2 << endl;
	cout << "--------------------" << endl;
	degistir(&sayi1, &sayi2);
	cout << "--------------------" << endl;
	cout << "sayi1:" << sayi1 << endl;
	cout << "sayi2:" << sayi2 << endl;

}