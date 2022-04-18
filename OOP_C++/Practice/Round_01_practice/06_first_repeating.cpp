/**
 * @file 06_first_repeating.cpp
 * @author  Ahsanul Ameen (ahsanulsabit7@gmail.com)
 * @brief find first repeating char with lowest second index
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;


string FirstRepeatingChar(const char* ara) {
    const int len = 26;
    int cnt[len] = {};

    for (int i = 0; ara[i] != '\0'; ++i) {
        if (++cnt[ara[i] - 'a'] == 2) {
            return string(1, ara[i]);
        }
    }
    return "-1";
}




int main(int argc, char **argv) {

    cout << "Enter string: ";
    string str;
    cin >> str;

    cout << FirstRepeatingChar(str.c_str()) << endl;

    return 0;
}


