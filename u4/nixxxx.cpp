#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int median(vector<int>);

int funk1(vector<int>*myvec);  //hilfsfunktionen
int funk2(vector<int>*myvec);

int a = 0;  //variablen zum rechnen
int b = 0;


int main ()
{


    return 0;
}


int median(vector<int>vec)
{
    funk1(&vec);

}




 int funk1(vector<int>*myvec)
    {

     //terminates if the vector is of even numbers and empty
       if ((*myvec).empty())
       {
           return ::a;
       }else
       {
           ::a = (*myvec).at(0);
           funk2(((*myvec).erase((*myvec).begin())));
       }
    }
int funk2(vector<int*myvec)
    {
        ::b = myvec.end();
        erase(myvec.begin());
        if (myvec.empty())
        {
            return (a+b)/2;
        }else
        {
            funk1(&myvec);
        }
    }




