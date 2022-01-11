#include "stack.h"
#include <cassert>
#include <iostream>

using namespace std;

void test1() {
    cout << "-- Test 1 --" << endl;

    Stack s;

    s.push(5);
    s.push(7);
    s.push(3);
    s.push(1);
    s.push(7);

    assert(s.peek() == 7);
    assert(s.pop() == 7);

    assert(s.peek() == 1);
    assert(s.pop() == 1);

    assert(s.pop() == 3);
    assert(s.pop() == 7);
    assert(s.pop() == 5);

    cout << "Test 1 success." << endl << endl;
}

void test2() {
    cout << "-- Test 2 --" << endl;

    Stack s;

    assert(s.isEmpty());

    s.push(1);
    s.push(2);
    s.push(13);
    s.push(12);

    assert(s.getSize() == 4);
    assert(!s.isEmpty());

    cout << "Test 2 success." << endl << endl;
}

void test3() {
    cout << "-- Test 3 --" << endl;

    Stack s1;

    s1.push(3);
    s1.push(5);
    s1.push(7);

    Stack s2(s1);

    s1.pop();
    s1.pop();
    s1.pop();

    assert(s1.isEmpty());
    assert(!s2.isEmpty());

    assert(s2.getSize() == 3);

    assert(s2.peek() == 7);
    assert(s2.pop() == 7);

    assert(s2.peek() == 5);
    assert(s2.pop() == 5);

    assert(s2.pop() == 3);

    assert(s2.isEmpty());

    cout << "Test 3 success." << endl << endl;
}

int main() {
    cout << "Hello world!" << endl;
    cout << "Beginning tests..." << endl;

    test1();
    test2();
    test3();

    cout << "Tests completed successfully!" << endl;

    return 0;
}
