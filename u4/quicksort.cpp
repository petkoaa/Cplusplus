#include <vector>
#include <stdlib.h>

using namespace std;
void swap(vector<int>& v, int x, int y);

void quicksort(vector<int> &vec, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void swap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

int main() {
    vector<int> vec1;
    const int count = 10;

    for (int i = 0; i < count; i++) {
        vec1.push_back(1 + (rand() % 100));
    }
    quicksort(vec1, 0, count - 1);  // quicksort (vector, start, size of vector )

}
