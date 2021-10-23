#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  assert(a > 0 && b > 0);

  while (true) {
    a %= b;
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
  }
}

int main(void) {
  std::int32_t a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}