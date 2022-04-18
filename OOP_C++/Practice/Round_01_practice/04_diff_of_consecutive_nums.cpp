/**
 * @file 04_diff_of_consecutive_nums.cpp
 * @author Ahsanul Ameen (ahsanulsabit7@gmail.com)
 * @brief check if the differences of consecutive integers are same or not
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>
using namespace std;

bool HasSameDiff(int arr[], int n) {
    if (n < 3)
        return true;
    int diff = arr[1] - arr[0];
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] + diff != arr[i + 1])
            return false;
    }
    return true;
}

int main(int argc, char **argv) {

    cout << "Enter array size: ";
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array has " << (HasSameDiff(arr, n) ? "same " : "different ") << "consecutive difference" << endl;

    return 0;
}


