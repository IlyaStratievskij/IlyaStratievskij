#include <iostream>

using namespace std;

struct Test {
    int get_i() { return i; } 
    void put_i(int j) { i = j; }
    private:
    int i;
};

// тоже самое, но в классах 
/*
class Test {
    int i;
    public:
    int get_i() { return i; } 
    void put_i(int j) { i = j; }
};
*/

int main(){
    Test s;
    
    s.put_i(10);
    cout << s.get_i();
}