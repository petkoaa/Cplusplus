#include <iostream>
#include <string>

using namespace std;

unsigned hamming(string, string);
//SPEZIFIKATION:
//Voraussetzung: Eingabe strings die Selbe Laenge, oder String 1 llaenger als String 2
//Effekt: Hamming Abstand zwischen beide Strings auf dem Bildschirm gezeigt
//Ergebnis: kein

// 1f wieder pass by value
int main ()
{
    string dNA1,dNA2;
    cout<< "Type in a DNA String of length 5: "<<endl;
    cin>>dNA1;

    cout<< "Type in a second DNA String of the same length: "<<endl;
    cin>> dNA2;

    hamming (dNA1,dNA2 );

    return 0;
}

unsigned hamming(string dNA1, string dNA2)
{
     int n =0;
    for (int i=0; i<dNA1.length(); i++)
    {
        if (dNA1[i] != dNA2[i])
            {
                n=n+1;
            }

    }
        cout<<n;

}

