#include <iostream>
#include <unistd.h>

using std::string;
using std::cout; 
using std::endl;
using std::cin;


#define msleep(X) usleep(X * 1000)


int main() {

	string str;
	cin >> str; 

	cout << str << std::flush;

	msleep(3000);

	cout << string(str.length(),'\b');

	cout << "Hello again!";

	msleep(3000);

	cout << '\r';

	cin >> str;
	cout << str << endl;


	return 0;
}