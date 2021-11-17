#include <cmath>
#include <iostream>

using fptr = double(double);
double fun(double x);
double trapezoid(double a, double b, int n, fptr f);
double simpson(double a, double b, int n, fptr f);

int main(int argc, char **argv)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    const double XMIN = std::atof(argv[1]); //En este ejercicio XMIN=0.0, XMAX=4.0, N1=10 Y N2=1000
    const double XMAX = std::atof(argv[2]);
    const int N1 = std::atof(argv[3]);
    const int N2 = std::atof(argv[4]);
    const double mass = 1.25;
    const double Final_Speed = std::sqrt(2.0*(1/mass)*(2.0*(std::sin(XMAX)-XMAX*std::cos(XMAX)))); //v_f=(2*(1/m)*W)^1/2, teniendo en cuenta que v_i=0
    
    double DeltaTrap1 = std::fabs(1 - (std::sqrt(2.0*(1/mass)*trapezoid(XMIN,XMAX,N1,fun)))/Final_Speed);
    double DeltaTrap2 = std::fabs(1 - (std::sqrt(2.0*(1/mass)*trapezoid(XMIN,XMAX,N2,fun)))/Final_Speed);
    double DeltaSimp1 = std::fabs(1 - (std::sqrt(2.0*(1/mass)*simpson(XMIN,XMAX,N1,fun)))/Final_Speed);
    double DeltaSimp2 = std::fabs(1 - (std::sqrt(2.0*(1/mass)*simpson(XMIN,XMAX,N2,fun)))/Final_Speed);
    
    std::cout << N1 << "\t"
	      << DeltaTrap1 << "\t"
	      << DeltaSimp1 << "\n";
    std::cout << N2 << "\t"
	      << DeltaTrap2 << "\t"
	      << DeltaSimp2 << "\n";
    return 0;
}

double fun(double x)
{
  return 2.0*x*std::sin(x);
}

double trapezoid(double a, double b, int n, fptr f)
{
  double h = (b-a)/n;
  double result = 0.0;
  for(int ii = 1; ii <= n; ++ii) {
    double xi = a + ii*h;
    result += f(xi);
  }
  result += 0.5*(f(a) + f(b));
  result *= h;

  return result;
}

double simpson(double a, double b, int n, fptr f)
{
  double h = (b-a)/n;
  double result = (f(a) + f(b));
  double sum1 = 0.0;
  double sum2 = 0.0;
  for(int ii = 1; ii <= (n-2)/2; ++ii) {
    double xi = a + (2*ii)*h;
    sum1 += 2*f(xi);
  }

  for(int ii = 1; ii <= n/2; ++ii){
    double xi = a + (2*ii-1)*h;
    sum2 += 4*f(xi);
  }

  result += sum1 + sum2;
  result *= h/3;

  return result;
}
