#ifndef _MY_MATRIX_HPP_
#define _MY_MATRIX_HPP_

#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix
{
private:
    int row_count;
    int col_count;
    std::vector<double> element;
        
public:
    Matrix() = delete;
    Matrix(int row_c, int col_c) : row_count{row_c}, col_count{col_c} {
       element.resize(row_count*col_count);
    }
    auto at (int row, int col ) {
        if ( row > row_count || col > col_count) {
            throw std::invalid_argument("invalid row or col");
        }
        return element.at(row*col_count+col);
    }
    void read_in_line(double * arr, int row, int col) {
        row_count = row;
        col_count = col; 
        for (int i = 0 ; i < row * col ; ++i ) {
            element.at(i) = arr [i];
        }
    }
    void read_in_vec(std::vector <double> vec) {
        if(vec.size() == element.size()) {
            element.swap(vec);
        }
    }
    void print (){
        std::cout<<"\n";
        for (int row = 0; row < row_count ; ++row) {
            for (int col = 0; col < col_count; ++col){
                std::cout << this->at(row, col)<< ", ";
            }
            std::cout << std::endl;
        }
    }

    ~Matrix();
};

Matrix::~Matrix()
{
}

#endif //_MY_MATRIX_HPP_