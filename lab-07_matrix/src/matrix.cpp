#include "matrix.h"
#include <utility>
#include <cstring>
#include <cassert>
#include <functional>
#include <iostream>


Matrix::Matrix(std::size_t row, std::size_t column) {
    _rows = row;
    _cols = column;
    if (row * column == 0) return;

    _data = new int*[_rows];
    for (int i = 0; i < (int)_rows; i++) {
        _data[i] = new int[_cols];
        memset(_data[i], 0, sizeof(int) * _cols);
    }
}

Matrix::Matrix(const Matrix& matrix) {
    if (this == &matrix) return;

    _rows = matrix.get_rows();
    _cols = matrix.get_cols();

    if(_rows * _cols == 0) return;
    
    _data = new int*[_rows];
    for (int current_row = 0; current_row < (int)_rows; current_row++) {
        _data[current_row] = new int [_cols];
        std::memcpy(_data[current_row], matrix._data[current_row], sizeof(int) * _cols);
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < (int)_rows; i++) {
        delete [] _data[i];
    }
    delete[] _data;
}

size_t Matrix::get_rows() const { 
    return _rows; 
}

size_t Matrix::get_cols() const { 
    return _cols; 
}

void Matrix::set(std::size_t i, std::size_t j, int val) {
    assert(i < _rows);
    assert(j < _cols);
    _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
    assert(i < _rows);
    assert(j < _cols);
    return _data[i][j];
}

void Matrix::print(FILE* f) const {
    for (int current_row = 0; current_row < (int)get_rows(); current_row++) {
        for (int current_col = 0; current_col < (int)get_cols(); current_col++)
            fprintf(f, (current_col == 0) ? "%d" : " %d", get(current_row, current_col));
        fprintf(f, "\n");
    }
}

bool Matrix::operator==(const Matrix& m) const {
    if (_rows != m.get_rows() || _cols != m.get_cols()) 
        return false;

    for (int current_row = 0; current_row < (int)_rows; current_row++) {
        for (int current_col = 0; current_col < (int)_cols; current_col++) {
            if (get(current_row, current_col) != m.get(current_row, current_col)) 
                return false;
        }
    }
	
    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !(m == *this);
}

Matrix& Matrix::operator+=(const Matrix& m) {
    return (*this = *this + m);
}

Matrix& Matrix::operator-=(const Matrix& m) {
    return (*this = *this - m);
}

Matrix& Matrix::operator*=(const Matrix& m) {
    return (*this = *this * m);
}

Matrix Matrix::operator+(const Matrix& m) const {
    return use_operation(m, [](int x, int y){ return x + y; });
}

Matrix Matrix::operator-(const Matrix& m) const {
    return use_operation(m, [](int x, int y){ return x - y; });
}

Matrix Matrix::operator*(const Matrix& m) const {
    Matrix result(get_rows(), m.get_cols());

    for (int current_row = 0; current_row < (int)_rows; current_row++)
        for (int current_col = 0; current_col < (int)m.get_cols(); current_col++) {
            int current_cell_sum = 0;
            for (int index = 0; index < (int)_cols; index++)
                current_cell_sum += get(current_row, index) * m.get(index, current_col);
            result.set(current_row, current_col, current_cell_sum);
        }

    return result;
}

Matrix Matrix::use_operation(const Matrix &m, const std::function<int(int, int)> f) const {
    Matrix temp(*this);
    for (int i = 0; i < (int)_rows; i++) {
        for (int j = 0; j < (int)_cols; j++)
            temp._data[i][j] = f(temp._data[i][j], m._data[i][j]);
    }
    return temp;
}

Matrix &Matrix::operator=(const Matrix &m) {
    if (this == &m) return *this;

    for (int i = 0; i < (int)_rows; i++) {
        delete [] _data[i];
    }
    delete [] _data;

    _cols = m.get_cols();
    _rows = m.get_rows();
    _data = new int*[_rows];
    for (int i = 0; i < (int)_rows; i++) {
        _data[i] = new int[_cols];
        memcpy(_data[i], m._data[i], sizeof(int) * _cols);
    }

    return *this;
}
