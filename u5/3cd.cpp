#include <iostream>
#include <vector>
using namespace std;

struct paar {int elem; unsigned index;};

void selectsort_paare(vector<paar>&  arr);//3c
//SPEZIFIKATION:
//Vouraussetzung: keine
//Effekt: eingabe array ist sortiert und gespeichert
//Ergebnis: keine

vector <int>  selectsort_stabil(vector<int> & arr);  //3d
//SPEZIFIKATION:
//Voraussetzung: keine
//Effekt keine
//Ergebniss: die sortierte liste ist geliefert
//Bemerkung: die selbe Ergebnis ist auch mit dem algorithmus aus 3b erreicht


vector <paar> paarvec (vector <int> intvec);//hilfsfunk 3d


void printPaarVec (vector<paar> x);    //print funk for PAAR vectors, in case you want to check something
void printIntVec (vector<int> x);    //print funk for vectors, in case you want to check something


int main ()
{
    vector <int> vec = {45, 34, 35 ,34, 34,  12, 34};

    printIntVec(selectsort_stabil(vec));


    return 0;
}


//////////////////////////////////////3C/////////////////////////////////////////

void selectsort_paare(vector<paar>  &arr)  //selectsort fur PAAR
{
    int vecsize = arr.size();
    for (int j = 0; j < vecsize - 1; j++)
    {

        int klein = j;
        for (int i = j+1; i < vecsize; ++i)
        {
            if ( arr[klein].elem > arr[i].elem) {   //stabil weil > nicht >=
            klein = i;
            }

        }
    if (klein != j)
        swap(arr.at(j), arr.at(klein));
    }
}

/////////////////////////////////////////3D//////////////////////////////////////////

vector<int> selectsort_stabil(vector<int> &arr)  //selectsort fur PAAR
{
    vector <paar> var = paarvec(arr);
    selectsort_paare(var);

    vector <int> output (var.size());
    for (unsigned i=0; i<var.size(); i++ )
    {
        output[i] = var[i].elem;
    }

    return output;
}



vector <paar> paarvec (vector <int> intvec)
{
     int len = intvec.size();
    vector <paar> newvec (len);
    for (unsigned i=0; i<intvec.size(); i++)
    {
        paar t = {intvec[i], i};
        newvec[i] = t;
    }
    return newvec;
}


////////////////////////////////////print///////////////////////////////////////////////////

void printPaarVec (vector<paar> x)    //print funk for PAAR, in case you want to check something
 {
    cout<<"[ ";
  for (int n=0; n<x.size(); n++){
    cout << x[n].elem<<", "<<x[n].index<<endl;
  }
  cout<<"]";
}


void printIntVec (vector<int> x)    //print funk for vectors, in case you want to check something
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n] << endl;
}
