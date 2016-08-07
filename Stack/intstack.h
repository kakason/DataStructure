#include <iostream>
#ifndef intstack_h  // this is closed by the #endif at the end

#define intstack_h // this is the class definition for intstack
                   
class intstack {
private:
	int thetop; // top of the stack
	int *a; // array of elements (the stack)
	int max; // maximum number of elements 

public:
	intstack::intstack() {}

	intstack::intstack(int size) {
		max = size;
		thetop = -1;
		a = new int[max];
	}

	void intstack::push(int item) {
		if (thetop + 1 < max) {
			a[thetop + 1] = item;
			thetop++;
		}
		else
			std::cout << "The stack is full, can not push anything\n";
	}

	int intstack::pop() {
		if (thetop >= 0)
			return a[thetop--];
		else {
			std::cout << "The stack is empty, can not pop anything\n";
			return -1; // the stack is empty
		}
	}

	int intstack::size() {
		return max;
	}

	int intstack::top() {
		return thetop + 1;
	}

	int intstack::looktop() {
		return a[thetop];
	}

	void intstack::print() {
		if (thetop < 0)
			std::cout << "The stack is empty, can not print anything\n";
		else {
			std::cout << "The stack contains: ";
			for (int i = 0; i <= thetop; i++) {
				std::cout << a[i] << " ";
			}
			std::cout << "\n";
		}
	}
};

#endif