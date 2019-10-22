#include <iostream>
#include <string>
#include <vector>


using namespace std;



int median(vector<int>myvec);
//SPEZIFIKATION:
//Voraussetzung:zahlen in Eingabevektor sind sortiert  //wenn man erst die quicksort anwendet gibt es keine voraussetzungen
//Effekt: kein
//Ergebnis: Median ist Geliefert


vector<int> str2vec (string str);  //string von ASCII zeichen in beliebige integers umwandeln, zahlen bleiben unverandert
void quicksort(vector<int> &vec, int l, int r); // quicksort fur sortieren von Eingabevektor
void myswap(vector<int>& v, int x, int y);      // hilfsfunktion der quicksort
void myPrint (vector<int> x);                   // printiert vektor auf dem Bildshirm


int main ()                                     //das Program hier ist zum Ausprobieren der Algorithmus
{
    string str;                                 //eingabe string von ascii zeichen
    cout<<"need a string of ints : "<<endl;     //eingeben und in str variable speichern
    cin>> str;

    int mySize = str.length();                  //hilfsvariable fur quicksort


    vector <int>newStuff = str2vec(str);        // vektor aus str erzeugen mit hilfe von str2vec und in newStfuff speichern
    myPrint(newStuff);                          // eingabe vektor auf bildschirm printieren
    cout<< "    <---  The input Vector "<<endl; //

    quicksort(newStuff,0,mySize-1);             //quicksort wird auf newStuff angewandt und neugespeichert
    myPrint(newStuff);                          //sortierte vektor auf Bildschirm gezeigt
    cout <<"    <---  The sorted Vector"<<endl; //

    cout<< "The median is : "<< median(newStuff)<<endl;     //median auf bildschirm gezeigt

    return 0;                                               //termination
}

int median(vector<int>myvec)
{

    if ((myvec.size())%2==0) //entscheidet ob der laenge des vektors gerade oder nicht ist
    {
        int a = myvec.at( ((myvec.size())/2) -1 );   //wenn ja nehmen wir den element mit position laenge/2 - 1
        int b = myvec.at ( ( (myvec.size())/2)  );   //und der nachste element
        int c = ((a+b)/2);                           //und teilen die Summe in 2
        return c;
    }else{                                          // wenn nicht nehmen wir den element mit position laenge/2
        int c = myvec.at( ((myvec.size())/2)  );
        return c;
    }                                               //c - median istgeliefert in beide faelle

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




void quicksort(vector<int> &vec, int l, int r) {           //quicksort mit pass by reference
    int i, j, mid, piv;
    i = l;                                                // hier macht es sinn pbr zu verwenden um die
    j = r;                                                // liste sortiert zu speichern weil die unsortierte liste
    mid = l + (r - l) / 2;                                // die selbe als die eigabe liste ist
    piv = vec[mid];

    while (i<r || j>l) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            myswap(vec, i, j);
            i++;
            j--;
        }
        else {
            if (i < r)
                quicksort(vec, i, r);
            if (j > l)
                quicksort(vec, l, j);
            return;
        }
    }
}

void myswap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}




void myPrint (vector<int> x)    //print Funktion für Vektoren
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n]<<",";
}
