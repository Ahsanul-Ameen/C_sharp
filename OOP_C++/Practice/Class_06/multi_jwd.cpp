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

string multiply(string num, string num2)
{
    string multiplicand = "";
    string multiplier = "";
    int m;
    int n;
    m = max(num.size(), num2.size());
    n = min(num.size(), num2.size());
    if (num.size() == n)
    {
        multiplier = num;
        multiplicand = num2;
    }
    else if (num2.size() == n)
    {
        multiplier = num2;
        multiplicand = num;
    }
    else 
    {
        multiplicand = num;
        multiplier = num2;
    }
    string res = "0";
    string temp = "";
    int multi;
    int counter = 0;
    char carry = '0';
    char sum;
    for (int i = n-1; i >= 0; i--)
    {
        string zero(counter, '0');
        temp = "";
        temp += zero;
        carry = '0';

        for (int j = m-1; j >= 0; j--)
        {
            multi = ((multiplicand[j]-'0') * (multiplier[i]-'0')) + (carry-'0');
            sum = multi%10 + '0';
            carry = multi/10 + '0';
            temp.push_back(sum);
        } 
        if(carry != '0')
        {
            temp.push_back(carry);
        }
        reverse(temp.begin(), temp.end());
        counter++;
        res = addition(res, temp);
        
    }

    return res;
}

int main ()
{ 
    // string a;
    // string b;
    // cin >> a >> b;
    // string c = multiply(a, b);
    // cout << c << endl;

    int n;
    cin >> n;
    string fact("1");
    while(n) {
        fact = multiply(fact, to_string(n--));
    }
    cout << fact << endl;
    return 0;
} 
