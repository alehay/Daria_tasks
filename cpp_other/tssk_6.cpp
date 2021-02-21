#include <iostream>
#include <vector>
#include <string>

#include <utility>

struct A{

  std::string *str {nullptr} ;

  A() : str {nullptr} 
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A(const std::string& s) : str {new  std::string(s)} 
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  ~A()
  {
    delete str;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  A(const A& oth):str {new  std::string(*oth.str)}
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A& operator=(const A& oth)
  {
    if (this != &oth ) {
      if (str){
        delete str;
      }
      str = new  std::string(*oth.str);
    }
    return *this;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
    
  A& operator=(A&& oth)
  {
    str = oth.str;
    oth.str = nullptr; 
    return *this;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
  A(A&& oth)
  {
    
    if (str){
      delete str;
    }
    str = oth.str;
    oth.str = nullptr; 
  
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  
};

// template<class T>
// void fast_delete_element_by_index(...){
// }
template <class T>
void fast_delete_element_by_index(T & cont, size_t iter){
  if(cont.empty()) return;

  if (iter >= 0 && iter < cont.size()) {
    cont[iter] = std::move(cont.back());
    cont.pop_back();
  }
   
}

int main(){
  // Заполнить все шесть функций для класса с динамически выделяемой памятью.
  // записать в памать класса получаемый параметр. 

  // Написать шаблонную функцию, которая удаляет по индексу элемент из вектора за время О(1) 
  // Проверить, что адрес динамически выделяемой памяти у элемента поменялся на адрес последнего
  
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