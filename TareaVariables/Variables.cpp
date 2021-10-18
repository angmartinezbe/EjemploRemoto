#include <iostream>

int main()
{
  float a;
  bool b = false;
  float x = 1.0e40;
  double y;
  std::cout << "a = " << a << "\n";
  std::cout << b << "\n";
  std::cout << "x = " << x << "\n";
  std::cout << "Address = " << &y << "\n";
  std::cout << "Size = " << sizeof(double) << "\n";

  return 0; 
}
