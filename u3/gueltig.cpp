#include <iostream>
using namespace std;

int a = 3;
int b = 42;

int f(int a) {
    cout << b << endl;
    cout << a << endl;
    return a*a;
}

int main() {
    int a = 7;  // 1)a=7
    int b = f(f(::a)-6); //1)b=9
    int i;
    for (int i = 0; i<b/2; i++) {
        int b = a-1;
        {b = f(i);
        ::b = 0;//global b=0
        ::a++; //global a=4
        a = a*::a*::a*::a*::a*::a; //local a = 7168
        int a = b;}
        cout << a << endl;
        cout << b << endl;
		cout << (&i+1) << endl;
    }
	cout << (&i) << endl;
	cout << i*::a << endl;

}

