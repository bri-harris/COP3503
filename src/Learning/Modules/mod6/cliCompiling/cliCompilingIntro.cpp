#include <iostream>
using namespace std;

int main(const int argc, const char** argv) {
    if (argc > 1) {
        for (int i = 0; i < argc; i++)
            cout << "Arg #" << i << argv[i] << endl;
    }
    return 0;
}
