/**
 * @file 07_cap_rev_word_letters.cpp
 * @author Ahsanul Ameen 
 * @brief  Capitalize first and last character of each word in a sentence. Also reverse every word
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {

    string str;
    getline(cin, str);

    int l = -1, r;
    for (int i = 0, n = str.length(); i < n; ++i) {
        if (isalpha(str[i])) {
            if (l == -1) {
                l = r = i;
            } else r = i;
        }
        if (!isalpha(str[i]) or i == n - 1) {
            if (l != -1) {
                str[l] &= ~32;
                str[r] &= ~32;
                reverse(str.begin() + l, str.begin() + r + 1);
            }
            l = -1;
        }
    }

    cout << str << endl;

    return 0;
}