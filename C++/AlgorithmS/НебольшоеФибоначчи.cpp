#include <cassert>
#include <iostream>
#include <cmath>

class Fibonacci final {
 public:
  static int get(int n) {
    assert(n >= 0);
      n = 1/sqrt(5)* ( pow((1 + sqrt(5))/2, n) - pow((1 - sqrt(5))/2, n));
    return n;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}