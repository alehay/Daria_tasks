#include <iostream>
#include <vector>
#include <map>

#include <algorithm>
#include <cmath>

struct Point{
  double x;
  double y;
 
  // правильный ответ 
  bool operator<(const Point& oth) const {
    return (x < oth.x) || (x == oth.x) && (y < oth.y);
  }
  
  /*
  friend const bool operator<(const Point& l_value,  const Point& r_value ) {
    return (l_value.x < r_value.x) || (l_value.y < r_value.y);
  } */

};


int main(){
  // Найти и исправить ошибку компиляции
  // Исправить оператор сравнения +
  // Заполнить map расстояниями от точки pivot до каждой точки points
  // В цикле удалить точки, расстояние до которых от pivot > 10
  
  Point pivot {1, 2};
  
  std::map<Point, double> distance;

  std::vector<Point> points = { {0, 0}, {11, 13}, {3, 4}, {8, -19}, {1, 2}};

  std::for_each( points.begin(),  points.end() , [&distance,&pivot ] (Point & point) {
      distance.insert ({ point, sqrt( pow (point.x - pivot.x,2) + pow (point.y - pivot.y,2)) }); 
      });
  for(auto&& [x, y]: points){
    std::cout << "(" << x << ", " << y << ") <-> " << distance[Point{x, y}] << std::endl; 
  }
}