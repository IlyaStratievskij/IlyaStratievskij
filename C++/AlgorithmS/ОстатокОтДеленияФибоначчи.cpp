// огромное число Фибоначчи по модулю
// необходимо найти остаток от деления nn-го числа Фибоначчи на mm.
#include <cmath>
#include <cassert>
#include <cstdint>
#include <iostream>

#define ULL unsigned long long

using namespace std;
class Fibonacci final {
    public:
        static int get_remainder(ULL n, ULL m) {
            assert(n >= 1);
            assert(m >= 2);
            ULL arr[m*6];
            arr[0] = 0; arr[1] = 1;
            for (int i = 2; i < 6 * m; i++) {
                arr[i] = (arr[i-2] + arr[i-1]) % m;
                if (arr[i-1] == 0 && arr[i] == 1) {
                    m = i -1;
                    break;
                }
            }
            return arr[n % m];
        }
};

int main(void) {
  ULL n, m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}