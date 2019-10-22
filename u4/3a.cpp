#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>,vector<int>);
vector<int> str2vec(string);
void myPrint (vector<int> x);

int main ()
{
    string str1;
    string str2;
    cout<<"Type in a string of integers : ";
    cin>>str1;
    cout<<"Type in another string of integers : ";
    cin>>str2;



    vector <int> vec1 = str2vec(str1);  // string 1 -> vec1
    vector <int> vec2 = str2vec(str2);  // string 2 -> vec2
    myPrint(  add((vec1), (vec2)) );    //printiert die Summe-Vektor, der aus die Addition der zwei Eingebestring konstruierte Vektoren entsteht



    return 0;
}

vector<int> add(vector<int>a,vector<int>b) //Addier zwei vektoren die aus integers bestehen
//SPEZIFIKATION:
//Voraussetzung: Zwei Vekroten aus integers
//Effekt: kein
//Ergebnis: Die Summe-Vektor aus der Eingabevektoren ist geliefert.

//1f macht nicht wirklich sinn pass by reference zu machen kann man auch naturlich are nichts wird veraendert und
//ein neues vector ist geliefert
{
    vector <int> newVec;
    for (int i=0; (i<a.size()&& i<b.size()); i++ )
    {

        int fs = a.at(i);
        int snd = b.at(i);
        int sum = fs+snd;
        newVec.push_back(sum);
    }
    return newVec;
}

vector<int> str2vec(string str) //String aus positive ints  in Vektor umwandeln
{
    vector <int> vec;
    for (int i=0; i<str.length(); i++)
    {
        vec.push_back(str[i]-48);
    }
    return vec;
}

void myPrint (vector<int> x)    //print Funktion für Vektoren
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n];
}

