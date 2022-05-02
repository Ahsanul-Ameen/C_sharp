/**
 * @file divisible_cnt.cpp
 * @author Ahsanul Ameen Sabit (you@domain.com)
 * @brief Write a function:

    class Solution { public int solution(int A, int B, int K); }

    that, given three integers A, B and K, 
    returns the number of integers within the range [A..B] that are divisible by K,
     i.e.: { i : A ≤ i ≤ B, i mod K = 0 }

    For example, for A = 6, B = 11 and K = 2, your function should return 3, 
    because there are three numbers divisible by 2 within the range [6..11], 
    namely 6, 8 and 10.

    Write an efficient algorithm for the following assumptions:

    A and B are integers within the range [0..2,000,000,000];
    K is an integer within the range [1..2,000,000,000];
    A ≤ B
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// return true if position has a one
inline bool check(int n, int pos) {
    return (n >> pos) & 1;
}

class Solution { 
public:
    int solution(int A, int B, int K); 
};

int Solution::solution(int A, int B, int K) {
    return (B / K) - (A / K) + (A % K == 0 ? 1 : 0);
}

int main(int argc, char **argv) {
    

    Solution s;
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << "case " << t << " : " <<  s.solution(a, b, k) << endl;
    }
   
    
    return 0;
}