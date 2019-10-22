#include <iostream>
#include <vector>

using namespace std;

vector <int> output;
vector <int> selectsort (vector <int>& input);
void myPrint (vector<int> x);    //print funk for vectors, in case you want to check something



int main ()
{
    vector <int> input ={23, 23, 1, 42, 34, 6, 1};
    myPrint (input);
    cout<<"     <-- before select sort"<<endl;
    selectsort(input);

    myPrint(input);
    cout<<"     <-- after select sort"<<endl;

    return 0;
}

vector <int> selectsort (vector <int>& input)
//meine algorithmus ist schon stabil
{

int vecsize = input.size();
for (int j = 0; j < vecsize - 1; j++) {

    int klein = j;
    for (int i = j+1; i < vecsize; ++i) {
        if (input.at(klein) > input.at(i)) {   //haette ich hier nicht > sondern >= geschrieben waere der algorithmus
            klein = i;                          // nicht stabil sein
        }

    }
    if (klein != j)
        swap(input.at(j), input.at(klein));
}

}


void myPrint (vector<int> x)    //print funk for vectors, in case you want to check something
 {
    cout<<"[ ";
  for (int n=0; n<x.size(); n++){
    cout << x[n]<<", " ;
  }
  cout<<"]";
}
