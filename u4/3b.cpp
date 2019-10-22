#include <iostream>
#include <string>
#include <algorithm>
#include <vector>vector<int> getVector (string *a) //get a list of ascii integers


using namespace std;

vector<int> string2ascii(string str);
//SPEZIFIKATION:
//Voraussetzung: String muss mur aus ascii zeichen bestehen
//Effekt: Keine
//Ergebnis: Vektor der ASCII Zeichen ist geliefert

//1f pass by value

void myPrint (vector<int> x);


int main()
{
    string str;
    cout << "Type in a string : "<<endl;
    cin>>str;

     myPrint(string2ascii(str));


}


vector<int> string2ascii(string str)

{

    int len = (str).length();  //speichert laenge des strings
    vector <int> newVec;          //neu erzeugene vektor
    for (int i=0; i<len; i++)
    {

        int c = (int)str[i];
        newVec.push_back(c);
    }


    return newVec;
}

void myPrint (vector<int> x)    //print funk for vectors, in case you want to check something
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n]<<", " ;
}


