#include <iostream>
#include <cmath>

void print_largestdivisor(long long nmin,long long nmax);

int main(void)
{
  const long m = 2;
  const long long n = 600851475147;

  print_largestdivisor(m,n);

  return 0;
}

void print_largestdivisor(long long nmin, long long nmax)
{
  long long dmax = 0;
  
  for(long long ii = nmin; ii <= nmax/2; ii++){ //Se optimiza para que el límite superior sea igual al máximo posible divisor de un número (es decir, su mitad).

     if(nmax % ii == 0) {

       dmax = nmax/ii;
       std::cout << "Number = " << nmax << "\n";
       std::cout << "Largest divisor = " << dmax << "\n";
       //std::cout << ii << "\n";
       break;
    }
  }
}
      
