#include <iostream>
#include <cmath>
#include <cstdlib>

double f(double x);
template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter);
template <class fptr>
double bisection_recursive(double xl, double xu, fptr fun, double eps);

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);
  const double EPS1 = std::atof(argv[3]);
  const double EPS2 = std::atof(argv[4]);
  const double EPS3 = std::atof(argv[5]);
  const double EPS4 = std::atof(argv[6]);
  int counter = 0;

  std::cout << "eps" << "\t"
	    << "                bisection" << "\t"
	    << "        bisection_recursive" << "\n"
	    << EPS1 << "\t"
	    << bisection(XL, XU, f, EPS1, counter) << "\t"
	    << bisection_recursive(XL, XU, f, EPS1) << "\n"
	    << EPS2 << "\t"
	    << bisection(XL, XU, f, EPS2, counter) << "\t"
	    << bisection_recursive(XL, XU, f, EPS2) << "\n"
	    << EPS3 << "\t"
	    << bisection(XL, XU, f, EPS3, counter) << "\t"
	    << bisection_recursive(XL, XU, f, EPS3) << "\n"
	    << EPS4 << "\t"
	    << bisection(XL, XU, f, EPS4, counter) << "\t"
	    << bisection_recursive(XL, XU, f, EPS4) << "\n";
  
  return 0;
}

double f(double x)
{
  return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = 0;
  int iter = 1;
  for( ;  ; ) { 
    xr = (xl + xu)/2; 
    if (std::fabs(fun(xr)) <= eps) break;
    
    iter++;
    
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
  }
  niter = iter;
  return xr;
}

template <class fptr>
double bisection_recursive(double xl, double xu, fptr fun, double eps)
{
  double xr = xl;

  while(std::fabs(fun(xr)) > eps){
    if(fun(xr)*fun(xl) < 0){
      xu = xr;
    } else{
      xl = xr;
    }
    xr = (xl + xu)/2;
    
    if(std::fabs(fun(xr)) <= eps)break; 
  }
  return xr;
}


