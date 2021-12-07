#include<iostream>
#include<iomanip>
#include "AVLAgaci.hpp"
using namespace std;



int main()
{
  AVLAgaci agac;


    try
    {
      agac.ekle(1);
      agac.ekle(3);
      agac.ekle(4);
      agac.ekle(5);
      agac.ekle(6);
      cout<<agac;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    


}