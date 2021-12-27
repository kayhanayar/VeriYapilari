#include<iostream>
#include<iomanip>
#include "HashTablosu.hpp"
using namespace std;



int main()
{
  HashTablosu hash;
  hash.ekle(11);
  hash.ekle(77);
  hash.ekle(112);
  hash.ekle(33);
  hash.ekle(44);
  hash.ekle(213);
  hash.ekle(66);
  cout<<hash;
  hash.cikar(11);
    hash.cikar(112);
      hash.cikar(213);
        hash.cikar(11);
   cout<<hash;

}