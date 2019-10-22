/* Informatik B SoSe19
 * 18. Vorlesung 14.6.2019
 * Max Willert
 */

#pragma once

template <typename E>
class Stack {
	
	// In einem Stack sind beliebige Elemente gespeichert.
	
	public:
		
		/* Voraussetzung: keine
		 * Ergebnis: keins
		 * Effekt: Der Speicher des Objekts ist freigegeben. */
		virtual ~Stack() {};

		/* Voraussetzung: keine
		 * Ergebnis: True ist genau dann geliefert, wenn keine Elemente
		 * auf dem Stack liegen.
		 * Effekte: keine */
		virtual bool is_empty() const = 0;
		
		/* Voraussetzung: Der Stack hat mindestens 1 Element.
		 * Ergebnis: Das jüngste Element ist geliefert.
		 * Effekte: Das jüngste Element ist entfernt. */
		virtual E pop() = 0;
		
		/* Voraussetzung: Der Stack hat mindestens 1 Element.
		 * Ergebnis: Das jüngste Element ist geliefert.
		 * Effekte: keine */
		virtual E top() const = 0;
		
		/* Voraussetzung: keine
		 * Ergebnis: keins
		 * Effekte: Das Argument der Methode ist nun das jüngste Element
		 * des Stacks. */
		virtual void push(E) = 0;
};
