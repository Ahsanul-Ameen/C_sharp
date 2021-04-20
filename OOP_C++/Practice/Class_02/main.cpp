#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;



struct Contact {
	string first_name;
	string last_name;

	string contact_no;
	string email;

	int age;

	friend istream& operator>>(istream& in, Contact& contact) {
		in >> contact.first_name >> contact.last_name >> contact.contact_no >> contact.email >> contact.age;
		return in;
	}

	friend ostream& operator<<(ostream& out, Contact& contact) {
		out << contact.first_name << " " <<  contact.last_name << " " <<  contact.contact_no << " " <<  contact.email << " " << contact.age;
		return out;
	}
};


int main() {

	const int CONTACT_SIZE = 10;

	Contact conts[CONTACT_SIZE];

	// int n;
	// cin >> n;

	// string str;
	// cin >> str;

	// Contact var;
	// cin >> var;


	for(int i = 0; i < 10; i++) {

		cin >> conts[i];

	
	}


	for(int i = 0; i < 10; i++) {

		

		conts[i].age += i;
		// conts[i].first_name = "Mr."
		// conts[i].last_name = "Bean" + i;

		// conts[i].contact_no = "3123" + i;
		// conts[i].email = "bean@hotmail.com";
		// conts[i].age = 66;

		cout << conts[i] << endl;
	}

}