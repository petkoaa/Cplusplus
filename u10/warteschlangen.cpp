 #include "queue.hpp"
 #include <iostream>
 using namespace std;



template <typename E>
class VKQueue : public Queue <E> {

private:
    struct wartende {
        E elem;
        wartende* naechstes;
    };
     int anzahl;
     wartende* erstes;

public:
        public:
		// Konstruktor
		// Vor.: keine
		// Eff.: Eine leere Warteschlange ist erzeugt.
		// Erg.: keins
		VKQueue() {
			this->anzahl = 0;
			this->erstes = nullptr;
			cout<<"queue entsteht"<<endl;
		}

		// Destruktor
		// Vor.: keine
		// Eff.: Der Speicher des Objekts ist freigegeben.
		// Erg.: keins
		~VKQueue() {
			while (!this->is_empty()) {
				this->dequeue();
			}
			cout<< "queue weg geflext"<< endl;
		}

		bool is_empty() const {
			return this->erstes == nullptr; // alternativ
			// return this->anzahl == 0;
		}


		// Spezifikation
		// Vor.: keine
		// Erg.: Der erste Element in der Warteschlange ist geliefert ?
		// Eff.: keins ?
        E front() const {
            return this -> erstes -> elem;
		}

		// Spezifikation
		// Vor.: keine
		// Erg.: Das erste Element in der Warteschlange ist geliefert
		// Eff.: Das erste Element ist von der Warteschlange
		//       entfernt.
		E dequeue() {
            wartende* kptr = this->erstes;
			this->erstes = this->erstes->naechstes;
			E element = kptr->elem;
			delete kptr;
			this->anzahl--;
			return element;
			cout<< "dequeued"<<endl;
		}
		/*
		//Spezifikation overload dequeue
		//Vor.: keine
		//Erg.: keins
		//Eff.: Erstes Element der Queue ist zerstoert.
		dequeue() {
		    delete this-> erstes;
            this->erstes = this->erstes->naechstes;
		}

       */

        // Spezifikation
		// Vor.: keins
		// Erg.: keins
		// Eff.: Ein Element E ist am Ende der Warteschlange
		//       platziert
        void enqueue(E element) {
            wartende* kptr = new wartende();
			kptr->elem = element;
			kptr->naechstes = this->erstes;
			this->erstes = kptr;
			this->anzahl++;
			cout<< "enqueued"<<endl;
        }



} ;

int main (){
    typedef VKQueue <int> somequeue;
    somequeue queue1;
    int i = 10;
    queue1.enqueue(i);
    queue1.enqueue(i);
    queue1.enqueue(i);

}
