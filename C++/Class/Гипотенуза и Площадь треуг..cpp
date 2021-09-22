#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Triangle {
    double h;
    double ln;
    public:
    double p;
    Triangle(double a, double b);
    double hypotinuza() { return ln; }
    void area();
    
};

Triangle::Triangle(double a, double b) {
    ln = sqrt( a*a + b*b);
    p = (ln + a + b) / 2.0;
    h = (2.0 / a) * sqrt(p*(p - a)*(p - b)*(p - ln));
}

void Triangle::area() {
   cout << endl << "Площадь треугольника = " <<  0.5 * ln * h;
}


int main(){
    
    float a1, b1;
    cin >> a1 >> b1;
    Triangle dlina(a1, b1);
    
    cout << setprecision(2) << fixed;
    cout << "Длина гипотенузы = " << dlina.hypotinuza();
    
    dlina.area();
    
    
}