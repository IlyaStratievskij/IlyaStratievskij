#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Foo {
    Foo() { cout << "Foo" << endl; }
    void show() { cout << "Hi" << endl; }
    ~Foo() { cout << "~Foo" << endl; }
};

class DeleteFoo {
public:
    void operator() (Foo *p) const {
        cout << "Call delete for Foo object" << endl;
        delete p;
    }
};

int main() {
    //UNIQUE_PTR
    cout << "unique_ptr" << endl << endl;
    {
        unique_ptr <Foo> p1(new Foo);
        if (p1) p1->show();
        {
            unique_ptr<Foo> p2(move(p1));
            if (!p1) cout << "pi is empty" << endl;
            
            p1 = move(p2);
            if (!p2) cout << "pi2 is empty" << endl;
        }
        
        if (p1) p1->show();
    }
    
    // SHARED_PTR
    cout << endl << "shared_ptr" << endl << endl;
    {
        shared_ptr<Foo> ab1;
        
        shared_ptr<Foo> ab2(new Foo);
        
        shared_ptr<Foo> ab3(ab2);
        
        cout << ab2.use_count() << endl;
        cout << ab3.use_count() << endl;
        
        ab2->show();
        ab3->show();
        
        shared_ptr<Foo> ab4(new Foo, DeleteFoo());
        
    }
    
    // DEFAULT_DELETE
    {
        unique_ptr<int> ptr1(new int(5));
    
        unique_ptr<int[]> ptr2(new int[10]);
    
        shared_ptr<int> shared_good(new int[10], default_delete<int[]>());
    
        vector<int*> v;
        for (int i = 0; i < 100; i++) 
            v.push_back(new int(n));
        for_each(v.begin(), v.end(), default_delete<int>());
    }
    
    // WEAK_PTR
    cout << endl << "weak_ptr" << endl << endl;
    {
        shared_ptr<Foo> a1(new Foo());
        
        shared_ptr<Foo> a2 = a1;
        
        weak_ptr<Foo> w = a2;
        
        a2.reset();     // обнуление значения в указатиле
        
        a2 = w.lock();
        
        a2.reset();
        a1.reset();
        
        shared_ptr<Foo> a0 = w.lock();  // не сработает, так как после удаления всех сильных указателей
    }                                   // слаюый приходит в негодность
}




































