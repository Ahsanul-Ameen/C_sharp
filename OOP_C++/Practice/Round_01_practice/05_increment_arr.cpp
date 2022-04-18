/**
 * @file 05_increment_arr.cpp
 * @author Ahsanul Ameen (ahsanulsabit7@gmail.com)
 * @brief given an array contains digits of an integer, add a digit to it
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void AddDigit(int* arr, int n, int digit) {
    int c = digit;
    // 8 9 9 
    //     3
    // 9 0 2
    for (int i = n - 1; i >= 0; --i) {
        if (!c) break;

        arr[i] += c;
        c = arr[i] / 10; // carry propagate
        arr[i] %= 10;
    }
    if (c > 0) {
        cout << "Carry overflow: " << c << endl;
    }
}



void PrintArray(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
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

    cout << "Enter digit to add: ";
    int digit;
    cin >> digit;

    PrintArray(arr, n);
    AddDigit(arr, n, digit);

    cout << " + " << digit;
    cout << " = ";
    PrintArray(arr, n);
    cout << endl; 

    return 0;
}


