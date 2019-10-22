/* Informatik B SoSe19
 * Musterlösung Übung 10
 * Max Willert
 */

#include "stack.hpp"

template <typename E>
class StaticArrayStack : public Stack<E> {

	// Diese Implementierung des ADT Stack verwendet Arrays, die ihre Größe
	// nicht ändern können (Arrays mit statischer Größe).

	private:

		E* array;
		int anzahl;
		int capacity;

	public:
		// Konstruktor
		// Vor.: keine
		// Eff.: Ein leerer Stack ist erzeugt.
		// Erg.: keins
		StaticArrayStack() {
			anzahl = 0;
			capacity = 1000;
			array = new E[capacity];
		}
		// Copy-Konstruktor
		// Vor.: keine
		// Eff.: Ein Stapel ist erzeugt, welcher genau dieselben
		//       Elemente wie der Eingabeparameter s besitzt.
		// Erg.: keins
		StaticArrayStack(const StaticArrayStack<E> & s) {
			capacity = s.capacity;
			array = new E[capacity];
			anzahl = 0;
			for (int i = s.anzahl-1; i >= 0; i--) {
				push(s.array[i]);
			}
		}
		// Zuweisungsoperator
		// Vor.: keine
		// Eff.: Der Stapel besitzt nun denselben Inhalt wie der
		//       Eingabeparameter s.
		// Erg.: Eine Referenz auf den Stapel ist geliefert.
		StaticArrayStack<E>& operator=(const StaticArrayStack<E> & s) {

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
		~StaticArrayStack() {
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
			return elem;
		}

		void push(E x) {
			array[anzahl] = x;
			anzahl++;
		}
};


