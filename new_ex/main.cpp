#include <iostream>
#include <string>
using namespace std;

struct Student {
	int id;
	string name;
};

int main() {
	Student* p1 = new Student[5];
	p1[0].id=1;
	p1[1].id=2;
	p1[2].id=3;
	p1[3].id=4;
	p1[4].id=5;
	p1[0].name="IU1";
	p1[1].name="IU2";
	p1[2].name="IU3";
	p1[3].name="IU4";
	p1[4].name="IU5";
	for(int i = 0 ; i < 5 ; i++) {
		cout<<"array("<<i<<") "<<p1[i].id<<", "<<p1[i].name<<endl;
	}
	delete[] p1;
} 
