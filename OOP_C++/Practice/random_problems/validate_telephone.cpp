/**
 * @file validate_telephone.cpp
 * @author Ahsnul Ameen Sabit (you@domain.com)
 * @brief Given two valid US number format 7831230564 and 783-123-0564 validate if a given
 *        string represents a US telephone number (asked in Therap R2)
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;


bool isValid(string str) {
    if (str.empty())
        return false;
    
    int n = str.size();

    
    if (n != 10 and n != 12)
        return false;
    
    int digs = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            ++digs;
        }
    }


    return (digs == 10) and 
           ((n == 10) or (n == 12 and str[3] == '-' and str[7] == '-'));
}

int main(int argc, char **argv) {
    
    string str;
    cin >> str;

    bool flag = isValid(str);

    cout << str << " is " << (flag ? "" : "not ") << "a valid US tel. no." << endl;
    
    return 0;
}