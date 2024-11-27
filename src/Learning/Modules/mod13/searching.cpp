#include <vector>
#include <iostream>
using namespace std;


bool BinarySearch(vector<int>& numbers, int val) {
    int numTries = 0;
    int lowIndex = 0;
    int highIndex = numbers.size() - 1;

    while (lowIndex <= highIndex) {
        numTries++;
        int midPoint = lowIndex + (highIndex - lowIndex) / 2;
        if (numbers[midPoint] == val) {
            cout << "Found " << val << " in " << numTries << " searches!" << endl;
            return true;
        } else if (numbers[midPoint] > val)
            highIndex = midPoint - 1;
        else if (numbers[midPoint] < val)
            lowIndex = midPoint + 1;
    }
    cout << "After " << numTries << " searches, the value " << val << " was not found." << endl;
    return false;
}
bool LinearSearch(vector<int>& numbers, int val) {
    for (unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == val) {
            cout << "Found " << val << " in " << i + 1 << " searches!" << endl;
            return true;
        }
    }
    cout << "After " << numbers.size() << " searches, the value " << val << " was not found." << endl;
    return false;
}


int main() {
    //create initial data
    std::vector<int> numbers;
    for (int i = 1; i <= 100000; i++)
        numbers.push_back(i);

    while (true) {
        int input;
        cin >> input;
        if (input == -1)
            break;

        cout << "Binary Search: ";
        BinarySearch(numbers, input);

        cout << "Linear Search: ";
        LinearSearch(numbers, input);
    }

    return 0;
}
