#include <iostream>

struct Point{
  double x;
  double y;
};

template<typename T>
struct operation{
  T value;
  
  operation(T v) : value{v} {}

  template<typename M>
  T add(M m) const {
    // мой код, специализация шаблона на этапе компиляции if else; 
    if constexpr (std::is_same_v < T, Point >) {
      auto copy (value);
      copy.x += m;
      copy.y += m;
      return copy;
    } else {
      return value + m;
    }
  }
};



int main(){
  // Исправить функцию add для обработки Point + число
  // Использовать if тип point {} else {}
  
  Point p{1, 4};
  int value = 10;

  operation<Point> make {p};

  Point p2 = make.add(value);
  
  auto [x, y] = p;
  auto [x2, y2] = p2;
  
  std::cout << "(" << x << ", " << y << ") + " << value
            << " -> (" << x2 << ", " << y2 << ")\n";
}
