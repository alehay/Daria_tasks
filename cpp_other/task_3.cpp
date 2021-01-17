/*
 *Найти пересечение двух множеств (векторов) и записать его в третий вектор. 
 вывод: 
107 118 237 247
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
    std::vector<int> v1{100,229,104,107,108,109,110,237,251,241,115,116,118,247,123};
    std::vector<int> v2{11,19,20,22,32,34,48,53,118,107,231,236,237,240,247,275,287,291,301,308};
    
   
    std::vector<int> v_intersection;
 
    // ...
    for(int n : v_intersection)
        std::cout << n << ' ';
    
    std::cout << std::endl;
}

// 