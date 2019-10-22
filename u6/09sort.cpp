/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic -o sort 09hilfsfunktionen.cpp 09sort.cpp

#include "09hilfsfunktionen.hpp"
#include <iostream>
#include <vector>
using namespace std;

/// Mergesort ----------------------------------------------------------
/// Mergesort hat immer die Laufzeit nlogn.
/// Mergesort ist stabil.
/// Mergesort ist out-of-place.

// Folgende Funktion wird für Mergesort benötigt, ihre Implementierung
// befindet sich in der Datei 09hilfsfunktionen.cpp.
// Voraussetzungen: 0 <= left < right <= array.size()
// Ergebnis: Eine Kopie aller Elemente des Eingabearrays zwischen den
// 			 Stellen left (inklusive) und right (exklusive) ist geliefert.
// Effekte: keine
// vector<int> copy(vector<int> array, unsigned left, unsigned right);

void merge_sort(vector<int> & array) { // Call-by-Reference
	unsigned size = array.size();
	if (size <= 1) return;
	
	// Unterteilen des Arrays in linke und rechte Hälfte
	unsigned middle = size / 2;
	vector<int> links = copy(array, 0, middle);
	vector<int> rechts = copy(array, middle, size);
	
	// Sortiere linke Hälfte und rechte Hälfte separat voneinander.
	merge_sort(links);
	merge_sort(rechts);
	
	// Merge die beiden Hälften mittels Reißverschlussprinzip
	unsigned l = 0;
	unsigned r = 0;
	while (l+r < size) {
		if (r == rechts.size()) {
			array[l+r] = links[l];
			l++;
		} else if (l == links.size()) {
			array[l+r] = rechts[r];
			r++;
		} else if (links[l] <= rechts[r]) {
			array[l+r] = links[l];
			l++;
		} else {
			array[l+r] = rechts[r];
			r++;
		}
	}
}

/// Quicksort ----------------------------------------------------------
/// Quicksort hat im besten Fall die Laufzeit nlogn.
/// Quicksort hat im durchschnittlichen Fall die Laufzeit nlogn.
/// Quicksort hat im worst case die Laufzeit n^2.
/// Quicksort ist nicht stabil.
/// Quicksort ist in-place.

// Hilfsfunktion für Quicksort:
// Voraussetzungen: array besitzt mindestens right+1 viele Elemente, left>=0
// Ergebnis: keins
// Effekt: Die Einträge von array zwischen den Positionen left und right
//		   (inklusive dieser beiden) ist aufsteigend sortiert.
void q_sort(vector<int> & array, int left, int right) { // Call-by-Reference
	
	if (left >= right) return;
	
	// Pivotelement wählen
	int pivot = array[right];
	
	// Unterteilen der Liste
	int l = left;
	
	for (int i = left; i <= right; i++) {
		if (array[i] <= pivot) {
			tausche(array, l, i);
			l++;
		}
	}
	
	// rekursive Aufrufe
	q_sort(array, left, l-2);
	q_sort(array, l ,right);
}

// Die eigentliche Quicksort-Funktion:
// Voraussetzungen: keine
// Ergebnis: keins
// Effekt: Die Einträge von array sind monoton steigend sortiert.
void quick_sort(vector<int> & array) { // Call-by-Reference
	q_sort(array, 0, array.size()-1);
}

/// Randomisiertes Quicksort -------------------------------------------
/// Randomisiertes Quicksort hat die erwartete Laufzeit nlogn.
/// Randomisiertes Quicksort ist nicht stabil.
/// Randomisiertes Quicksort ist in-place.

// Hilfsfunktion für Randomisiertes Quicksort:
// Voraussetzungen: array besitzt mindestens right+1 viele Elemente, left>=0
// Ergebnis: keins
// Effekt: Die Einträge von array zwischen den Positionen left und right
//		   (inklusive dieser beiden) ist aufsteigend sortiert.
void rq_sort(vector<int> & array, int left, int right) { // Call-by-Reference
	
	if (left >= right) return;
	
	// Pivotelement randomisiert wählen
	tausche(array, right, zufall(left, right));
	int pivot = array[right];

	int l = left;
	for (int i = left; i <= right; i++) {
		if (array[i] <= pivot) {
			tausche(array, l, i);
			l++;
		}
	}
	rq_sort(array, left, l-2);
	rq_sort(array, l ,right);
}

// Die eigentliche RQuicksort-Funktion:
// Voraussetzungen: keine
// Ergebnis: keins
// Effekt: Die Einträge von array sind monoton steigend sortiert.
void random_quick_sort(vector<int> & array) { // Call-by-Reference
	rq_sort(array, 0, array.size()-1);
}

/// Main ---------------------------------------------------------------

int main() {
	
	srand(time(NULL)); // Zufallsgenerator starten ... technische Notwendigkeit
	
	// Zufallsarray erzeugen, dann sortieren, dann anzeigen lassen
	vector<int> array = zufalls_array(20);
	merge_sort(array);
	print(array);
	
	array = zufalls_array(20);
	quick_sort(array);
	print(array);
	
	array = zufalls_array(20);
	random_quick_sort(array);
	print(array);
	
}
