#include <iostream>
#define SIZE 10

using namespace std;

template <typename T>
class MP {
    T* t;
public:
    MP() : t(new T) {
        cout << "MP() " << this << " = " << t << endl;
    }
    *MP(const MP<T> &mp) : t(new T(*mp.t)) {
        cout << "MP() " << this << " = " << t << endl;
    }
    MP<T>& operator=(const MP<T>& mp) {
        if (&mp != this) {
            delete t;
            t = new T(*mp.t);
        }
        return *this;
    }
    T* operator-> () { return t; }
    T& operator* () { return *t; }
    
    ~MP() {
        cout << "~MP() " << this << " = " << t << endl;
        delete t;
    }
};

class Foo {
    friend class MP<Foo>;
    char *str;
protected:                                          // помещая конструтор и деструктор в protected, мы не сможем 
    Foo () { cout << "Foo() " << this << endl; }    // создать экземпляр этого класса самостоятельно => создаётся 
    ~Foo() { cout << "~Foo() " << this << endl; }   // через умный указатель (MP)
public:
    void init(char *_str) { str = _str; }
    void show() { cout << str << endl; }
};

int main() {
    //while (true) {
        MP <Foo> sp;
        sp->init("sp");
        sp->show();
        
        MP<Foo> sp2(sp);
        
        MP<Foo> sp3 = sp2;
        sp3->show();
        
        sp = sp3;
    //}
    
    
}