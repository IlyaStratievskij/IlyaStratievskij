#include <iostream>
using namespace std;

void println(bool b);
void println(int i);
void println(long i);
void println(char ch);
void println(char *str);
void println(double d);

void print(bool b);
void print(int i);
void print(long i);
void print(char ch);
void print(char *str);
void print(double d);

void print(char *str, int num);

int main() {
    println(true);
    println(10);
    println("It is just text");
    println('x');
    println(99L);
    println(123.23);

    print("something paramets: ");
    print(false);
    print(' ');
    print(88);
    print(' ');
    print(100000L);
    print(' ');
    print(100.1);

    println(" Ready! \n");

    print("Text", 18);
    return 0;
}

void println(bool b) {
    if (b) cout << "true \n";
    else cout << "false \n";
}

void println(int i) {
    cout << i << endl;
}

void println(long i) {
    cout << i << endl;
}

void println(char ch) {
    cout << "char ch " << ch << endl;
}

void println(char *str) {
    cout << "char str " << str << endl;
}

void println(double d) {
    cout << d << endl;
}

void print(bool b) {
    if (b) cout << "true";
    else cout << "false";
}

void print(int i) {
    cout << " int " << i;
}

void print(long i) {
    cout << "long " << i;
}

void print(char ch) {
    cout << "char " << ch;
}

void print(char *str) {
    cout << "char str " <<str;
}

void print(double d) {
    cout << "double " << d;
}

void print(char *str, int num) {
    while (num) {
        cout << " ";
        num--;
    }
    cout << str;
}
