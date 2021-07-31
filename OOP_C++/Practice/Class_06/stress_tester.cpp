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
 

//--------------------------------------------
string addition (string str, string str2)
{
    int add;
    char carry;
    char sum = '0';
    string res2 = "";
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
        res2.push_back(carry);
    }
    res2.push_back(sum);
      if (res2[res2.size()-1] == '0')
    {
        res2.pop_back();
    }
    reverse(res2.begin(), res2.end());
    return res2;
}

string multiply(string multiplicand, string multiplier)
{
    if(multiplicand.length() < multiplier.length())
        swap(multiplicand, multiplier);
    
    int m = multiplicand.length(), n = multiplier.length();
   
    string res("0"), temp;
    int multi, counter(0);
    char sum, carry;

    for (int i = n-1; i >= 0; i--)
    {
        temp = string(counter++, '0');
        carry = '0'; // it was missing

        for (int j = m-1; j >= 0; j--)
        {
            multi = (multiplicand[j]-'0') * (multiplier[i]-'0') + carry - '0';
            sum = multi % 10 + '0';
            carry = multi / 10 + '0';
            temp.push_back(sum);
        } 
        if(carry != '0')
            temp.push_back(carry);

        reverse(all(temp));
     
        res = addition(res, temp);
    }

    reverse(all(res));
    while(res.length() > 1 && res.back() == '0') res.pop_back(); // handle case like 12 * 0 = 0
    reverse(all(res));
    return res;
}
//---------------------------------------

using pcc = pair<char, char>;

pcc operateTwoChars(char a, char b, bool add = true) { // default value
    int ai(a-'0'), bi(b-'0');   
    (add) ? ai += bi : ai *= bi;
    return make_pair(ai / 10 + '0', ai % 10 + '0');
}

// consider them as REVERSED already
string addTwoString(const string &a, const string &b) {
    char carry = '0';

    int n = min(a.size(), b.size()), m = max(a.size(), b.size());
    
    string sum(m + 1, '0');
    
    for(int i = 0; i < m; i++) {
        
        char ca('0'), cb('0');
        
        if (i < n) ca = a[i], cb = b[i];
        else if (a.size() < b.size()) cb = b[i];
        else ca = a[i];

        pcc s = operateTwoChars(ca, cb); // carry , sum_value

        pcc new_sum_carry = operateTwoChars(carry, s.second);


        sum[i] = new_sum_carry.second;
        
        s = operateTwoChars(new_sum_carry.first, s.first);
        

        carry = s.second;
    }
    
    sum[m] = carry;
    return sum;
}

string multiply_okay (const string &multiplicand, const string &multiplier) {
    int n = multiplicand.size(), m = multiplier.size();
    string result(n * m + 1, '0');
    for (int i = m - 1; i >= 0; i--) { 
        string layer_res(m - i - 1, '0'); 
        char layer_carry('0');
        for (int j = n - 1; j >= 0; --j) {
            pair <char, char> mul_res = operateTwoChars(multiplier[i], multiplicand[j], false);
            pair <char, char> add_carry = operateTwoChars(layer_carry, mul_res.second);     
            layer_res.push_back(add_carry.second);
            
            pair <char, char> new_carry = operateTwoChars(mul_res.first, add_carry.first);
            layer_carry = new_carry.second;
        }
        
        layer_res.push_back(layer_carry);
        layer_res += string(n * m + 1 - layer_res.size(), '0'); 
        result = addTwoString(result, layer_res);
    }
    while(result.length() > 1 && result.back() == '0') result.pop_back();
    
    
    reverse(begin(result), end(result));
    return result;
} 
//-------------------------------------------------------

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "9018723654";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
 //------------------------------------------------

void tester(string a, string b) {

	string test_result = multiply(a, b);
	string correct_result = multiply_okay(a, b);
	

	if(test_result != correct_result) {
		cout << "____Input " << a << " * " << b 
             << "\nfailed___ [Checker: " << correct_result 
             << " ], [your_code: " << test_result << "]\n";
	}

	assert(test_result == correct_result);
}


void stress_tester() {
	std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
	std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
                             //and seed it with entropy.

    //Define the distribution, by default it goes from 0 to MAX(unsigned long long)
    //or what have you.
    std::uniform_int_distribution<unsigned long long> distr;
	
	const ll MAX = 3;
	
	while(true) {
		size_t n = distr(eng) % MAX + 1;
		size_t m = distr(eng) % MAX + 1;
		
		tester(random_string(n), random_string(m));
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

