#include "Rectangle.hpp"
#include <cstdio>
#include <cstdlib>

Rectangle::Rectangle(int id, int x, int y, int width, int height): Figure{id, x, y}, width{width}, height{height} {};

Rectangle::~Rectangle() {};

void Rectangle::print() const {
    printf("Rectangle ");
    Figure::print();
    printf(" width = %d height = %d\n", width, height);
};

bool Rectangle::is_inside(int x, int y) const {
    return 2 * std::abs(this->x - x) <= width && 2 * std::abs(this->y - y) <= height;
};

void Rectangle::zoom(int factor) {
    width *= factor;
    height *= factor;
};
