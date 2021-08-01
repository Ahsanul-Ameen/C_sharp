#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define     endl               "\n"
#define     unsync_io          ios::sync_with_stdio(false);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(const auto& i: t) os<<i<<" "; return os; }
 



void test_case(int nt) {
	// write your coe here
	int n;
	cout << "Enter n : ";
	cin >> n;
	
	vector<vector<int>> layer(2, vector<int>(n, 0));
	layer[0][0] = 1;
	for(int l = 0; l < n; ++l) {
		
		layer[l&1][0] = 1;
		
		cout << string(n - l - 1, ' ');
		
		for(int i = 0; i <= l; ++i) {
			if(l > 0 && i > 0) {
				layer[l&1][i] = layer[(l-1)&1][i-1] ^ layer[(l-1)&1][i];
			}
			cout << (layer[l&1][i] == 1 ? '*' : ' ') << " ";
		}
		cout << endl;
	}
}


int main(int argc, char** argv) {
    //unsync_io
    //cin.tie(nullptr);
	
	
    int T = 1;	// default
	//cin >> T;	
    for(int nt = 1; nt <= T; ++nt) {	
		test_case(nt);
    }
    
    return 0;
}
// g++ -o pp.exe pascal_pattern.cpp && ./pp.exe >> out.txt