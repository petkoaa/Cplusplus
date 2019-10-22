#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void mega_sort (vector <int> &vec, unsigned k);
// Voraussetzungen: k >= 20
// Ergebnis: keins
// Effekt: Die Elemente von array sind monoton steigend sortiert.
void swap(vector<int>& v, int x, int y);
void quick_sort(vector<int> &vec, int L, int R, unsigned k);
int pivot (vector <int>vec);
void insertionSort(vector<int> &vec, int n);
void printVec (vector<int> x); //print funk for vectors, in case you want to check something



int main ()
{
    vector<int> some_vec = {2,5,7,4,6,6,3,5,7,2,3,4,6,123123,123,213,12,3,123,12,3,123,21,31,
    2376,34,4236,43,5,345,4,5,543,4,6,5};
    mega_sort(some_vec,3);
    printVec(some_vec);

}

void mega_sort (vector <int> &vec, unsigned k){
    if (k>=vec.size())
    {
        quick_sort (vec, 0,vec.size()-1,k);
    }else{int n = vec.size();
        insertionSort(vec,n);}
}

void quick_sort(vector<int> &vec, int L, int R, unsigned k) {
    if (k>=vec.size()){
    int i, j, piv;
    i = L;
    j = R;
    piv = pivot(vec);

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j);
            i++;
            j--;
        }
        else {
            if (i < R)
                quick_sort(vec, i, R, k);
            if (j > L)
                quick_sort(vec, L, j, k);
            return;
        }
    }
}else{
    int n = vec.size();
        insertionSort(vec,n);}
}


void swap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

int pivot (vector <int>vec) //random partition
{
    int len= vec.size()-1;
    int a =  rand() % len;
    int b = rand() % len;
    int c = rand() % len;
    if ((a>=b && b>=c)||(c>=b && b>=a)) return b;
    else if ((b>=a && a>=c)||(c>=a && a>=b)) return a;
    else if ((a>=c && c>=b)||(b>=c && c>=a)) return c;

}



void insertionSort(vector<int>& data, int n)
{

    int i, j, tmp;

        for (i=1; i<n; i++)
        {
            j=i;
            tmp=data[i];
            while (j>0 && tmp<data[j-1])
            {
                data[j]=data[j-1];
                j--;
            }
            data[j]=tmp;
    }
}



void printVec (vector<int> x)    //print funk for vectors, in case you want to check something
 {
  for (int n=0; n<x.size(); n++)
    cout << x[n] << ", ";
}


