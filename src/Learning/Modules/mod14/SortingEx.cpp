#include <iostream>
#include <vector>
#include <algorithm>
#include "Random.h"
#include "Hero.h"
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

bool Ascending(int a, int b) {
    return a > b;
}

int main() {
    //create initial data
    // vector<int> numbers;
    // int count = 30;
    // for (int i = 0; i <= 30; i++)
    //     numbers.push_back(Random::Int(1, 50));
    //
    // sort(numbers.begin(), numbers.end(), [](int a, int b) {
    //     return a > b;
    // });
    // cout << "Sorting in descending order..." << endl;
    // PrintNumbers(numbers);
    //
    // sort(numbers.begin(), numbers.end());
    // cout << endl << endl << "Sorting in Ascending order..." << endl;
    // PrintNumbers(numbers);
    //
    // cout << endl << endl;

    vector<Hero> heroes;
    heroes.push_back(Hero("Thor", 50, 125));
    heroes.push_back(Hero("Spider-Man", 35, 70));
    heroes.push_back(Hero("Batman", 20, 40));
    heroes.push_back(Hero("Wolverine", 30, 55));

    auto lambda = [](Hero& h1, Hero& h2) {
        return h1.GetHitpoints() < h2.GetHitpoints();
    };

    sort(heroes.begin(), heroes.end(), lambda);
    for (int i = 0; i < heroes.size(); i++)
        heroes[i].PrintInfo();
    cout << endl << endl;

    sort(heroes.begin(), heroes.end(), [](Hero& h1, Hero& h2) {
        return h1.GetName() > h2.GetName();
    });

    for (int i = 0; i < heroes.size(); i++)
        heroes[i].PrintInfo();
    cout << endl << endl;

    string input;
    getline(cin, input);
    auto result = find_if(heroes.begin(), heroes.end(), [&input](Hero& h1) {
        return h1.GetName() == input;
    });
    if (result != heroes.end())result->PrintInfo();
    else cout << "search term not found" << endl;


    return 0;
}
