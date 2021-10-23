// Последняя цифра большого числа Фибоначчи 
#include <cassert>
#include <iostream>

class Fibonacci final {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
      int a = 0, b = 1;
      for (int i = 0; i < n; i++) {
          a = a + b;
          b = a - b;
          if (a >= 10) a %= 10;
          if (b >= 10) b %= 10;
      }
    return a;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}