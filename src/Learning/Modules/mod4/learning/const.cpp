#include <string>
#include <iostream>
#include <vector>
using namespace std;

// class Point {
//     float x, y;
//
// public:
//     float Distance(const Point& p) const;
//
//
// };
//
// float Point::Distance(const Point& p) const {
//     return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
// }

class Example {
    vector<int> _data;

public:
    vector<int>& GetData();

    const vector<int>& GetData() const;
};

vector<int>& Example::GetData() {
    return _data;
}

const vector<int>& Example::GetData() const {
    return _data;
}


void GetUserInput(Example& obj) {
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        obj.GetData().push_back(num);
    }
}

int CountEvens(const Example& obj) {
    const vector<int>& vals = obj.GetData();
    int count = 0;
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i] % 2 == 0) count++;
    }
    return count;
}

int main() {
    return 0;
}

