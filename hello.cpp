#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& A) {
    cout << "[ ";
    for (const auto& a : A) cout << a << " ";
    cout << "]" << endl;
}

void insertion_sort(vector<int>& A) {
    for (int i = 1; i < int(A.size()); i++) {
        int key = A[i];
        // Insertamos A[i] en el sorted subarray A[0 : i-1], desplazando A[x : i-1] a la derecha (A[x+1 : i-1]) para dejar A[x] libre, en A[x] estara A[i]. 
        int j = i-1;
        while (j >= 0 and A[j] > key) { // Cambiando > por < pasamos de creciente a decreciente
            A[j+1] = A[j]; // Movemos A[j] a A[j+1] para dejar el lugar de A[j] libre
            j--;
        }
        // Luego de desplazar el subarray, insertamos key en el ultimo A[j] que dejamos libre
        A[j+1] = key;
    }
}

int linear_search(const vector<int>& A, int x) {
    for (size_t i = 0; i<A.size(); i++) if (A[i] == x) return i;
    return -1;
}

int main() {
    
    vector<int> A = {5, 4, 2, 1, 12, 54, 11, 10, 9};
    print(A);
    cout << linear_search(A, 1) << endl;
    insertion_sort(A);
    print(A);

    cout << linear_search(A, 1) << endl;
}