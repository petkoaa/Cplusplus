#include <iostream>
#include <string>

using namespace std;



string kompl (string dNA);
string rev (string dNA) ;

int main(){       // Reversed complement of the input DNA string

string dna;
cout<<"gimme a dna string: ";
cin>>dna;

kompl(rev(dna));

return 0;
}

string kompl (string dNA){    //prints out the coplement

        for (int i=0; i<dNA.length(); i++){

        char base = dNA[i];
        if (base == 'A'){cout<<'T';}
        else if (base == 'G'){cout<<'C';}
        else if (base == 'T'){cout<< 'A';}
        else if (base == 'C'){cout << 'G';}
        else cout<< "Invalid"<<endl;

    }
return dNA;
}

string rev(string dNA)    // but it reverses it first
{
    int n = dNA.length();

    for (int i = 0; i < n / 2; i++)
        swap(dNA[i], dNA[n - i - 1]);
return dNA;
}
