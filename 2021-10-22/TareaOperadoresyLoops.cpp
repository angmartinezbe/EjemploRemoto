#include <iostream>
#include <cmath>

void print_largestdivisor(long long int nmin,long long int nmax);

int main(void)
{
  const long long int m = 1;
  const long long int n = 600851475147;

  print_largestdivisor(m,n);

  return 0;
}

void print_largestdivisor(long long int nmin, long long int nmax)
{
  long long int dmax = 0;
  
  for(long long int ii = nmin; ii <= nmax/2; ii++){ //Se optimiza para que el límite superior sea igual al máximo posible divisor de un número (es decir, su mitad).

     if(nmax % ii == 0) {

       dmax = ii;
      
       //std::cout << ii << "\n";     
    }
  }
  std::cout << "Number = " << nmax << "\n";
  std::cout << "Largest divisor = " << dmax << "\n";
}
      
