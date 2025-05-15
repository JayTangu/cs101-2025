#include <iostream>
#include <string>
using namespace std;

struct Student {
	int id;
	string name;
};

int main() {
	Student* p1 = new Student[5];
	for(int i = 0 ; i < 5 ; i++) {
		p1[i].id = 1+i;
		p1[i].name="IU"+to_string(i+1);
	}
	for(int i = 0 ; i < 5 ; i++) {
		cout<<"array("<<i<<") "<<p1[i].id<<", "<<p1[i].name<<endl;
	}
	delete[] p1;
} 
