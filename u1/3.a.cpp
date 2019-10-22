#include <iostream>
using namespace std;
#include <string>

string dNA;
string rNA;

int main (){

    cout <<"give DNA: "<<endl;
    cin>> dNA;
   //int a = length(dNA);

        for (int i=0; i<dNA.length(); i++){
        char base = dNA[i];
        if (base == 'A'){cout<<'A';}
        else if (base == 'G'){cout<<'G';}
        else if (base == 'T'){cout<< 'T';}
        else if (base == 'C'){cout << 'u';}
        else cout<< "Invalid"<<endl;

    }


return 0;
}
