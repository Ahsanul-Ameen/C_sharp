#include <bits/stdc++.h>
using namespace std;
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

string multiply (const string &multiplicand, const string &multiplier) {
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

int main() {
   	int T(1); 
   	cin >> T;
   	for(int t = 1; t <= T; t++) {
   		int n;
		cin >> n;
		string result("1");
		for(int i = 1; i <= n; ++i) result = multiply(result, to_string(i));
		cout << result << endl;
   	}
    return 0;
}
