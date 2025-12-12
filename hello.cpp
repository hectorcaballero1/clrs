#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(const vector<T>& A) {
    cout << "[ ";
    for (const auto& a : A) cout << a << " ";
    cout << "]" << endl;
}

void insertion_sort(vector<int>& A) {
    for (int i = 1; i < A.size(); i++) {
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


/*
Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n+1)-element array C.
Input: An array of booleans A and an array of booleans B, each representing an integer stored in binary format (each digit is a number, either 0 or 1 , least-significant digit first) and each of length n.
*/

vector<int> add_binary_integers(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> C(n+1);

    int carry = 0;
    for (int i=0; i<n; i++) {
        int sum = A[i] + B[i] + carry;
        C[i] = sum%2;
        carry = sum/2; 
    }
    C[n] = carry;

    return C;
}

int main() {
    
    vector<int> A = {5, 4, 2, 1, 12, 54, 11, 10, 9};
    print(A);
    cout << linear_search(A, 1) << endl;
    insertion_sort(A);
    print(A);

    cout << linear_search(A, 1) << endl;


    vector<int> B = {1, 1, 0, 1};  // 1011 (lee de derecha a izquierda)
    vector<int> C = {0, 1, 1, 0};
    vector<int> D = add_binary_integers(B,C);
    print(D);

}