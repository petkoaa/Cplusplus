#include <iostream>
#include <string>
using namespace std;

char complement(char c) {
	switch (c) {
		case ('A'): return 'T';
		case ('T'): return 'A';
		case ('C'): return 'G';
		case ('G'): return 'C';
		default: return c;
	}
}

string reverse_compl1(string   dna)
    //SPEZIFIKATION:
	//Voraussetzung: include <string>,<iostream>;   die funktion (char complement ()) ist auch irgendwie geladen;
	//Effekt: kein
	//Ergebnis: Reverse-Komplement der Eingabe-DNA-string auf dem Bildschirm gezeigt
{

	// Zuerst wird jeder Character in sein Komplement umgewandelt.
	for (unsigned i = 0; i < dna.length(); i++) {
		dna[i] = complement(dna[i]);
	}

	// Nun wird der String umgedreht und dabei in der Hilfsvariable
	// dna_reverse gespeichert.
	string dna_reverse = "";
	for (unsigned i = 0; i < dna.length(); i++) {
		dna_reverse = dna[i] + dna_reverse;
	}

	// dna_reverse wird ausgegeben.
	return dna_reverse;

}

string reverse_compl2(string & dna)
 //SPEZIFIKATION:
	//Voraussetzung: include <string>,<iostream>;   die funktion (char complement ()) ist auch irgendwie geladen;
	//Effekt: Eingabestring wird in der Komplementstrand umgewandelt und global gespeichert.
	//Ergebnis: Reverse-Komplement der Eingabe-DNA-string auf dem Bildschirm gezeigt
 {

	// Zuerst wird jeder Character in sein Komplement umgewandelt.
	for (unsigned i = 0; i < dna.length(); i++) {
		dna[i] = complement(dna[i]);
	}

	// Nun wird der String umgedreht und dabei in der Hilfsvariable
	// dna_reverse gespeichert.
	string dna_reverse = "";
	for (unsigned i = 0; i < dna.length(); i++) {
		dna_reverse = dna[i] + dna_reverse;
	}

	// dna_reverse wird ausgegeben.
	return dna_reverse;
}

int main() {

	string dna = "ACAGGT";

	cout << reverse_compl1(dna) << endl;
	cout << dna << endl;
	cout << reverse_compl2(dna) << endl;
	cout << dna << endl;

}
