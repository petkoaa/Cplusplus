//Info B//uebungsblatt 11//Petko Antonov//Yuwei Nan//
//Aufgabe 1

#pragma once

template <typename E >
class PrioQueue {

    //Eine Prioritaetswarteschlange liefert immer der Element
    //mit dem hoechste Prioritaetswert.

public:
    // Spezifikation
		// Vor.: keine
		// Erg.: keins
		// Eff.: Ein Object der Class PrioQueue ist Automatisch
		//       zerstoert.
		virtual ~PrioQueue() {};

		// Spezifikation
		// Vor.: keine
		// Erg.: True wenn queue ist leer.
        //       False wenn quueu nicht leer ist.
		// Eff.: keins
		virtual bool is_empty() const = 0;

		// Spezifikation
		// Vor.: keine
		// Erg.: Das Element mit der hoechsten Prioritaet in der
		//       Warteschlange ist geliefert
		// Eff.: Das erste Element ist von der Warteschlange
		//       entfernt.
		virtual E dequeue() = 0;

		// Spezifikation
		// Vor.: keine
		// Erg.: Das Element mit der hoechsten Prioritaet in der
		//       Warteschlange ist geliefert
		// Eff.: keins
		virtual E front() const = 0;

		// Spezifikation
		// Vor.: keins
		// Erg.: keins
		// Eff.: Ein Element E ist an der Warteschlange
		//       platziert
		virtual void enqueue(E) = 0; //vieleicht enqueue ?
};
