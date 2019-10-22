//Uebungsblatt 10 // Petko Antonov // Yuwei Nan
//Aufgabe 1 a

#include <iostream>
#include "09hilfsfunktionen.cpp"        //quicksort
    #include "09sortierfunktionen.cpp"
#include <vector>


using namespace std;

void naiv ( vector <int> &vec) ;
//Spezifikation
//Vor.: keine
//Erg.: Gibt "true" wenn ein x und y existieren
//      fuer welche x-y<= 10 wahr ist sonst "false"
//Eff.: keins


void schnell ( vector <int> &vec) ;
//Speziffikation
//Vor.: keine
//Erg.: Gibt "true" wenn ein x und y existieren
//      fuer welche x-y<= 10 wahr ist sonst "false"
//Eff.: keins


int main (){
    vector <int> vec = {99,3};
    naiv(vec);
    schnell(vec);

}



void naiv (vector <int> &vec) {
    unsigned laenge = vec.size();
    for (int x = 0;  x < laenge; x++){         //doppel for schleife = O(n^2)
        for (int y = 0; y<laenge; y++){
            int a = vec.at(x);
            int b = vec.at(y);
            if ((a-b<=10)&&(b-a<=10)&&(b!=a) ){
                cout<<" JA ! ";
                 return;
            }
        }
    }
        cout<<" NEIN ! ";    return;



}


void schnell ( vector <int> &vec){
    merge_sort(vec);
    for(int x=0; x<vec.size()-1; x++){     //eine for schleife = O(n)
        int y = x+1;
        if((vec.at(x)-vec.at(y)<=10)&&(vec.at(y)-vec.at(x)<=10)&&(x!=y))
            cout<<" JA ! ";
                return;
    }

    cout<<" NEIN ! ";



}
