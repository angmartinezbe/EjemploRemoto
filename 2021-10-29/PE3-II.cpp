#include <iostream>
#include <cmath>
#include <cstdlib>

bool isprime(long long n);
long long largestprimedivisor(long long n);
long long primeaddition(long long n); 

int main(int argc, char **argv)
{
  const long long N = std::atoll(argv[1]);
  std::cout << largestprimedivisor(N) << std::endl;
  std::cout << primeaddition(N) << std::endl;
  return 0;
}

long long largestprimedivisor(long long n)
{
  long long result = n;
  for (long long ii = 2; ii <= n/2; ii++){
    if (n%ii == 0){
      long long largedivisor = n/ii;
      if(isprime(largedivisor)){
	result = largedivisor;
	break;
      }
    }
  }

  return result;
}

bool isprime(long long n)
{
  bool isprime = true;
  for(long long jj = 2; jj <= std::sqrt(n); jj++){
	if(n%jj == 0){
	  isprime = false;
	  break;
	}
  }
  return isprime;
}

long long primeaddition(long long n)
{
  long long suma = 0;
  for(long long ii=2; ii<=n; ii++){
    if(n%ii ==0 && isprime(ii)){
    suma+=ii;
    n/=ii;
    }
  }
  return suma;
}
