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
  // Imprime inf ya que el numero es demasiado grande y supera el valor máximo    (en mi caso el último valor que da un resultado claro es 1.0e5 = 100000).
  std::cout << "Address = " << &y << "\n";
  std::cout << "Size = " << sizeof(double) << "\n";

  return 0; 
}
