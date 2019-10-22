#include <iostream>
#include <vector>


using namespace std;

vector<int> index;  //globale variablen zum rechnen
int a = 0;


vector<int> firstRecc (int l, int m, vector<int> t_stellen);
//Achtung: Programm crashes beim unmoeglichem Plan
void findeTankestelle ( int l, int m, vector<int>&t_stellen );
void myPrint (vector<int> x);


int main ()
{
    vector<int> tryout;
    tryout.push_back(3);
    tryout.push_back(7);
    tryout.push_back(12);
    tryout.push_back(18);
    tryout.push_back(26);
    tryout.push_back(28);
    tryout.push_back(32);
    tryout.push_back(33);
    tryout.push_back(36);

    vector<int> testVec;
    testVec = firstRecc(42, 13, tryout);
    myPrint(testVec);




    return 0;
}





vector<int> firstRecc (int l, int m, vector<int> t_stellen)
{

		if ( (l-(::a)) > m ) {
			 	 findeTankestelle ( l, m, t_stellen) ;
			 	 firstRecc ( l, m, t_stellen);

		}

		    return ::index;
}


void findeTankestelle ( int l, int m, vector<int>&t_stellen  )
{
        int b = 0;

        while( (m+a) > t_stellen[0] )
        {
            b = t_stellen[0];
            t_stellen.erase(t_stellen.begin());
            if (t_stellen.empty()) {break;}
        }
        ::a=b;
        index.push_back(::a);



}

void myPrint (vector<int> x)    //print Funktion für Vektoren
 {
     cout<<"Wir mussen an Tankestelle(n): ";
  for (int n=0; n<x.size(); n++){
    cout << x[n]<<",";
 }
 cout<< " tanken. "<<endl;
}




