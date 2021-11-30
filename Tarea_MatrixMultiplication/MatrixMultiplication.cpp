#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3);

int main(int argc, char **argv) {
 
  const int N = std::atoi(argv[1]); //Esta N es para los casos de prueba 
  const int SEED = std::atoi(argv[2]);

  for (int ii = 2; ii <= 9; ++ii){

    int N = pow(2, ii);

    std::vector<double> A(N*N, 0.0), B(N*N, 0.0), C(N*N, 0.0);

    std::mt19937 gen(SEED);
    std::uniform_real_distribution<> dist(0.,1.);
 
    std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); });   
    std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); });
    
    auto start = std::chrono::high_resolution_clock::now();
    multiply(A, B, C);
    auto stop = std::chrono::high_resolution_clock::now();
    
    std::cout << N << "\t";
    auto elapsed = std::chrono::duration<double>(stop - start);
    std::cout << elapsed.count()/1.391e-06 << "\n"; //1.391e-06: Tiempo cuando N=4
  }

  // Lo siguiente sirve para ver los casos de prueba
  /* std::vector<double> A(N*N, 0.0), B(N*N, 0.0), C(N*N, 0.0); 

  std::mt19937 gen(SEED);
  std::uniform_real_distribution<> dist(0.,1.);
 
  std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); });   
  std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); });
    
  auto start = std::chrono::high_resolution_clock::now();
  multiply(A, B, C);
  auto stop = std::chrono::high_resolution_clock::now();
    
  std::cout << C[N/2] << "\t";
  auto elapsed = std::chrono::duration<double>(stop - start);
  std::cout << elapsed.count() << "\n"; 
  */
  
  
  return 0;
}

void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3)
{
  const int N = std::sqrt(m1.size());
  for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
	  double  mproduct = 0.0;
	  for (int kk = 0; kk < N; ++kk)
	    mproduct += m1[ii*N + kk] * m2[kk*N + jj];
	  m3[ii*N + jj] = mproduct;	    
        }
    }
}
