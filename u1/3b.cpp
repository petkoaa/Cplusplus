#include <iostream>
#include <string>
using namespace std;

string zahl;

 int funk (string zahl );


int main () {
    cout<<"int : "<<endl;
    cin>> zahl;


    int b = 0;
    for (int i = 0; i<zahl.length(); i++){
        int k = (zahl[i] - '0');
        b=b+k;
    }


    cout<<b;




return 0;
}



