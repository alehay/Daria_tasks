/*
 * найти максимальный и минимальный элемент по x 
 * и по y (отдельно) в векторе точек.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<double> v1 = {1,2,3,10};
  std::vector<double> v2 = {2,4,6,2};
  for(auto&& v : v1) {
    std::cout << v << ",";
  }
  std::cout << "\n";
  for(auto&& v : v2) {
    std::cout << v << ",";
  }
  std::cout << "\n";

////////////////////////////////////////////////
// разделить все элементы вектора v1 на элементы
// вектора  v2 почленно.   
//  for_each(...);
////////////////////////////////////////////////  

//auto lamda = [] () {} 
std::for_each (v1.begin(), v1.end(), [&v2, i = 0] ( double & val ) mutable { 
    val = val / v2[i];
    std::cout<< val << std::endl;
    ++i;
  });

}
/*
И распечатать внутри for_each. Вывод:
1,2,3,
2,4,6,
1/=2
2/=4
3/=6
0.5,0.5,0.5,
2,4,6,
*/


/* 
template<class InputIt, class UnaryFunction>
constexpr UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first) {
        f(*first);
    }
    return f; // implicit move since C++11
}

*/