/**
 * @file 01_palindrome_number.cpp
 * @author your name (you@domain.com)
 * @brief given an integer number, check whether it is a palindrome or not 
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
    int rn = 0;
    do { // give it a chance for digit 0 case
        rn = 10*rn + n%10;
        n /= 10;
    } while (n != 0);
    return rn;
}

bool isPalindrome(int n) {
    return n == reverse(n);
}

int main(int argc, char **argv) {

    cout << "Enter a number" << endl;

    int n;
    cin >> n;

    cout << n << " is " << (isPalindrome(n) ? "" : " not ") << " a palindrome" << endl;

    return 0;
}


