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
 


void solve(int nt) {

	string str;
	cin >> str;

	string res;

	for(const char& ch : str) {
		if(res.empty())
			res.push_back(ch);
		else if(res.back() < ch) {
			//replace "ab -> b"
			res.pop_back();
			res.push_back(ch);

			// now remove unncessary char if needed
			while(res.size() >= 2) {

				int n = res.size();
				
				if(res[n-2] <= res[n-1]) {
					char last_char = res[n-1];
					res.pop_back();
					res.pop_back();
					res.push_back(last_char);
				}
			}

		} else if(res.back() > ch) {
			res.push_back(ch);
		}
	}

	cout << res << endl;

}



int main(int argc, char** argv) {
    fast_io
    
   	int T = 1; // default
   	cin >> T;

   	for(int t = 1; t <= T; t++) {
   		solve(t);
   	}



    return 0;
}


// https://toph.co/p/compressed-string