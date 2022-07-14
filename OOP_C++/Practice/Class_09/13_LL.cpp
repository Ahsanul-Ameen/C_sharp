#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define     endl               "\n"
#define     unsync_io          ios::sync_with_stdio(false);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(const auto& i: t) os<<i<<" "; return os; }

// faced this type of problem in an interview 
// code was incomplete
// task was to identify bugs / missing snippets
// namely detect absence of destructor
// and existance of dangling pointer

class Node {
public:
	int data;
	Node* next;
	
	Node (int _data, Node* _next) 
		: data(_data), next(_next)
	{}
	
	Node (int _data) {
		this->data = _data;
		this->next = nullptr;
	}
	
	~Node() {
		if (this->next) {
			delete this->next;
		}
		this->next = nullptr;
	}
};


int main(int argc, char *argv[]) {

	Node* head = new Node(5);
	head = new Node(4, head);
	head = new Node(3, head);
	head = new Node(2, head);
	head = new Node(1, head);
	
	Node* A = head;
	while (A) {
		cout << A->data <<  endl;
		A = A->next;
	}
	if (A == nullptr) {
		cout << "A is null" << endl;
	}
	delete head;
	head = nullptr;
	
	cout << "head deleted" << endl;
	
	A = head;
	
	if (A == nullptr) {
		cout << "A is again null" << endl;
	}
	while (A) {
		cout << " - " << A->data <<  endl;
		A = A->next;
	}
	
	A = head = nullptr;
	
	
	return 0;
}


