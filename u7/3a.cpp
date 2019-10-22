#include <iostream>
#include <vector>

using namespace std;


unsigned matrix_summe(vector<vector<unsigned>> & matrix);
//SPEZIFIKATION:
//Vouausetzung: matrix aus unsigned integers
//Effekt: keine
//Ergebnis: die Summe aus alle Eintraege der Matrix ist geliefert in O(n^2)

void summier (vector<unsigned> vec,unsigned &sum);

int main(){
    vector<vector<unsigned> > vect{ { 5, 2, 3 },
                                    { 9, 5, 6 },
                                    { 4556, 8, 9 } };


        matrix_summe(vect);

}


unsigned matrix_summe(vector<vector<unsigned>> & matrix)
{
    unsigned sum = 0;
    for (unsigned i = 0; i < matrix.size(); i++)
    {

        for (unsigned j =0; j < matrix[i].size();j++ )
        {
            sum = sum + matrix[i][j];
        }
    }
    cout<<sum;
    return sum;
}



