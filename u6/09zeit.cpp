/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

/// Bemerkung: Es ist nicht notwendig diese Datei zu verstehen.
/// Wer daran Interesse hat, kann sich diese Datei natürlich genauer
/// anschauen.

// Kompilieren:
// g++ -std=c++14 -Wall -Wextra -Werror -pedantic -o zeitmessen 09sortierfunktionen.cpp 09hilfsfunktionen.cpp 09zeit.cpp

/* Mögliche Aufrufe:
 * ./zeitmessen insertsort
 * ./zeitmessen mergesort
 * ./zeitmessen quicksort
 * ./zeitmessen rquicksort
 * ./zeitmessen heapsort
 */

#include <iostream>
#include <vector>
#include <stdlib.h>                    
#include <time.h>
#include "09hilfsfunktionen.hpp"
#include "09sortierfunktionen.hpp"
using namespace std;

/// Main ---------------------------------------------------------------

int main(int argn, char *argv[]) {
	if (argn != 2) {
		return -1;
	}
	if (*argv[1] != 'i' && *argv[1] != 'q' && *argv[1] != 'm'&& *argv[1] != 'r'&& *argv[1] != 'h') return -1;
	srand(time(NULL));
	double time;
	vector<int> array;
	for (int size = 10000; size <= 10000000; size *=10) {
		cout << "   " << size << " Elemente:" << endl;
		
		array = zufalls_array(size);
		time = clock();
		if (*argv[1] == 'm') merge_sort(array);
		if (*argv[1] == 'i') insertion_sort(array);
		if (*argv[1] == 'q') quick_sort(array);
		if (*argv[1] == 'r') random_quick_sort(array);
		if (*argv[1] == 'h') heap_sort(array);
		time = clock() - time;
		cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden (";
		cout << ist_sortiert(array) << ")" << endl;
		
		array = sortiertes_array(size, true);
		time = clock();
		if (*argv[1] == 'm') merge_sort(array);
		if (*argv[1] == 'i') insertion_sort(array);
		if (*argv[1] == 'q') quick_sort(array);
		if (*argv[1] == 'r') random_quick_sort(array);
		if (*argv[1] == 'h') heap_sort(array);
		time = clock() - time;
		cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden (";
		cout << ist_sortiert(array) << ")" << endl;
		
		array = sortiertes_array(size, false);
		time = clock();
		if (*argv[1] == 'm') merge_sort(array);
		if (*argv[1] == 'i') insertion_sort(array);
		if (*argv[1] == 'q') quick_sort(array);
		if (*argv[1] == 'r') random_quick_sort(array);
		if (*argv[1] == 'h') heap_sort(array);
		time = clock() - time;
		cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden (";
		cout << ist_sortiert(array) << ")" << endl;
	}
	return 0;
}
