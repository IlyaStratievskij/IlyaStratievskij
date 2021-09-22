#include <iostream>
#define MAX 1048576
#define ten 10
#define five 5 
#define twenty 20

using namespace std;

class SmallAllocator {
private:
    char Memory[MAX];
    int offset;
public:
    SmallAllocator():offset(0) {} // Инициализация структуры данных менеджера памяти
    void *Alloc(unsigned int Size) {
        offset += Size;
        if (offset < MAX) // память ещё есть
            return (void*) ((char*) Memory + offset - Size) ;
        else {
            offset -= Size;
            return nullptr;
        }
    };
    void *ReAlloc(void *Pointer, unsigned int Size) {
        if (offset + Size >= MAX)
            return nullptr;
        for (int i = 0; i < Size; i++) 
            *(Memory + offset + i) = *((char*) Pointer + i);
        
        offset += Size;
        return (void*) ((char*)Memory + offset - Size);
    };
    void Free(void *Pointer) {
        Pointer = nullptr;
        offset = 0;	
    };
};

int main () {
    SmallAllocator A1;
    int * A1_P1 = (int *) A1.Alloc(sizeof(int));
    A1_P1 = (int *) A1.ReAlloc(A1_P1, 2 * sizeof(int));
    A1.Free(A1_P1);
    SmallAllocator A2;
    int * A2_P1 = (int *) A2.Alloc(ten * sizeof(int));
    for(unsigned int i = 0; i < ten; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < ten; i++) if(A2_P1[i] != i) std::cout << "ERROR 1" << std::endl;
    int * A2_P2 = (int *) A2.Alloc(ten * sizeof(int));
    for(unsigned int i = 0; i < ten; i++) A2_P2[i] = -1;
    for(unsigned int i = 0; i < ten; i++) if(A2_P1[i] != i) std::cout << "ERROR 2" << std::endl;
    for(unsigned int i = 0; i < ten; i++) if(A2_P2[i] != -1) std::cout << "ERROR 3" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, twenty * sizeof(int));
    for(unsigned int i = ten; i < twenty; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < twenty; i++) if(A2_P1[i] != i) std::cout << "ERROR 4" << std::endl;
    for(unsigned int i = 0; i < ten; i++) if(A2_P2[i] != -1) std::cout << "ERROR 5" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, five * sizeof(int));
    for(unsigned int i = 0; i < five; i++) if(A2_P1[i] != i) std::cout << "ERROR 6" << std::endl;
    for(unsigned int i = 0; i < ten; i++) if(A2_P2[i] != -1) std::cout << "ERROR 7" << std::endl;
    A2.Free(A2_P1);
    A2.Free(A2_P2);
}
