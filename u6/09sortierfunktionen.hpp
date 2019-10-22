/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

// In dieser Datei befinden sich nur die Funktionssignaturen und die
// Spezifikationen der Sortieralgorithmen.

#pragma once // Sorgt dafür, dass diese Datei nur 1x inkludiert wird.
#include <vector>
using namespace std;

// Voraussetzungen: keine
// Ergebnis: keins
// Effekt: Das Eingabearray ist monoton steigend sortiert.
void insertion_sort(vector<int> & array);
void merge_sort(vector<int> & array);
void quick_sort(vector<int> & array,unsigned k);
void random_quick_sort(vector<int> & array);
void heap_sort(vector<int> & array);
