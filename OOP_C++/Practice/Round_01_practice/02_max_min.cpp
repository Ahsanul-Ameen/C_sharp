/**
 * @file 02_max_min.cpp
 * @author Ahsanul Ameen (ahsanulsabit7@gmail.com)
 * @brief Given an array find its 1st and 2nd max, min in a single loop
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>
using namespace std;

void PrintMinMax(int* arr, int n) {
    int f_max = INT_MIN, s_max = INT_MIN;
    int f_min = INT_MAX, s_min = INT_MAX;

    for ( int i = 0; i < n; ++i ) {
        if (arr[i] > f_max) {
            s_max = f_max, f_max = arr[i];
        } else if (arr[i] > s_max) {
            s_max = arr[i];
        }
        if (arr[i] < f_min) {
            s_min = f_min, f_min = arr[i];
        } else if (arr[i] < s_min) {
            s_min = arr[i];
        }
    }
    cout << f_max << " " << s_max << " | " << s_min << " " << f_min << endl;
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

    PrintMinMax(arr, n);

    return 0;
}


