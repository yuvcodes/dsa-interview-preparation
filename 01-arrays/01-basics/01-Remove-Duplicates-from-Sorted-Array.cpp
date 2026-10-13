#include<bits/stdc++.h>
using namespace std;
/*
Approach:
Start with the smallest possible value.
Check each number and remember the biggest one found so far.
After checking all numbers, print the biggest number.

Time Complexity: O(n) - We check every number once.
Space Complexity: O(1) - We use only one extra variable.
*/

void get_largest_number(const vector<int> &arr) {
    int len = arr.size();
    int largest = INT_MIN;
    for(auto i: arr) {
        if(i>largest) largest = i;
    }

    cout << "largest number is: " << largest;
}

int main() {
    vector<int> arr_1 = {1, 2, 9, 2, 3};
    vector<int> arr_2 = {11, -2, 9, 2, 3};

    get_largest_number(arr_1);
    cout << endl;
    get_largest_number(arr_2);

}