#ifndef _MY_VECTOR_H_INCLUDED
#define _MY_VECTOR_H_INCLUDED

#include <cstddef>
#include <cstring>

class MyVector {
public:
    MyVector(std::size_t init_capacity = 2);
    MyVector(const MyVector& another_vector);
    MyVector& operator=(const MyVector& another_vector);
    ~MyVector();

    void set(std::size_t index, int value);
    int get(std::size_t index);

    std::size_t size();
    std::size_t capacity();

    void reserve(std::size_t new_capacity);
    void resize(std::size_t new_size);

    void push_back(int value);
    void insert(std::size_t index, int value);
    void erase(std::size_t index);

private:
    std::size_t _size, _capacity;
    int * _data;
};

#endif
