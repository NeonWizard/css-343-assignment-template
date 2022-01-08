#include "stack.h"
#include <vector>

using namespace std;

Stack::Stack() : _size(0) {}

Stack::Stack(const Stack &other) {
  _size = other._size;
  _data = other._data;
}

Stack::~Stack() {}

void Stack::push(const int x) {
  _data.push_back(x);
  _size++;
}

int Stack::pop() {
  int x = _data.back();
  _data.pop_back();
  _size--;

  return x;
}

int Stack::peek() { return _data.back(); }

bool Stack::isEmpty() { return _size == 0; }

int Stack::getSize() { return _size; }
