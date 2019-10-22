/* Informatik B SoSe19
 * 9. Vorlesung 15.5.2019
 * Max Willert
 */

/// In dieser Datei befinden sich nur die Funktionssignaturen und die
/// Spezifikationen. Die Implementierung befindet sich woanders.

#pragma once // Sorgt dafür, dass diese Datei nur 1x inkludiert wird.
#include <vector>
using namespace std;

// Voraussetzungen: 0 <= left < right <= array.size()
// Ergebnis: Eine Kopie aller Elemente des Eingabearrays zwischen den
// 			 Stellen left (inklusive) und right (exklusive) ist geliefert.
// Effekte: keine
vector<int> copy(vector<int> & array, unsigned left, unsigned right);

// Voraussetzungen: array besitzt mindestens max(i,j)+1 viele Elemente
// Ergebnis: keins
// Effekt: Die Einträge von array an den Stellen i und j sind getauscht
void tausche(vector<int> & array, unsigned i, unsigned j);

// Voraussetzungen: 0 <= left <= right
// Ergebnis: Eine Zufallszahl aus dem Intervall [left,right] ist geliefert.
// Effekt: keins
int zufall(int left, int right);

// Voraussetzungen: keine
// Ergebnis: keins
// Effekt: Die Elemente des Arrays sind auf dem Bildschirm in entsprechender
//		   Reihenfolge angezeigt.
void print(vector<int> & array);

// Voraussetzungen: keine
// Ergebnis: True ist genau dann geliefert, wenn das Array monoton
//			 steigend sortiert ist.
// Effekt: keins
bool ist_sortiert(vector<int> & array);

// Voraussetzungen: size > 0
// Ergebnis: Ist richtung=true, so ist das aufsteigend sortierte Array
//			 [0,1,2,...,size-2,size-1] geliefert. Andernfalls ist das
//			 absteigend sortierte Array [size-1,size-2,...,2,1,0] geliefert.
// Effekt: keins
vector<int> sortiertes_array(unsigned size, bool richtung);

// Voraussetzungen: size > 0
// Ergebnis: Ein zufälliges Array mit size vielen Elementen ist geliefert.
// Effekt: keins
vector<int> zufalls_array(unsigned size);
