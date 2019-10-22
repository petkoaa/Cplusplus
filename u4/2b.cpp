#include <iostream>
#include <string>
using namespace std;

string dna2rna(string dNA);
//SPEZIFIKATION:
//Voraussetzung: eingabe DNA string ist mit groessen Buchstaben eingegebe
//Effekt: Zur Eingabe string equivalenta RNA-Strand auf Bildschirm gezeigt
//Ergebnis: kein

//1f ich benutze pass by value weil auch nichts verandert wird und die program sooll nur irgendwas ausdrucken
//und weil es einfacher zu implementieren ist
int main ()
{
    string dNA;
    string rNA;

    cout <<"give DNA: "<<endl;
    cin>> dNA;

    dna2rna(dNA);


return 0;
}

string dna2rna (string dNA)
{
    for (int i=0; i<dNA.length(); i++){
        char base = dNA[i];
        if (base == 'A'){cout<<'A';}
        else if (base == 'G'){cout<<'G';}
        else if (base == 'T'){cout<< 'T';}
        else if (base == 'C'){cout << 'u';}

}
}
