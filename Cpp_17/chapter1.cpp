#include <iostream>
#include <chrono>
#include <ctime>

// имитация вычислений надо пологать... 
void calc(){
  for(int i = 0; i < 5000000; ++i){
    std::cout << i << '\r' << std::flush;
  }
}

template<typename T>
std::pair<std::string, double> get_duration(T fun){
  auto start = std::chrono::system_clock::now(); 
  fun();
  auto end = std::chrono::system_clock::now();
  
  std::chrono::duration<double> elapsed_seconds = end - start;     //получаем время 
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  return std::pair<std::string, double> (std::ctime(&end_time), elapsed_seconds.count());  // получаем время замера, результат замера 
}

int main(){
  // Daria - Что происходит в этой программе и как распаковать полученные значения?
  // Alehay - в программе замеряется время вычислений. шаблон возвращает пару дата резльтат , результаты получаем распаковкой. 
  auto [date, stopwatch] = get_duration(calc);  
  std::cout << "date : " << date << "stopwatch : " << stopwatch << std::endl;

}
