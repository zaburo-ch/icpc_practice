#include "item.h"
#include <iostream>

using namespace std;

item::item() : x_(0), y_(0) {
  cout << "ctor()" << endl;
}

item::item(int x, int y) : x_(x), y_(y) {
  cout << "ctor(int x, int y) x=" << x << ", y=" << y << endl;
}

item::item(const item& other) : x_(other.x_), y_(other.y_) {
  cout << "ctor(const item& other) other=" << other << endl;
}

item::item(item&& other) : x_(other.x_), y_(other.y_) {
  cout << "ctor(item&& other) other=" << other << endl;
}

item::~item() {
  cout << "dtor() *this=" << *this << endl;
}

item& item::operator=(const item& other) {
  cout << "copy(const item& other) other=" << other << endl;
  x_ = other.x_;
  y_ = other.y_;
  return *this;
}

item& item::operator=(item&& other) {
  cout << "copy(item&& other) other=" << other << endl;
  x_ = other.x_;
  y_ = other.y_;
  return *this;
}

std::ostream& item::print_on(std::ostream& stream) const {
  return stream << '{' << x_ << ',' << y_ << '}';
}