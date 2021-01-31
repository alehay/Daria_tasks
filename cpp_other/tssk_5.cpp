#include <iostream>
#include <vector>
#include <map>

struct Point{
  double x;
  double y;

  bool operator<(const Point& oth) {
    return (x < oth.x) || (y < oth.y);
  }
};


int main(){
  // Найти и исправить ошибку компиляции
  // Исправить оператор сравнения
  // Заполнить map расстояниями от точки pivot до каждой точки points
  // В цикле удалить точки, расстояние до которых от pivot > 10
  
  Point pivot {1, 2};
  
  std::map<Point, double> distance;

  std::vector<Point> points = { {0, 0}, {11, 13}, {3, 4}, {8, -19}, {1, 2}};

  for(auto&& [x, y]: points){
    std::cout << "(" << x << ", " << y << ") <-> " << distance[Point{x, y}] << std::endl; 
  }
}