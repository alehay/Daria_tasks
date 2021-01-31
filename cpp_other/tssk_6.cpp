#include <iostream>
#include <vector>
#include <string>

struct A{

  std::string *str;

  A()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A(const std::string& s)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  ~A()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  A(const A& oth)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A& operator=(const A& oth)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
    
  A& operator=(A&& oth)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A(A&& oth)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
};

// template<class T>
// void fast_delete_element_by_index(...){
// }

int main(){
  // Заполнить все шесть функций для класса с динамически выделяемой памятью.
  // Написать шаблонную функцию, которая удаляет по индексу элемент из вектора за время О(1) 
  // Проверить, что адрес динамически выделяемой памяти первого элемента поменялся на адрес последнего
  
  A a1{"qwerty"};
  A a2{"asdfgh"};
  A a3{"zxcvbn"};

  std::cout << *a1.str << std::endl;
  std::cout << *a2.str << std::endl;
  std::cout << *a3.str << std::endl;

  std::vector<A> str_v = {a1, a2, a3};
  
  for(auto&& s: str_v){
    std::cout << "(" << *s.str << ") : " << s.str << std::endl; 
  }
  std::cout << std::endl;
  
  fast_delete_element_by_index(str_v, 0);

  for(auto&& s: str_v){
    std::cout << "(" << *s.str << ") : " << s.str << std::endl; 
  }
}