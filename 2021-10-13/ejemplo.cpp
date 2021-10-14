// Calcular los números pares entre 1 y 100

// Incluir las librerías que vamos a usar
#include <iostream>
#include <cmath>

void print_even(int nmin, int nmax); // declaración

// main function
int main(void)
{
  const int m = 1;
  const int n = 15;

  print_even(m,n);
  print_even(m/2, 2*n);

  return 0;
}

void print_even(int nmin, int nmax) // implementación
{  
  for(int ii = nmin; ii <= nmax ; ii = ii+1){
    //si el número es par, entonces imprimir
    if (ii%2 ==  0) {
      std::cout << ii << " ";
    }
  }
  std::cout << "\n"; 
}
