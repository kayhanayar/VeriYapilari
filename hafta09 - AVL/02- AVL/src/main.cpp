#include<iostream>
#include<iomanip>
#include "AVLAgaci.hpp"
using namespace std;



int main()
{
  AVLAgaci agac;


    try
    {
      agac.ekle(20);
      agac.ekle(10);
      agac.ekle(5);
      agac.ekle(15);
      agac.ekle(30);
      cout<<agac;
      agac.sil(30);
      cout<<agac;           
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    


}