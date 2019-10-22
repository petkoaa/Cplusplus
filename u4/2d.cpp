#include <iostream>
#include <cmath>

using namespace std;


void zweierpotenzen(int a, int b);
//SPEZIFIKATION:
//Voraussetzung: kein
//Effekt: Die zweierpotenzen im Intervall, auf dem Bildschirm gezeigt
//Ergenis: kein

//1f wieder pass by value weil nichts veraendert wird // man koennte auch naturlich fur alle aufgabe bis hier
//pass by reference wenn man speicher sparen wollte

int main ( )
{
    int lowerBorder;
    int upperBorder;
    cout << "Enter a number: " << endl;
    cin >> lowerBorder;

    cout << "Enter a number bigger than "<< lowerBorder << endl;
    cin >> upperBorder;

    zweierpotenzen(lowerBorder, upperBorder);

return 0;
}


void zweierpotenzen(int a, int b)
{
    int lowerBorder = a;
    int upperBorder = b;

    for(int i = 0; i < upperBorder; i++ )
        {
            if((pow(2, i) >= lowerBorder) && (pow(2, i) <= upperBorder ))
            {
                cout << pow(2, i)<<"," <<endl;
            }

        }
}
