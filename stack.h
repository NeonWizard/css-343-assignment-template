#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

class Stack {
  public:
    // default constructor
    Stack();

    // copy constructor
    Stack(const Stack& other);

    // destructor
    ~Stack();

    void push(const int x);
    int pop();
    int peek();

    bool isEmpty();
    int getSize();

  private:
    vector<int> _data;
    int _size;
};

#endif // STACK_H
