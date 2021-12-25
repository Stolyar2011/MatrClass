#include<iostream>
#include "supermatrix.h"

using namespace std;

int main() {
    int n, m, n1, m1;
    cout << "Size of first matrix: ";
    cin >> n >> m;
    cout << "Size of second matrix: ";
    cin >> n1 >> m1;
    cout << "Integers for multiplication and power: ";
    int k, q;
    cin >> k >> q;
    supermatrix<int> a(n, m), b(n1, m1);
    cout << "Enter numbers for first matrix: " << endl;
    cin >> a;
    cout << "Enter numbers for second matrix: " << endl;
    cin >> b;
    cout << "Show result of all actions: " << endl;
    cout << "A + B = " << endl;
    try {
        cout << (a + b);
    } catch (const char *msg) {
        cerr << "ERROR: " << msg << endl;
    }
    cout << "A * B = " << endl;
    try {
        cout << (a * b);
    } catch (const char *msg) {
        cerr << "ERROR: " << msg << endl;
    }
    cout << "Transposed A: " << endl;
    cout << a.tr();
    cout << "Transposed B: " << endl;
    cout << b.tr();
    cout << "A * k: ";
    cout << (a * k);
    cout << "A ^ q: ";
    try {
        cout << (a ^ q);
    } catch (const char* msg) {
        cerr << "ERROR: " << msg << endl;
    }
    cout << "B * k: " << endl;
    cout << (b * k);
    cout << "B ^ q: " << endl;
    try {
        cout << (b ^ q);
    } catch (const char *msg) {
        cerr << "ERROR: " << msg << endl;
    }
    cout << "Det of first matrix is: " << endl;
    try {
        cout << a.det() << endl;
    } catch (const char *msg) {
        cerr << "ERROR: " << msg << endl;
    }
    cout << "Det of second matrix is: " << endl;
    try {
        cout << b.det() << endl;
    } catch (const char *msg) {
        cerr << "ERROR: " << msg << endl;
    }
}
