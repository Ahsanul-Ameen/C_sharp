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
 

//util print function
void print(const int& i, const int& j) {
    printf("i = %d, j = %d\n", i, j);
}


int main(int argc, char** argv) {
    fast_io
    
    
    // //file_io // what does this do ? 
    // int n;
    // scanf("%d", &n);
    

    int i = 0, j = 0;
	// this is goto statement, rarely used, frequent in assembly
	printf("loop 1\n");
    Loop1: 
        print(i, j);
        ++i, j--;
        if(i < 18) goto Loop1;
        
    printf("\n");
    
    //loop 2
    printf("loop 2\n");
    for(; ; ) { // for(optional expression_1; optexpr_2; optexpr_3) {}
		--i, ++j;
		if(i == 0) break;
	}
	print(i, j);
    printf("\n");
	
	//loop 3
	printf("loop 3\n");
	for(int i = 10, j = 20; i < j; ++i, --j) {
		print(i, j);
	}
	print(i, j);
    printf("\n");
	
	//loop 4
	printf("loop 4\n");
	i = 5, j = 3;
	while(i--) {
		print(i, ++j);
	}
	print(i, j);
    printf("\n");
	

	// loop 5
	printf("loop 5\n");
	while(--j) {
		print(++i, j);
	}
	print(i, j);
    printf("\n");
    
    //loop 6
    printf("loop 6\n");
    do {
		print(i, j);
	} while(!(i-- < ++j)); // semicolon!!!
	print(i, j);
	puts("");
	
	//loop 7
	printf("loop 7\n");
	// do you know about octal number system?
	i = 011, j = -043; // i = 9, j = -35

	print(i, j);
	while(j++);

	print(i, j);
	puts("");
    
    //loop 8
    printf("loop 8\n");
    while(i) { // undefined behaviour // be careful
		printf("i : %d, (--i): %d\n", i, (--i));
		//cout <<"inside loop 8: " << i << ", " << --i << endl; 
	}
	print(i, j); // 
	puts("");
	
	//loop 9
	//evaluate binary -> decimal
	char *str = "1011001"; // 89 // asteric -> pointer of an array
	int decNum = 0;
	for(; *str != '\0'; ++str) { 
		char bit = *str;
		int bit_val = (bit == '1'); // 1 or 0
		decNum = (decNum << 1) + bit_val; // 0 / 1
	}
	printf("Decimal val : %d \n\n", decNum);

    return 0;
}
