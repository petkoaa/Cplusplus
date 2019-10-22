//Uebunngs blatt 8
//Aufgabe 2

#include <iostream>
using namespace std;

class dvdplayer {

private:
    string marke;
    int bauJahr;
    bool bluRay;

public:
    //Konstruktor -----------------------------------------
    // Default-Konstruktor:	DVDplayer() {}

		// Vor.: keine
		// Erg.: keins
		// Eff.: Eine DVD Player ist erstellt. Der Text
		// "Ein DVD Player ist in shop angekommen. " ist auf dem Bildschirm angezeigt.
		dvdplayer () {
			cout << "Ein DVD Player ist in shop angekommen. " << endl;
		}

    // Destruktor -----------------------------------------------------

		// Default-Destruktor:	~dvdplayer() {}

		// Vor.: keine
		// Erg.: keins
		// Eff.: Der DVD player ist zerstoert. Der Text
		//       "Der DVD Player ist zerstoert." ist auf dem Bildschirm angezeigt.
		~dvdplayer() {
			cout << "Der DVD Player ist zerstoert" << endl;
		}


    // Methoden -------------------------------------------------------

		// Vor.: keine
		// Erg.: keins
		// Eff.: Der parameter bluRay ist entweder auf true oder false gesetzt
		void hat_blu_ray(bool wert) {
			this->bluRay = wert;


        //Vor.: keine
        //Erg.: keine
        //Eff.: Die Baujahr des DVD Players ist neugesetzt.
        void gebaut_in(int jahr){
            this-> bauJahr = jahr;
        }

		//Vor.: keine
		//Erg.: keine
		//Eff.: Die Marke des Herstellers ist neugesetzt =.
		void marke_ist (string make) {
            this-> marke = marke;
		}

		//Vor.: keine
		//Erg.: keine
		//Eff.: Die Marke, Baujahr und ob der Player BluRay lesen kann sind auf dem Bildschirm angezeigt.
		void info_player (dvdplayer dvd){
            cout << "Marke: "<< marke
		}
};
