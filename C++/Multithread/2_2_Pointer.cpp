#include <iostream>

class StringPointer {
    std::string *pointer;
public:
    StringPointer(std::string *p) { pointer = p ? new std::string(*p) : new std::string("");}
    ~StringPointer () { delete pointer; }
    std::string *operator->() { return pointer; }
    operator std::string*() {  return pointer; }
};

int main() {
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(NULL);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;
}




































