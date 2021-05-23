#include <iostream>

#include "matrix.hpp"

Matrix mul_matrix (Matrix a, Matrix b) {
    if  (a.getRowCount() != b.getColCount()) {
        throw std::invalid_argument("invalid row or col to multyply");
    }
    Matrix result (a.getRowCount(), b.getColCount());
    
    // для каждой строки  А
    for (int i = 0; i < result.getRowCount(); ++i) {
        for (int j = 0; j < result.getColCount(); ++j) {
            double result_cell {0};

            for (int k = 0; k < a.getColCount() && k < b.getRowCount(); ++k) {
                result_cell += a.at(i,k)*b.at(k,j);
                // a[i][k] * b[k][j] -> c[i][j]
            }
            result.put(i,j,result_cell);
        }
    }
    
    return result;

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
    std::cout<< "result" <<std::endl;
    Matrix c = mul_matrix(a,b);
    c.print();
}