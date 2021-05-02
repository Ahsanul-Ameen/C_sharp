#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define     endl               "\n"
#define     fast_io            ios::sync_with_stdio(false); cin.tie(0);
#define     file_io            freopen("input.txt", "r", stdin);   \
                               freopen("output.txt", "w", stdout);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }
 





int main(int argc, char** argv) {
    fast_io
#ifdef LOCAL
    file_io
#endif
   
    int n = 1e9;
    cout << n * n << endl;
    cout << 1LL * n * n << endl;
    cout << n * 1LL * n << endl;
    cout << n * (n * 1LL) << endl;    
    cout << n * n * 1LL << endl;
   

    return 0;
}




















