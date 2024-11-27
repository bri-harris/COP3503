#include <iostream>
using namespace std;

class MemExample {
  int _count;
  float* _someFloats;
  string _label;

public:
  MemExample() {
    _count = 0;
    _someFloats = nullptr;
    _label = "Bat";
  }

  void AllocateMemory(int count) {
    _count = count;
    _someFloats = new float[_count];
  }

  MemExample& operator=(const MemExample& otherObj) {
    _count = otherObj._count;

    _label = otherObj._label;

    // delete old memory previously allocated
    delete[] _someFloats;
    // then create the deep copy
    _someFloats = new float[_count];
    for (int i = 0; i < _count; i++)
      _someFloats[i] = otherObj._someFloats[i];

    return *this;
  }

  ~MemExample() { delete[] _someFloats; }
};

void Foo(const MemExample& A) {
  MemExample B;
  B = A;
}

// int main() {
//   MemExample A;
//   A.AllocateMemory(3);
//   Foo(A);
//
//   // int *ptr = new int[5];
//   // for (int i = 0; i < 5; i++) {
//   //     ptr[i] = i * 2;
//   // }
//   // int *deep = new int[5];
//   // for (int i = 0; i < 5; i++) {
//   //     deep[i] = ptr[i];
//   // }
//   return 0;
// }
