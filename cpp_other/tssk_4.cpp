#include <iostream>
#include <vector>
#include <numeric>

int main() {
int start = -5;
int stop = 15;
  std::vector<int> v;
  
  v.resize(stop - start + 1);

  std::iota(v.begin(), v.end(), start) ;

  for(auto&& i : v){
    std::cout << i << std::endl;
  }
}

//заполнить вектор числами от -5 до 15