#include <iostream>

using namespace std;

int main () {

    int n;      //eingabe zahl
    int m = 0;
    int a = 1;       // variablen zum potenzen rechnen
    int b = 1;

    cout << "Type in a positive integer greater than 2: " << endl;
    cin >> n;


    do {b =b* 2;                //liste der Zweierpotenzen
        if (b <= n) {cout << b << ",";}
    }while (b <= n);



    do {a =a* 3;                //liste der Dreierpotenzen
        if (a <= n) {cout << a << ",";}
    }while (a <= n);




    while (m <= n) {          //liste von zahlen die zaweier und dreierpotenzen sind
        m = m+1;
        if (m%3 == 0 && m%2 == 0) {cout << m << ",";}
    }




    return 0;
}
