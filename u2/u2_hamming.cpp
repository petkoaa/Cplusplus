#include <iostream>
#include <string>

using namespace std;


string dNA1 ;
string dNA2 ;

int main()    //hamming abstand zwischen DNA strings der gleiche lange oder die erste länger als die zweite
{


    cout<< "Type in a DNA String of length 5: "<<endl;
    cin>>dNA1;


    cout<< "Type in a second DNA String of the same length: "<<endl;
    cin>> dNA2;

    int n =0;
    for (int i=0; i<dNA1.length(); i++){


        if (dNA1[i] != dNA2[i]){n=n+1;}

    }
        cout<<n;




        return 0;
}

