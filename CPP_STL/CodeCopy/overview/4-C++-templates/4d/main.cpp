#include <iostream>
#include <algorithm>

#include "stack.h"

#include "simple_string.h"

using namespace std;

int main() {
  // Multiple stacks that are created automatically.
  stack<simple_string> s1(1), s2(2);

  cout << "begin copy constructor" << endl;
  stack<simple_string> s3(s2);
  cout << "end copy constructor" << endl;

  cout << "begin move constructor" << endl;
  stack<simple_string> s4(std::move(s2));
  cout << "end move constructor" << endl;

  int item = 0;

  cout << "begin push(const &)" << endl;
  while (!s1.full()) {
      simple_string s (std::to_string(item++).c_str());
      s1.push(s);
  }
  cout << "end push(const &)" << endl;

    cout << "begin pop()" << endl;
    while (!s1.empty()) {
        cout << "top item = " << s1.top() << endl;
        s1.pop();
    }
    cout << "end pop()" << endl;

  cout << "begin push(&&)" << endl;
  while (!s1.full())
    s1.push(std::to_string(item++).c_str());
  cout << "end push(&&)" << endl;

  cout << "begin pop()" << endl;
  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }
  cout << "end pop()" << endl;

  cout << "begin emplace()" << endl;
  while (!s1.full())
    s1.emplace(std::to_string(item++).c_str());
  cout << "end emplace()" << endl;

  cout << "begin pop()" << endl;
  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }
  cout << "end pop()" << endl;

  cout << "begin copy assignment operator" << endl;
  s1 = s2; // No aliasing problem with assignment
  cout << "end copy assignment operator" << endl;

  cout << "begin move assignment operator" << endl;
  s1 = std::move(s2); // move assignment.
  cout << "end move assignment operator" << endl;

  // Termination is handled automatically.
  cout << "calling destructors" << endl;

  return 0;
}
