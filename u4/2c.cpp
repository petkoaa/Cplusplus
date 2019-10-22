#include <iostream>
#include <string>
using namespace std;

int quersumme (string zahl );
//SPEZIFIKATION:
//Voraussetzung: Eingabestring besteht nur aus positive Ganzezahlen
//Effekt: Quersumme auf dem bilschirm gezeigt
//Ergebnis: kein

//1f immer noch pass by value weil nichts verändert wird

int main ( )
{
    string zahl;
    cout<<"int : "<<endl;
    cin>> zahl;
    quersumme(zahl);
}




int quersumme (string zahl)
{
    int b = 0;
    for (int i = 0; i<zahl.length(); i++)
    {
        int k = (zahl[i] - '0');
        b=b+k;
    }

    cout<<b;
}
