#include <iostream>




template<typename N, typename I, typename S>
struct info{
  N name;
  I id;
  S salary;

  explicit info(N n, I i, S s) :
    name(n), id(i), salary(s)
  {}
};


int main(){
  // Daria - Разрешается компилировать только с флагом -std=c++14
  // Найти и устранить проблему компиляции.

  auto worker(make_info("John", 32, 1000));
  std::cout << "#" << worker.id << "\tName: " << worker.name
            << "\tSalary: " << worker.salary << std::endl;
  
}
