#include <iostream>
#include <vector>
#include <algorithm>
#include "Random.h"
using namespace std;

void PrintNumbers(vector<int>& numbers) {
    for (unsigned int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
}
void BubbleSort(vector<int>& numbers) {
    bool swapWasMade = true;

    while (swapWasMade) {
        swapWasMade = false;
        for (unsigned int i = 0; i < numbers.size() - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;

                swapWasMade = true;
            }
        }
    }
}
void SelectionSort(vector<int>& numbers) {
    /*∀ element in the array, search ∀Other element to find the smallest number
     * then swap that smallest number if necesary into the original element*/

    for (unsigned int i = 0; i < numbers.size() - 1; i++) {
        int minIndex = i; // <--------------------------------assume this is the smallest numbers location
        int sortedIndex = i; //<---------- dont really need this, just for code readability

        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minIndex])
                minIndex = j; //<----- update location of smallest number
        }
        // any changes?
        if (minIndex != sortedIndex) {
            int temp = numbers[minIndex];
            numbers[minIndex] = numbers[sortedIndex];
            numbers[sortedIndex] = temp;
        }
    }
}
void InsertionSort(vector<int>& numbers) {
    /*∀element in array
     *bubble that element forward until it can swap anymore*/
    for (unsigned int i = 1; i < numbers.size(); i++) {
        int currIndex = i;
        while (currIndex > 0 && numbers[currIndex] < numbers[currIndex - 1]) {
            //swap
            int temp = numbers[currIndex];
            numbers[currIndex] = numbers[currIndex - 1];
            numbers[currIndex - 1] = temp;

            currIndex--;
        }
    }
}


int main() {
    vector<int> numbers;
    for (int i = 0; i < 30; i++) {
        numbers.push_back(Random::Int(1, 50));
    }
    PrintNumbers(numbers);
    cout << endl;
    // BubbleSort(numbers);
    // SelectionSort(numbers);
    // InsertionSort(numbers);
    sort(numbers.begin(), numbers.end());
    PrintNumbers(numbers);

    return 0;
}
