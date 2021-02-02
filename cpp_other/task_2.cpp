/*
 * найти максимальный и минимальный элемент по x 
 * и по y (отдельно) в векторе точек.
 */

#include <iostream>
#include <vector>

#include <boost/iterator/zip_iterator.hpp>
#include <boost/fusion/algorithm/transformation/zip.hpp>
#include <boost/fusion/include/zip.hpp>
#include <boost/range.hpp>

#include <boost/range/combine.hpp>
#include <boost/foreach.hpp>


#include <iterator>

int main() {
  std::vector<double> v1 = {1,2,3};
  std::vector<double> v2 = {2,4,6};
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
//auto zip = std::zip( v1 , v2 );
  //for( auto & [ v_1,  v_2] : zip( v1 , v2 )) {
  //  std::cout << v_1  << v_2 << std::endl;
  //for (auto && items : boost::fusion::zip ( v1 , v2 ))  {
    //for (auto [v_1, v_2] : zip( v1 , v2 ) ) {
    //for (auto zi : zip ( v1 , v2 ) ) {
    for (auto const & i : boost::combine(v1 , v2) ) {
      double v_1;
      double v_2;
      boost::tie(v_1,v_2) = i;
      std::cout << v_1  << v_2 << std::endl;
    }
  }

////////////////////////////////////////////////  
  /*
  for(auto&& v : v1) {
    std::cout << v << ",";
  }
  std::cout << "\n";
  for(auto&& v : v2) {
    std::cout << v << ",";
  }
  std::cout << "\n"; */
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