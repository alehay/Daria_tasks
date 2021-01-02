#include <iostream>




template<typename N, typename I, typename S>
struct info{
  N name;
  I id;
  S salary;

  explicit info(N n, I i, S s) :
    name{n}, id{i}, salary{s}
  {}
};

// мой код : 
template<typename N, typename I, typename S> 
info <N, I, S> make_info (N n, I i, S s) {
  return info<N, I, S>(n, i, s);  // без Дарьи я бы и не решил. 
}

int main(){
  // Daria - Разрешается компилировать только с флагом -std=c++14
  // Найти и устранить проблему компиляции.

  auto worker(make_info("John", 32, 1000));
  std::cout << "#" << worker.id << "\tName: " << worker.name
            << "\tSalary: " << worker.salary << std::endl;
  
}
