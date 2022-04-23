#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack <char>* s = new Stack <char>();
	string str1 = "({x-y-z}*[x+2y]-(z+4x));";
	cout << "\n\t#1 " << str1 << endl;
	if (s->ChekLine(str1)) {
		cout << "\n\tCorrect line!" << endl;
	}
	else {
		cout << "\n\tIncorrect line!" << endl;
	}
	string str2 = "([x-y-z}*[x+2y)-{z+4x)];";
	cout << "\n\t#2 " << str2 << endl;
	if (s->ChekLine(str2)) {
		cout << "\n\tCorrect line!" << endl;
	}
	else {
		cout << "\n\tIncorrect line!" << endl;
	}
	return 0;
}

