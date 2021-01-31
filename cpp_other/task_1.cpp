/* 
 * мап из структур, в которых есть вектор 
 * points, как с помощью stl пройдись по map, добраться до 
 * значения структуры и её внутреннего вектора и посчитать 
 * 
 */

#include <map>
#include <vector>
#include <iostream>
#include <numeric>

struct Point{
  int x {0};
  int y {0};

  Point(int x_, int y_) : x(x_), y(y_) {}
};

using v_type = std::vector<Point>;

struct Feature{
  v_type points;
};

int main(){
  v_type points1 {Point(1,4), Point(2,2), Point(6,2)};
  v_type points2 {Point(2,5), Point(2,2), Point(6,2)};
  v_type points3 {Point(3,6), Point(2,2), Point(6,2), Point(2,2), Point(2,2), Point(2,2)};
  v_type points4 {Point(4,7), Point(2,2), Point(6,2),  Point(6,2)};

  Feature f1;
  f1.points = points1;

  Feature f2;
  f2.points = points2;

  Feature f3;
  f3.points = points3;

  Feature f4;
  f4.points = points4;

  std::map<int, Feature> m;
  m[0] = f1;
  m[1] = f2;
  m[2] = f3;
  m[3] = f4;

  for(auto&& [k, f] : m){
    std::cout << "[" << k << "] = " << f.points.front().x << ", " << f.points.front().y << std::endl;
  }

  /* измените код здесь */
  //size_t size = std::accumulate(...);
 size_t size = std::accumulate(m.begin(), m.end(),0 , [] (int acum, auto it  ) 
 { return acum + it.second.points.size(); } );

//size_t size = std::accumulate(m.begin(), m.end(),0 , [] ( ) {return acum + it->second.points.size(); } );



  std::cout << "size: " << size << std::endl;
}


/*



template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init, 
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // std::move since C++20
        int  = [](std::move(init), *first) {
          first->
        }
    }
    return init;
}
*/

