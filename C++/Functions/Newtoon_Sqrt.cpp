#include <iostream>
#include <cmath>
#define FABS(x) ((x) < 0 ? -(x) : (x))
 
double newton_sqrt(double x, double precision = 1e-9)
{
  double result = 1.0, current;
  
  do
  {
    current = result;
    result = (current + x / current) / 2;
  } while (FABS(result - current) > precision);
  
  return result;
}

using namespace std;

int main() {
    double n;
    cin >> n; 
   
    cout << "My_Sqrt: " << newton_sqrt(n) << endl << "sqrt(n): " << sqrt(n);
}