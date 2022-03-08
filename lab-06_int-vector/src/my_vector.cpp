#include "my_vector.hpp"
#include <cassert>
#include <algorithm>

MyVector::MyVector(std::size_t init_capacity) {
    _capacity = init_capacity;
    _size = 0;
    _data = new int[_capacity];
}

MyVector &MyVector::operator=(const MyVector& another_vector) {
    if (&another_vector == this)
        return *this;
    
    delete [] _data;

    _size = another_vector._size;
    _capacity = another_vector._capacity;
    _data = new int[_capacity];
    memcpy(_data, another_vector._data, sizeof(int) * _size);
    return *this;
}

MyVector::MyVector(const MyVector& another_vector) {
    if (&another_vector == this)
        return;

    _capacity = another_vector._capacity;
    _size = another_vector._size;
    _data = new int[_capacity];
    memcpy(_data, another_vector._data, sizeof(int) * _size);
}

MyVector::~MyVector() {
    _capacity = 0;
    _size = 0;
    delete[] _data;
}

void MyVector::set(size_t index, int value) {
    assert(_size > index);
    _data[index] = value;
}

int MyVector::get(size_t index) {
    assert(_size > index);
    return _data[index];
}

size_t MyVector::size() {
    return _size;
}

size_t MyVector::capacity() {
    return _capacity;
}

void MyVector::reserve(size_t new_capacity) {
    if (new_capacity < _capacity)
        return;
    int* new_data = new int[new_capacity];
    assert(new_data && "Unable to allocate memory");
    memcpy(new_data, _data, sizeof(int) * _capacity);
    delete [] _data;
    _data = new_data;
    _capacity = new_capacity;
}

void MyVector::resize(size_t new_size) {
    if (new_size > _capacity)
        reserve(std::max(new_size, 2 * _capacity));
    if (new_size > _size)
        memset(_data + _size, 0, sizeof(int) * (new_size - _size));
    _size = new_size;
}

void MyVector::push_back(int value) {
    if (_size == _capacity)
        reserve(2 * _capacity);
    _data[_size++] = value;
}

void MyVector::insert(size_t index, int value) {
    assert(index <= _size);
    if (_size == _capacity)
        reserve(2 * _capacity);
    memmove(_data + index + 1, _data + index, sizeof(int) * (_size - index));
    _data[index] = value;
    _size++;
}

void MyVector::erase(size_t index) {
    assert(index < _size);
    memmove(_data + index, _data + index + 1, sizeof(int) * (_size - index - 1));
    _size--;
}