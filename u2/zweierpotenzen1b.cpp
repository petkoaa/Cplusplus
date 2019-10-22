#include <iostream>
#include <cmath>

using namespace std;



int main()
{
    int lowerBorder;
    cout << "Enter a number: " << endl;
    cin >> lowerBorder;

    int upperBorder;
    cout << "Enter a number bigger than "<< lowerBorder << endl;
    cin >> upperBorder;

    for(int i = 0; i < upperBorder; i++ ){
        if((pow(2, i) >= lowerBorder) && (pow(2, i) <= upperBorder )){
            cout << pow(2, i)<<"," <<endl;
        }

    }


return 0;
}


