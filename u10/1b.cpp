//Uebungsblatt 10 // Petko Antonov // Yuwei Nan

#include <iostream>
#include <vector>
#include "09hilfsfunktionen.cpp"        //quicksort
#include "09sortierfunktionen.cpp"

using namespace std;

void naiv(vector<int> &l1, vector<int> &l2, vector<int> &l3);
//Spezifikation
//Vor.: keine
//Erg.: keins
//Eff.: Auf dem Bildschirm wird JA oder NEIN gezeigt wenn
//      eine kombination  x+y+z= 0 existiert.

void schnell(vector<int> &l1, vector<int> &l2, vector<int> &l3);
//Spezifikation
//Vor.: keine
//Erg.: keins
//Eff.: Auf dem Bildschirm wird JA oder NEIN gezeigt wenn
//      eine kombination  x+y+z= 0 existiert.

//////////////////////////////////////////////////////////////bin search
bool suche(vector<int> & array, int k);
bool bin_search(vector<int> & array, int k, unsigned left, unsigned right);




/// Main-------------------------------------------------------------------
int main (){

    vector<int> l1 ={1,2,3};
    vector<int> l2 ={4,5,6};
    vector<int> l3 ={-6,8,9};

    naiv(l1,l2,l3);             // tests

    schnell(l1,l2,l3);


}


/// Funktionsdeffinitionen-------------------------------------------------
void naiv(vector<int> &l1, vector<int> &l2, vector<int> &l3){

    for (unsigned x=0; x<l1.size(); x++ ){      // 3 for-Schleifen =O(n^3)
        for (unsigned y=0; y<l2.size(); y++ ){
            for (unsigned z=0; z<l3.size(); z++ ){
                if ( l1.at(x) + l2.at(y) + l3.at(z) ==0){
                    cout<<" JA ! "<<endl;
                    return;
                }
            }
        }
    }
    cout<<" NEIN ! ";           //else cout nein
}


void schnell(vector<int> &l1, vector<int> &l2, vector<int> &l3){

    vector<int>* l4= new vector<int> ((l1.size())*(l2.size()));   //allozieren vector l4
    unsigned counter = 0;          //counter fuer l4 elemente

    for(unsigned x=0; x<l1.size(); x++){        //doppel for-Schleife = o(n^2)
        for (unsigned y=0; y<l2.size(); y++){
            (*l4).at(counter) = l1.at(x) + l2.at(y);
            counter ++;
        }
    }
    random_quick_sort(*l4);                     // + quicksort O(

    for (unsigned z=0; z<l3.size(); z++ ){
        if (suche ((*l4), l3.at(z))) {
            cout<<" JA ! "<<endl;
            return;
        }
    }

    cout<< " NEIN ! "<<endl;            //else cout NEIN
}

///-Modifizierte bin suche-----------------------------------------------------------

bool bin_search(vector<int> & array, int k, unsigned left, unsigned right){
	if (left >= right)
		return false;
	unsigned mitte = (left + right) / 2;
	if (k == array[mitte])
		return true;
	else if (k < array[mitte])
		return bin_search(array, k, left, mitte);
	else
		return bin_search(array, k, mitte+1, right);
}

// Binäre Suche - schnell :-)
bool suche(vector<int> & array, int k) {
	return bin_search(array, k, 0, array.size());
}

