/**
 * @file 03_avg_without_max_min.cpp
 * @author Ahsanul Ameen (ahsanulsabit7@gmail.com)
 * @brief find average of an array without largest and smallest elements
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

double get_average(int* arr, int n) {
    double sum = 0;
    if (n < 3)
        return sum;
    int maxi = INT_MIN, maxc = 0;
    int mini = INT_MAX, minc = 0;

    for(int i = 0; i < n; ++i) {
        sum += arr[i];

        if (arr[i] > maxi) {
            maxi = arr[i];
            maxc = 1;
        } else if (arr[i] == maxi) {
            ++maxc;
        }
        
        if (arr[i] < mini) {
            mini = arr[i];
            minc = 1;
        } else if (arr[i] == mini) {
            ++minc;
        }
    }

    int rem = n - minc - maxc;
    sum -= minc * mini + maxc * maxi;

    return rem > 0 ? sum / rem : 0;
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

    cout << "Average without max_min : " << get_average(arr, n) << endl;

    return 0;
}


