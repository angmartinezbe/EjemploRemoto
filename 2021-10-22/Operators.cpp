#include <iostream>
#include <cmath>

int main (void)
{
  double x = 9.7, y = -1.87;
  double z = 0;

  z = x + y;
  std::cout << z << std::endl;

  z = x - y;
  std::cout << z << std::endl;
  
  z = x * y;
  std::cout << z << std::endl;
  
  z = x / y;
  std::cout << z << std::endl;
  
  int m  = -2.9;
  std::cout << m << std::endl;

  std::cout << 2*3-4/5 << std::endl; // = 6 trunca el 0.8
  //std::cout << 2*3-4.0/5 << std::endl; = 5.2 lo vuelve double

  //Recordar precedencia de signos
  
  std::cout  << 4%3 << std::endl; // % : Módulo (Menor precedencia)
  std::cout  << 3%3 << std::endl;
  std::cout  << 2%3 << std::endl;
  std::cout  << -4%3 << std::endl;
  std::cout  << -5%3 << std::endl;

  // y = y + 0.9;
  y += 0.9;
  std::cout << y << std::endl;
  
  int ii = 3, jj = 0;
  
  jj = ++ii;
  std::cout << ii  << std::endl;
  std::cout << jj << std::endl;
  
  ii = 3;
  jj = ii++;
  
  std::cout << ii << std::endl;
  std::cout << jj << std::endl;
  
  return 0;

}
  
  
  
