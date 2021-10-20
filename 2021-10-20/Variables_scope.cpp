#include <iostream>

const int a = 8; //Siempre usar las variables globales como constantes
  
int main(void)
{
  int a = 9;
  std::cout << a << "\n";
  std::cout << &a << "\n";
  std::cout << ::a << "\n";
  std::cout << &::a << "\n";

  {
    int  a = 10;
    std::cout << a << "\n";
    std::cout << &a << "\n";
  }

  std::cout << a << "\n";
  std::cout << &a << "\n";
  
  return 0;
}
