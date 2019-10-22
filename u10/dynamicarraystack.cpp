/* Informatik B SoSe19
 * Musterlösung Übung 10
 * Max Willert
 */

#include "stack.hpp"
#include <iostream>
using namespace std;

template <typename E>
class DynamicArrayStack : public Stack<E> {

	// Diese Implementierung des ADT Stack verwendet Arrays, die ihre Größe
	// ändern können (Arrays mit dynamischer Größe).

	private:

		E* array;
		//capacity ist die Größe des alloziierten Arrays
		int capacity;
		// anzahl ist die Anzahl der Elemente auf dem Stack
		int anzahl;
		/* Folgende Aussage soll immer erfüllt sein:
		 *
		 * capacity/4 <= anzahl <= capacity
		 *
		 * Immer wenn ein neues Element entfernt oder gelöscht wird, wird
		 * resize aufgerufen (siehe unten) und prüft, ob die obige Aussage
		 * verletzt ist. Falls ja, wird ein neues Array erzeugt und die
		 * Elemente aus dem alten in das neue Array übertragen. Das alte
		 * Array wird anschließend gelöscht. */


		//Spezifikation
        //Vor.: Der Stack ist Instanze der Class DynamicStackArray
        //Erg.: keins
        //Eff.: Sowohl die Adresse des Stacks im Speicher, als auch
        //      das fuers Stack reservierte Speicherplatz,
        //      werden fuer den Bedarf des Programs angepasst.
		void resize() {
			if ((capacity/4 > anzahl ) || (anzahl> capacity)){

                capacity = anzahl+5 ;   //dammit muessen wir nicht jedes
                                         //mal waechseln
                E* new_arr = new E [capacity]; //neues array mit genug
                                              //Speicherplatz erzeugen
                for (unsigned i=0; i<=anzahl-1; i++){
                    new_arr[i] = array[i];  //alte array wird jetze
                }                           //in die neue uberschrieben
                delete[] array;  //alte array loeschen
                array = new_arr; //neue array ist jetzt array
                anzahl = capacity-5 ;  //anzahl neu setzen

                cout<<"Stack resized. "<<endl; //sagt bescheid

            }

		}

	public:
		// Konstruktor
		// Vor.: keine
		// Eff.: Ein leerer Stack ist erzeugt.
		// Erg.: keins
		DynamicArrayStack() {
			anzahl = 0;
			capacity = 1;
			array = new E[capacity];
		}
		// Copy-Konstruktor
		// Vor.: keine
		// Eff.: Ein Stapel ist erzeugt, welcher genau dieselben
		//       Elemente wie der Eingabeparameter s besitzt.
		// Erg.: keins
		DynamicArrayStack(const DynamicArrayStack<E> & s) {
			capacity = s.capacity;
			array = new E[capacity];
			anzahl = 1;
			for (int i = s.anzahl-1; i >= 0; i--) {
				push(s.array[i]);
			}
		}
		// Zuweisungsoperator
		// Vor.: keine
		// Eff.: Der Stapel besitzt nun denselben Inhalt wie der
		//       Eingabeparameter s.
		// Erg.: Eine Referenz auf den Stapel ist geliefert.
		DynamicArrayStack<E>& operator=(const DynamicArrayStack<E> & s) {

			// Fall abfangen: was passiert wenn ein Objekt sich selbst zuweist.
			if (this != &s) {

				// 1. Alten Speicher freigeben
				anzahl = 0;
				delete[] array;

				// 2. Neuen Speicher erzeugen
				capacity = s.capacity;
				array = new E[capacity];

				// 3. Alle Elemente herüberkopieren.
				for (int i = s.anzahl-1; i >= 0; i--) {
					push(s.array[i]);

				}
			}
			return *this;
		}
		// Destruktor
		// Vor.: keine
		// Eff.: Der Speicher des Objekts ist freigegeben.
		// Erg.: keins
		~DynamicArrayStack() {
			delete[] array;
		}

		bool is_empty() const {
			return this->anzahl == 0;
		}

		E top() const {
			return array[anzahl-1];
		}

		E pop() {
			E elem = array[anzahl-1];
			anzahl--;
			resize(); // Array zu groß? ... Erneuern!
			return elem;
		}

		void push(E x) {
			resize(); // Array zu klein? ... Erneuern!
			array[anzahl] = x;
			anzahl++;
		}

};

/*int main (){

    typedef DynamicArrayStack <int> somestack;
    somestack stack1;
    int i = 10;
    stack1.push(i);
    stack1.push(i);
    stack1.push(i);

}
*/



