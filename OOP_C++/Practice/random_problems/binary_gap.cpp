/**
 * @file binary_gap.cpp
 * @author your name (you@domain.com)
 * @brief A binary gap within a positive integer N is any maximal sequence of 
 *        consecutive zeros that is surrounded by ones at both ends in the binary 
 *        representation of N.
 *        
 *        For example, number 9 has binary representation 1001 and 
 *        contains a binary gap of length 2. 
 *        The number 529 has binary representation 1000010001 and contains 
 *        two binary gaps: one of length 4 and one of length 3. 
 *        The number 20 has binary representation 10100 and contains 
 *        one binary gap of length 1. 
 *        The number 15 has binary representation 1111 and has no binary gaps. 
 *        The number 32 has binary representation 100000 and has no binary gaps.
 * 
 *        Write a function: int solution(int N);
 * 
 *        that, given a positive integer N, returns the length of its longest binary 
 *        gap. The function should return 0 if N doesn't contain a binary gap.
 * 
 *        For example, given N = 1041 the function should return 5, 
 *        because N has binary representation 10000010001 and so its 
 *        longest binary gap is of length 5. 
 *        Given N = 32 the function should return 0, 
 *        because N has binary representation '100000' and thus no binary gaps.
 * 
 *        Write an efficient algorithm for the following assumptions:
 *        N is an integer within the range [1..2,147,483,647].
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

int binGap(int n) {
    bool left_bound = false;
    int zeros = 0;
    int max_gap = 0;

    int len = sizeof (int) * 8; // bits

    for (int pos = 0; pos < len; ++pos) {
        if (check(n, pos)) { // found a one
            if (left_bound) { // previously found a one
                max_gap = max(max_gap, zeros);
            }
            left_bound = true;
            zeros = 0;
        } else if (left_bound) {
            ++zeros;
        }
    }

    return max_gap;
}


int main(int argc, char **argv) {
    

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        cout << "case " << t << " : " << binGap(n) << endl;
    }
   
    
    return 0;
}