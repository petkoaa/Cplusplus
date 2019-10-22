// Namen:
// Tutorium:
// Informatik B, Übung 6, Aufgabe 3

// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic -o megasort 09hilfsfunktionen.cpp megasort.cpp

// mein algorithmus my_rand_quick_sort hat sehr schlechte laufzeit

#include "09hilfsfunktionen.hpp"
#include "09sortierfunktionen.hpp" // Diese Funktionen sollen implementiert werden.
#include "09hilfsfunktionen.cpp"


#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
void my_rand_quick_sort(vector<int>&array, unsigned k);
void my_rand_q_sort(vector<int> &vec, int L, int R, unsigned k);
int pivot (vector <int>array);//random partition
void rq_sort(vector<int> & array, int left, int right) ;
void random_quick_sort(vector<int> & array) ;
void swap(vector<int>& v, int x, int y) ;



/// Sortierverfahren ----------------------------------------------------

// Voraussetzungen: k >= 20
// Ergebnis: keins
// Effekt: Die Elemente von array sind monoton steigend sortiert.
void mega_sort(vector<int> & array, unsigned k) {

	if (k<=array.size())
    {
        my_rand_quick_sort(array,k );
    }else{
        insertion_sort(array);}
}




/// Main ----------------------------------------------------------------
// Auch die Main muss noch angepasst werden.
// Denken Sie nicht nur an das Zeitmessen sondern auch daran, zu überprüfen
// ob ihr Algorithmus wirklich das tut, was er tun soll - sortieren!

int main() {
	srand(time(NULL)); // Zufallsgenerator starten. Technische Notwendigkeit.
	double time;
	vector<int> array;
	for (int size = 10000; size <= 1000000; size *= 10) {
		cout << "   " << size << " Elemente:" << endl;
    int k = 25;
		// Zufälliges Array testen:
		array = zufalls_array(size);

		time = clock(); // Startzeit
		mega_sort(array,k);
		time = clock() - time; // Endzeit

		cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;

		// Aufsteigend sortiertes Array testen:
		array = sortiertes_array(size, true);

		time = clock(); // Startzeit
		mega_sort(array,k);
		time = clock() - time; // Endzeit

		cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;

		// Absteigend sortiertes Array testen:
		array = sortiertes_array(size, false);

		time = clock(); // Startzeit
		mega_sort(array,k);
		time = clock() - time; // Endzeit

		cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;

		cout<<"random qsort ///////////////"<<endl;

		//////////////////////////RANDOMISIERTEN QSORT///////////////
		// Zufälliges Array testen:
		array = zufalls_array(size);

		time = clock(); // Startzeit
        random_quick_sort(array);
        time = clock() - time; // Endzeit

		cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;

		// Aufsteigend sortiertes Array testen:
		array = sortiertes_array(size, true);

		time = clock(); // Startzeit
		random_quick_sort(array);
		time = clock() - time; // Endzeit

		cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;


		// Absteigend sortiertes Array testen:
		array = sortiertes_array(size, false);

		time = clock(); // Startzeit
		random_quick_sort(array);
		time = clock() - time; // Endzeit

		cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << endl;



	}
	return 0;
}



/// my random Quicksort------------------------------------------------------
void my_rand_q_sort(vector<int> &vec, int L, int R, unsigned k) {
    if (k>=vec.size()){
    int i, j, piv;
    i = L;
    j = R;
    piv = pivot(vec);

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j);
            i++;
            j--;
        }
        else {
            if (i < R)
                my_rand_q_sort(vec, i, R, k);
            if (j > L)
                my_rand_q_sort(vec, L, j, k);
            return;
        }
    }
}else{
    int n = vec.size();
        insertion_sort(vec);}
}


void swap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

void my_rand_quick_sort(vector<int> & array, unsigned k) {
	my_rand_q_sort(array, 0, array.size() - 1,k);
}

int pivot (vector <int>array) //random partition
{
    int len= array.size()-1;
    int a =  rand() % len;
    int b = rand() % len;
    int c = rand() % len;
    if ((a>=b && b>=c)||(c>=b && b>=a)) return b;
    else if ((b>=a && a>=c)||(c>=a && a>=b)) return a;
    else if ((a>=c && c>=b)||(b>=c && c>=a)) return c;

}


/// Insertsort
void insertion_sort(vector<int> & array) {
	for (unsigned i = 0; i < array.size(); i++) {
		for (unsigned j = i; j > 0 && array[j] < array[j - 1]; j--)
			tausche(array, j, j - 1);
	}
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

