/* Informatik B SoSe19
 * 18. Vorlesung 14.6.2019
 * Max Willert
 */
 
// Kompilieren: g++ -Wall -Wextra -Werror -pedantic -std=c++14 -o stacks stack_test.cpp

#include <iostream>
using namespace std;

// Hier ist unser ADT beschrieben.
#include "stack.hpp"

// Diese Implementierung soll benutzt werden:
#include "staticarraystack.cpp"

//#include "dynamicstaticarraystack.cpp"

int main() {
	StaticArrayStack<int> s = StaticArrayStack<int>();
	// DynamicArrayStack<int> s = DynamicArrayStack<int>();
	s.push(3);
	s.push(5);
	s.push(2);
	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.is_empty() << endl;
	StaticArrayStack<int> t = s; // Copy-Konstruktor oder Zuweisungsoperator?
	// DynamicArrayStack<int> t = s;
	cout << s.is_empty() << endl;
	cout << t.pop() << endl;
	cout << t.is_empty() << endl;
	cout << s.is_empty() << endl;
	
}
