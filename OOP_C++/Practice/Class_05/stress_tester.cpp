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
 



string pushback (int A)
 {
     string str1;
     string str = "\0";
     string str2 = ",";
     //cin >> str1;
     str1 = to_string(A); 

     int counter = 1;
    if (str1.length() == 7)
    {   for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 5)
            {
                str.push_back(str2[0]);
            }
        }
    }
    else if (str1.length() == 9)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 5)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 8)
            {
                str.push_back(str2[0]);
            }
        }
    }
    else if (str1.length()  == 8)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 3)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 6)
            {
                str.push_back(str2[0]);
            }
        }
    }      

    else if (str1.length() == 4)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
        }
    }      
     else if (str1.length() == 5)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 3)
            {
                str.push_back(str2[0]);
            }
        }
    } 
    else if (str1.length() == 3)
    {
      for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
        }

    } 
    else if (str1.length() < 3)
    {
        cout << str1;
    }    
    else if (str1.length() == 6)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 4)
            {
                str.push_back(str2[0]);
            }
        }
    }
    //cout << str;

    return str;
 }






string solver(int A) {
	/// put your codes here
	//-----------------------------------------------------------------
	
	
	
	return pushback(A);
	
	
	
	
	/// return your answer
	//return res;
}


void tester(int A) {
	string str, res;
	str = to_string(A);
	
	reverse(all(str));  // reverse the number
	
	for(unsigned i = 0; i < str.size(); i++) {
		if(i && i % 3 == 0)
			res.push_back(',');
			
		res.push_back(str[i]);
	}
	reverse(all(res)); // reverse the seperated number
	
	//cout << res << endl;
	
	string sol = solver(A);
	if(res != sol) {
		cout << "____Input " << A << " failed___ [Checker: " << res << " ], [your_code: " << sol << "]\n";
	}
	assert(res == sol);
	//cout << sol << endl;
}


void stress_tester() {
	srand(time(nullptr));
	const int MAX_VAL = 200000000;
	while(true) {
		int A = rand() % MAX_VAL;
		tester(A);
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

