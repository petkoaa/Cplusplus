
/* Informatik B SoSe19
 * 18. Vorlesung 14.6.2019
 * Max Willert
 */

#pragma once

template <typename E>
class Queue {

	// Spezifikation:
	// Vor.: keine
	// Erg.: keins
	// Eff.: Entsteht eine Warteschlange von Objecte der
	//       abstakten Class <E>

	public:

		// Spezifikation
		// Vor.: keine
		// Erg.: keins
		// Eff.: Ein Object der Class Queue ist Automatisch
		//       zerstoert.
		virtual ~Queue() {};

		// Spezifikation
		// Vor.: keine
		// Erg.: True wenn queue ist leer.
        //       False wenn quueu nicht leer ist.
		// Eff.: keins
		virtual bool is_empty() const = 0;

		// Spezifikation
		// Vor.: keine
		// Erg.: Das erste Element in der Warteschlange ist geliefert
		// Eff.: Das erste Element ist von der Warteschlange
		//       entfernt.
		virtual E dequeue() = 0;

		// Spezifikation
		// Vor.: keine
		// Erg.: Der erste Element in der Warteschlange ist geliefert ?
		// Eff.: keins ?
		virtual E front() const = 0;

		// Spezifikation
		// Vor.: keins
		// Erg.: keins
		// Eff.: Ein Element E ist am Ende der Warteschlange
		//       platziert
		virtual void enqueue(E) = 0; //vieleicht enqueue ?
};
