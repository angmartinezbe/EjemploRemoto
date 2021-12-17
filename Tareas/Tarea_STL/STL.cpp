#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include <cmath>
#include <random>
#include <fstream>

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);

  std::vector<double> v(N);		
  std::iota(v.begin(), v.end(),10);

  auto print = [](const int & i){std::cout << " " << i;};
  
  std::for_each(v.begin(), v.end(), print);
  std::cout << "\n" ;

  int count_great25 = std::count_if(v.begin(),v.end(),[](int i){return i > 25;});
  std::cout << "Numbers greater than 25 = " << count_great25 << "\n";

  int count_div3_5 = std::count_if(v.begin(),v.end(),[](int i){return i % 3 == 0 && i % 5 == 0;});
  std::cout << "Numbers divisible by 3 and 5 = " << count_div3_5 << "\n";

  if(std::any_of(v.begin(), v.end(), [](int i){return i % 7 == 0 && i % 13 == 0;})){
    std::cout << "At least one number is divisible by seven and thirteen\n";
  }
  
  std::sort(v.begin(), v.end(), std::greater<double>());
  std::for_each(v.begin(), v.begin() + 10,[](int i){std::cout << " " << i;});
  std::cout << "\n" ;

  double sum = std::accumulate(v.begin(), v.end(), 0);
  auto start = std::chrono::steady_clock::now();
  std::cout << "Average = " << sum/2 << "\n";
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "Elapsed time computing the average = " << elapsed_seconds.count() << "s\n";


  std::mt19937 gen(5);
  std::normal_distribution<double> d(0, 1);

  std::map<int, int>hist{};
  for(int n = 0; n < 10000; ++n){
    ++hist[std::round(d(gen))];
  }
  
  std::ofstream fout("histo.txt");
  for(auto x : hist){
    fout << x.first << " " << x.second << "\n";
  }
 
  return 0;
}
