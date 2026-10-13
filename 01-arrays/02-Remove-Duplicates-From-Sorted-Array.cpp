#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Put all numbers into a set, which keeps only unique numbers in sorted order.
Copy those unique numbers back into the original array.
Return how many unique numbers are present.

Time Complexity: O(n log n) - Adding numbers to the set takes time.
Space Complexity: O(n) - The set stores the unique numbers.
*/
int brute_remove_duplicates(vector<int>& numbers) {
    set<int> uniqueNumbers;

    for (int number : numbers) {
        uniqueNumbers.insert(number);
    }

    int uniqueCount = 0;

    for (int number : uniqueNumbers) {
        numbers[uniqueCount] = number;
        uniqueCount++;
    }

    return uniqueCount;
}

/*
Approach:
Keep the first number and look for new numbers.
Whenever a different number is found, put it in the next available position.
Return how many unique numbers are present.

Time Complexity: O(n) - We check each number once.
Space Complexity: O(1) - We use only a few extra variables.
*/
int optimal_remove_duplicates(vector<int>& numbers) {
    int totalNumbers = numbers.size();

    if (totalNumbers == 0) {
        return 0;
    }

    int uniqueCount = 1;

    for (int currentIndex = 1; currentIndex < totalNumbers; currentIndex++) {

        if (numbers[currentIndex] != numbers[uniqueCount -1]) {
            numbers[uniqueCount] = numbers[currentIndex];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    vector<int> firstArray = {1, 2, 2, 3, 3, 7};
    vector<int> secondArray = {11, 22, 99, 112, 112};

    int bruteResult = brute_remove_duplicates(firstArray);

    cout << "Brute Force: ";
    for (int index = 0; index < bruteResult; index++) {
        cout << firstArray[index] << " ";
    }
    cout << "\nUnique count: " << bruteResult << endl;

    int optimalResult = optimal_remove_duplicates(secondArray);

    cout << "Optimal: ";
    for (int index = 0; index < optimalResult; index++) {
        cout << secondArray[index] << " ";
    }
    cout << "\nUnique count: " << optimalResult << endl;

    return 0;
}