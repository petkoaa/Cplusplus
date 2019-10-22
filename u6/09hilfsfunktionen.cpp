/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

// In dieser Datei befinden sich nur die Funktionsdefinitionen der bereits
// spezifizierten Funktionen.

#include "09hilfsfunktionen.hpp" // Diese Funktionen sollen implementiert werden.
#include "09sortierfunktionen.hpp" // Diese Funktionen sollen implementiert werden.

#include <iostream>
using namespace std;

void tausche(vector<int> & array, unsigned i, unsigned j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void print(vector<int> array) {
	for (unsigned i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool ist_sortiert(vector<int> array) {
	for (unsigned i = 0; i + 1 < array.size(); i++) {
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

vector<int> sortiertes_array(unsigned size, bool richtung) {
	vector<int> array(size);
	for (unsigned i = 0; i < size; i++)
		array[i] = richtung * i + (!richtung) * (size - i - 1);
	return array;
}

vector<int> zufalls_array(unsigned size) {
	vector<int> array(size);
	for (unsigned i = 0; i < size; i++)
		array[i] = rand() % size;
	return array;
}

vector<int> copy(vector<int> array, unsigned left, unsigned right) {
    unsigned size = right-left;
    vector<int> result(size);
    for (unsigned i = 0; i < size; i++)
        result[i] = array[left + i];
    return result;
}

int zufall(int left, int right) {
	return left + rand() % (right-left+1);
}
