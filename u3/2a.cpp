#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getVector (string *a);
vector<int> newVector (vector<int> a);
void myPrint (vector<int> x);


int main (){

string eingabe;
cout<< "Type in a string: "<<endl;
cin>> eingabe;

int mass = eingabe.length();    // calculate the length of input string

string* einGabe = new string [mass]; //create dynamically allocated string to save input into

(*einGabe).assign(eingabe); // assign value of eingabe ot einGabe just for fun

cout<< newVector(getVector (einGabe)).size() ; // reslut print size of newVector23



return 0;
}


vector<int> getVector (string *a) //get a list of ascii integers
{

    int len = (*a).length();
    vector <int> vec;
    for (int i=0; i<len; i++)
    {

        int c = (int)((*a)[i]);
        vec.push_back(c);
    }


    return vec;
}

vector<int> newVector (vector<int> a) //get a vector of the non-repeating ascii ints
{
    vector <int> newvec;
    for(int i =0; i<a.size(); i++)
    {
        int b = a.at(i);
          if(find(newvec.begin(), newvec.end(), b) != newvec.end()) //checks if b is already contained in newvec
            {
                cout<<b<<"contained more that once"<<endl;    //if it is
            } else {
                newvec.push_back(b);        //if its not
            }
    }
    return newvec;
}

void myPrint (vector<int> x)    //print funk for vectors, in case you want to check something
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n] << endl;
}

