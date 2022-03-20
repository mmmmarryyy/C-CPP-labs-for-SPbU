#include "Scheme.hpp"
#include <cassert>

Scheme::Scheme(int capacity) : capacity{capacity}, size{0} {
    assert(capacity > 0);
    figures_ = new Figure*[capacity];
}

Scheme::~Scheme() {
    for (int i = 0; i < size; ++i)
        delete figures_[i];
    delete[] figures_;
}

int Scheme::find_id(int id) {
    for (int i = 0; i < size; ++i)
        if (figures_[i]->get_id() == id)
            return i;
    return -1;
}

void Scheme::push_back_figure(Figure* fg) {
    assert(fg != nullptr);
    assert(size < capacity);
    assert(find_id(fg->get_id()) == -1);
    
    figures_[size++] = fg;
}

void Scheme::remove_figure(int id) {
    int index = find_id(id);
    
    delete figures_[index];
    size--;
    
    for (int i = index; i < size; ++i)
        figures_[i] = figures_[i + 1];
}

void Scheme::print_all_figures() {
    for (int i = 0; i < size; ++i)
        figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor) {
    int index = find_id(id);
    assert(index != -1);
    figures_[index]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < size; ++i)
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
            
    return nullptr;
}


void Scheme::move(int id, int new_x, int new_y) {
    int index = find_id(id);
    assert(index != -1);
    figures_[index]->move(new_x, new_y);
}