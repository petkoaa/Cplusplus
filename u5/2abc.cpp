// Namen:
// Tutorium:
// Übung 5, Aufgabe 2
// Kompilieren: g++ -Wall -Wextra -Werror -pedantic -std=c++14 -o aufgabe2 aufgabe2.cpp

// Bemerkung: Die Datei ist zurzeit ohne -Werror kompilierbar. Sie dürfen die Datei als
// Vorlage benutzen und natürlich auch frei verändern. Einige Denkanstöße sind
// bereits bei den Kommentaren hinterlegt. Die main soll Ihnen helfen, zu verstehen,
// was verlangt wird.
#include <iostream>
#include <vector>
using namespace std;

//hilfsfunktionen "generic" binary search Algorithmen
int binsearch1 (vector<int>skirr, int a);   //return : index ab welchem alle Eintraege in array >= a
int binsearch2 (vector<int>skirr, int a);   //return : index ab welchem alle Eintraege in array <= a


struct eintrag {
	char symbol;
	unsigned anzahl;
};

// vector<int> find_all(vector<int> & array, int a, int b)   <-- Vielleicht auch so?
//2c ich habe mich fur call by value entchieden weil irgendwelche veraenderungen in array
//konnen die nachsten anwendungen von find_all auf die selben array schlecht beeinflussen
//SPEZIFFIKATION
//Varaussetzung: nur fur sortierte integer vektoren geeignet
//Effekt: keine
//Ergebniss: der Vektor alle elemente im Intervell [a,b] ist geliefert
vector<int> find_all(vector<int> arr, int a, int b) {

    int groesse; //zum bestimmen die Groesse von ausgabe
    int left;
    int right;

	if (a>b)
    {
        a = b;
        b = a;
    }else
    {
        left = binsearch1 (arr, a);
        right = binsearch2 (arr, b);
        groesse = right - left +1;
    }



	vector<int> ausgabe (groesse); 	// Neues Array mit (groesse) Elementen.


	cout<<left<<endl<<right<<endl;
	int j=0;                                       //index für ausgabe
	for (int i = left; i<1+right; i++)             // alle elemente zwischen left und right (inkl. right)
    {                                              // in ausgabe schmeisen
        ausgabe[j]=arr[i];
        j++;
    }



	return ausgabe;

}


// unsigned find(vector<eintrag> & array, char c)  <-- Vielleicht auch so?
//2c ich habe mich fur call by value entchieden weil irgendwelche veraenderungen in array
//konnen die nachsten anwendungen von find auf die selbe array schlecht beeinflussen
//SPEZIFIKATION:
//Voraussetzung: nur fur sortierte vektoren mit elemente der Typ "eintrag"
//Effekt: keine
//Ergebnis: wert der member of eintrag "anzahl" ist geliefert
//      Sonderfall: falls c nicht im arr auftritt ist "0" geliefert
unsigned find(vector<eintrag> arr, char c) {

	int low = 0;
	int high = arr.size() - 1;
	int middle = (low + high) /2;

	char sym;

	while (low < high)
    {
        middle = (low+high)/2;
        sym = arr[middle].symbol;                          //sym ist die char wert von arr[n]
        if ( high - low == 1){return 0;}                   //wenn c nicht in arr ist
        if ( sym == c ) {return arr[middle].anzahl;}
        else if (sym < c) { low=middle;}
        else {high = middle; }


    }




}
/////////////////////////////////MAIN////////////////////////////////////////////////////////////////////////

int main() {



	vector<int> zahlen = {-2,0,3,5,14,36,42,89,101};

	vector<int> weniger_zahlen = find_all(zahlen, 36, 95);

	// Die folgende Schleife sollte dann 36, 42, 89 auf dem Bildschirm ausgeben.
	for (unsigned i = 0; i < weniger_zahlen.size(); i++)
		cout << weniger_zahlen[i] << " ";
	cout << endl;

	cout<<"/////////////////////////////////////Aufgabe 2 b "<<endl;


	eintrag a = {'a', 10};
	eintrag b = {'b', 12};
	eintrag t = {'t', 3};
	eintrag x = {'x', 0};
	eintrag y = {'y', 42};
	eintrag z = {'z', 6};

	vector<eintrag> histo = {a, b, t, x, y, z};

	cout << find(histo, 't') << endl; // Sollte 3 auf dem Bildschirm ausgeben
	cout << find(histo, 'x') << endl; // Sollte 0 auf dem Bildschirm ausgeben
	cout << find(histo, 'b') << endl; // Sollte 12 auf dem Bildschirm ausgeben
	cout << find(histo, 'f') << endl; // Sollte 0 auf dem Bildschirm ausgeben, weil f nicht vorhanden.  */

	return 0;
}

////////////////////////////////////FUNKTIONEN//////////////////////////////////////////////////////////////////


int binsearch1 (vector<int>skirr, int a)

{
    int low = 0;
    int high = skirr.size() - 1;
    int middle = (low+high)/2;

    while (low<=high)
    {
        middle = (low+high)/2;
        if (high- low == 1 )                       //wenn wert a nicht in array ist
        {                                     // am enge kommt binsearch zwischen zwei konsequente integers
            return high;                     // soll die groessere grenzwert ausgegeben werden
        }
        if (skirr[middle] == a)
        {
            return middle;

        }else if(skirr[middle] < a)
        {
            low = middle;
        }else
        {
            high = middle;
        }
    }

}



int binsearch2 (vector<int>skirr, int a)

{
    int low = 0;
    int high = skirr.size() - 1;
    int middle = (low+high)/2;

    while (low<=high)
    {
        middle = (low+high)/2;
        if (high - low ==1)                        //wenn wert a nicht in array ist
        {                                       // am enge kommt binsearch zwischen zwei konsequente integers
            return low;                        // soll die kleinere grenzwert ausgegeben werden
        }
        if (skirr[middle] == a)
        {
            return middle;

        }else if(skirr[middle] < a)
        {
            low = middle;
        }else
        {
            high = middle;
        }
    }

}
