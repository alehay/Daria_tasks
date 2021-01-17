#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::vector<int> v;

  for(auto&& i : v){
    std::cout << i << std::endl;
  }
}

//заполнить вектор числами от -5 до 15