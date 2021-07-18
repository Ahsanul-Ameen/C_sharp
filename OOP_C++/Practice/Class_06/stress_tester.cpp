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
 



string addition (string str, string str2)
{
    int add;
    char carry;
    char sum = '0';
    string res = " ";
    int m = max(str.size(), str2.size());
    int n = min(str.size(), str2.size()); 
    string gtr(m-n, '0');
    if (str.size() == n)
    {
        reverse(str.begin(), str.end());
        str = str + gtr;
        reverse(str.begin(), str.end());
    }
    else if (str2.size() == n)
    {
        reverse(str2.begin(), str2.end());
        str2 = str2 + gtr;
        reverse(str2.begin(), str2.end());
    }
    
    for (int i = m-1; i >= 0; i--)
    {
        add = (str[i] - '0') + (str2[i] - '0') + (sum - '0');
        carry = add%10 + '0';
        sum = add/10 + '0';
        res.push_back(carry);
    }
    res.push_back(sum);
      if (res[res.size()-1] == '0')
    {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    //cout << res;
    return res;
}





void tester(ll a, ll b) {

	string add_value = addition(to_string(a), to_string(b));
	ll sum = stol(add_value);
	
	ll correct_sum = a + b;
	cout << sum << " | " << correct_sum << endl;
	
	if(sum != correct_sum) {
		cout << "____Input " << a << " + " << b << " failed___ [Checker: " << correct_sum << " ], [your_code: " << sum << "]\n";
	}
	assert(sum == correct_sum);
}


void stress_tester() {
	std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
	std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
                             //and seed it with entropy.

    //Define the distribution, by default it goes from 0 to MAX(unsigned long long)
    //or what have you.
    std::uniform_int_distribution<unsigned long long> distr;
	
	const ll MAX = 1e16 + 7;
	
	while(true) {
		ll a = distr(eng) % MAX;
		ll b = distr(eng) % MAX;
		
		tester(a, b);
	}
}


void test_case(int nt) {}


int main(int argc, char** argv) {
    //unsync_io
    //cin.tie(nullptr);
	
	stress_tester();
	
    int T = 1;	// default
	//cin >> T;	
    for(int nt = 1; nt <= T; ++nt) {	
		test_case(nt);
    }
    
    return 0;
}

