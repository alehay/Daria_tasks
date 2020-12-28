#include <iostream>

void sep() {
  std::cout << "************************" <<std::endl;
}


int main(){
  auto t = {1}; 
  //auto t2 {2,3};
  auto t3 = {2, 3};

  auto v (12);
  // auto v2 (21, 23); 
  //auto v3 = {1, 2.0};

  std::cout << typeid(t).name()  << " auto t = {1}; - будет int "  << std::endl; // вот тут тоже ошибся я думал будет инт а он nitializer_list
  sep();
  std::cout << /* typeid(t2).name() << */" auto t2 = {2,3} - ошибка  " << std::endl; // правильно
  sep();
  std::cout << typeid(t3).name() << " auto t3 = {2, 3} будет initializer_list " << std::endl; // правильно
  sep();
  std::cout << typeid(v).name()  << " auto v = (12) будет int " << std::endl; // ну вроде правильно.
  sep();
  std::cout << /* typeid(v2).name() <<*/ " auto v2 (21, 23); - ошибка  " << std::endl;
  sep();
  std::cout << /* typeid(v3).name() << */ " auto v3 = {1, 2.0}; будет initializer_list<> " << std::endl; // вот тут я ошибся, копилятор не принял
}
