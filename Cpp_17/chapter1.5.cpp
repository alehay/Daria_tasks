#include <iostream>

template<typename T>
struct mult{
  T result;
  
  template<typename ... Ts>
  mult(Ts&& ... values) : result{(values * ...)} {}

};

template<typename ... Ts>
//mult(Ts&& ... values) -> mult<int>;   
// мой код: 
mult(Ts&& ... values) -> mult<std::common_type_t<Ts...>>;

int main(){
  // Daria Исправить warning
  // Alehay  использовать явные правила преведения тпов  <std::common_type_t<Ts...>>
  // дает право компилятору выбрать самый широкий тип
  mult fact {1, 2, 3, 4, 5};
  
  std::cout << "factorial: " << fact.result << std::endl;

  mult m1{1.2, 3, 10, 0.4f};
  std::cout << "result1: " << m1.result << std::endl;
}
