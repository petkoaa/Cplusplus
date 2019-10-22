#include <iostream>
#include <string>

using namespace std;

double taschenrechner(double, double, string);
//SPEZIFIKATION:
//Vouraussetzung: moegliche operationen sind PLUS, MINUS, MAL oder GETEILT;
//Effekt: Resultat auf Bildschirm gezeigt
//Ergenbis: kein

//1f) hier benutze ich pass by value weil nichts veraendert wird und die Program sehr einfach ist


int main ()
{
double number1;
string operation;
double number2;

cout<<"Number 1 is? : ";  //Erste Zahl eingeben
cin>>number1;


cout<<"Operation? :  ";
cin>>operation;

cout<<"Aaand number 2 is? : ";
cin>>number2;

taschenrechner(number1,number2,operation);


return 0;
}



double taschenrechner(double a, double b, string c)
{
     if (c == "PLUS" ){ cout<<a+b;}
     else if (c =="MINUS" ){ cout<<a-b;}
     else if (c=="MAL" ){cout<<a*b;}
     else if (c =="GETEILT" ){cout<<a/b;}

     return 0;
}


