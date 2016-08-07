#include "intstack.h"
using namespace std;

int main() {
	intstack mystack(8);  // creates a stack that can hold 8 ints
	
	//intstack *pstack;
	//pstack = &mystack;

	int i = 8;
	while (mystack.top() < mystack.size()) { // pushing as much as we can
		mystack.push(i);
		i++;
	}
	cout << "After the while loop" << "\n";
	mystack.print(); // print its content to cout

	mystack.push(i); // trying extra push beyond the size (for testing)

	int a;
	a = mystack.pop(); // start poping
	a = mystack.pop();
	mystack.print(); // print its content to cout

	for (int j = 1; j < 8; j++) {
		a = mystack.pop();
		cout << "pop# " << j << " gave me: " << a << "\n";
	}
	mystack.print(); // print its content to cout

	mystack.push(30);   // two more pushes
	mystack.push(31);
	mystack.print(); // print its content to cout

	a = mystack.looktop(); // look at the element at the top
	cout << "looktop gave me: " << a << "\n";

	mystack.print(); // print its content to cout

	return 0;
}