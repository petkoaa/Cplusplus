/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

// In dieser Datei befinden sich nur die Funktionsdefinitionen der Sortieralgorithmen.

#include "09sortierfunktionen.hpp" // Diese Funktionen sollen implementiert werden.
#include "09hilfsfunktionen.hpp"
#include <vector>
using namespace std;

/// Insertsort
void insertion_sort(vector<int> & array) {
	for (unsigned i = 0; i < array.size(); i++) {
		for (unsigned j = i; j > 0 && array[j] < array[j - 1]; j--)
			tausche(array, j, j - 1);
	}
}

/// Mergesort
void merge_sort(vector<int> & array) {
    unsigned size = array.size();
    if (size <= 1) return;
    unsigned middle = size / 2;
    vector<int> leftArray = copy(array, 0, middle);
    vector<int> rightArray = copy(array, middle, size);
    merge_sort(leftArray);
    merge_sort(rightArray);
    unsigned l = 0;
    unsigned r = 0;
    while (l + r < size) {
        if (r == rightArray.size()) {
            array[l+r] = leftArray[l];
            l++;
        } else if (l == leftArray.size()) {
            array[l+r] = rightArray[r];
            r++;
        } else if (leftArray[l] <= rightArray[r]) {
            array[l+r] = leftArray[l];
            l++;
        } else {
            array[l+r] = rightArray[r];
            r++;
        }
    }
}

/// Quicksort
void q_sort(vector<int> & array, int left, int right) {
	if (left >= right) return;
    int pivot = array[right];
	int l = left;
    for (int i = left; i <= right; i++) {
		if (array[i] <= pivot) {
			tausche(array, l, i);
			l++;
        }
    }
    q_sort(array, left, l-2);
    q_sort(array, l, right);
}
void quick_sort(vector<int> & array) {
	q_sort(array, 0, array.size() - 1);
}

/// Randomisiertes Quicksort
void rq_sort(vector<int> & array, int left, int right) {
	if (left >= right) return;
    tausche(array, zufall(left, right), right);
    int pivot = array[right];
    
	int l = left;
    for (int i = left; i <= right; i++) {
		if (array[i] <= pivot) {
			tausche(array, l, i);
			l++;
        }
    }
    rq_sort(array, left, l-2);
    rq_sort(array, l, right);
}
void random_quick_sort(vector<int> & array) {
	rq_sort(array, 0, array.size() - 1);
}

/// Heapsort
unsigned parent(unsigned i) {return (i - 1) / 2;} // Elternknoten
unsigned lchild(unsigned i) {return 2 * i + 1;} // Linkes Kind
unsigned rchild(unsigned i) {return 2 * i + 2;} // Rechtes Kind
void hochblubbern(vector<int> & heap, unsigned i) {
	if (i > 0 && heap[i] > heap[parent(i)]){
		tausche(heap, i, parent(i));
		hochblubbern(heap, parent(i));
	}
}
void versickern(vector<int> & heap, unsigned i, unsigned size) {
	if ((lchild(i) >= size || heap[lchild(i)] <= heap[i]) &&
	    (rchild(i) >= size || heap[rchild(i)] <= heap[i])) return;
	unsigned next_i = lchild(i);
	if (rchild(i) < size && heap[rchild(i)] > heap[lchild(i)])
		next_i = rchild(i);
	tausche(heap, i, next_i);
	versickern(heap, next_i, size);
}
void heap_sort(vector<int> & array) {
	unsigned n = array.size();
	for (unsigned i = 0; i < n; i++)
		hochblubbern(array, i);
	for (int i = n - 1; i >= 0; i--) {
		tausche(array, 0, i);
		versickern(array, 0, i);
	}
}