#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int zahl = 29/2;
	
	cout << zahl << endl;
	
	cout << (5+5*7==zahl-2) << endl;
	
	zahl = 50;
	
	cout << (5+5*9==zahl) << endl;
	
	cout << "Inf B " << (40 * zahl + 19) << endl;
	
	cout << (true && (zahl <= 42)) << endl;
	
	cout << (true + 7) << endl;
	
	zahl++;
	
	if (zahl - 10 <= 30) {
		cout << "Korrekt" << endl;
	} else {
		cout << "Falsch" << endl;
	}
	
	cout << (zahl + true
	
	- 7) << endl;
	
	string temp;
	
	cin >> temp;
	
	if (temp.length() > 2) {
		temp[2] = 'x';
	}
	
	cout << temp << endl;
	
	int anzahl;
	
	cout << "Geben Sie eine Zahl ein: ";
	
	cin >> anzahl;
	
	for (int i = 0; i < anzahl; i++) {
		cout << i*2 << endl;
	}
	
	return 0;
}
