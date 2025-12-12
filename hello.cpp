#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& A) {
    cout << "[ ";
    for (auto a : A) cout << a << " ";
    cout << "]" << endl;
}

void insertion_sort(vector<int>& A) {
    for (int i = 1; i < int(A.size()); i++) {
        int key = A[i];
        // Insertamos A[i] en el sorted subarray A[0 : i-1], desplazando A[x : i-1] a la derecha (A[x+1 : i-1]) para dejar A[x] libre, en A[x] estara A[i]. 
        int j = i-1;
        // Este bucle desplaza el subarray hasta q encontramos el spot para A[i]
        while (j >= 0 and A[j] > key) {
            A[j+1] = A[j]; // Movemos A[j] a A[j+1] para dejar el lugar de A[j] libre
            j--;
        }
        // Luego de desplazar el subarray, insertamos key en el ultimo A[j] que dejamos libre
        A[j+1] = key;
    }
}

int main() {
    
    vector<int> A = {5, 4, 2, 1};
    print(A);
    insertion_sort(A);
    print(A);
}