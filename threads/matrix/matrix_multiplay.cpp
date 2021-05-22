#include <iostream>

#include "matrix.hpp"

Matrix mul_matrix (Matrix a, Matrix b) {
    if  
}

int main (int, char**) {
    Matrix a(3,2);
    std::vector<double> arr { 
        1, 2, 
        3 ,4,
        5, 6 };
    a.read_in_vec(arr);
    Matrix b(2,3);
    std::vector<double> arr2 { 
        7, 8, 9,
        3 ,4, 8 };
    b.read_in_vec(arr2);
    a.print();
    b.print();

}