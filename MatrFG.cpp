#include <iostream>
#include "Matr.h"
#include <string>
#define _GLIBCXX_DEBUG

using namespace std;

void solve_int(){
    int n1, n2, m1, m2;
    cout << "Enter size of first matrix: ";
    cin >> n1 >> m1;
    int k;
    Matr<int> a(n1, m1);
    cout << "Enter elems of first matrix: ";
    cin >> a;
    cout << "Enter size of second matrix: ";
    cin >> n2 >> m2;
    Matr<int> b(n2, m2);
    cout << "Enter elems of second matrix: ";
    cin >> b;
    Matr<int> helper;
    try {
        helper = a + b;
        cout << "Sum of to matrix: " << endl << helper;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    cout << "Input a number for multiplication: ";
    cin >> k;
    helper = a * k;
    cout << "First matrix multiplied by number: " << endl << helper;
    try{
        helper = a * b;
        cout << "First matrix multiplied bu second matrix: " << endl << helper;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    helper = a.transp();
    cout << "Transposed matrix" << endl << helper;
    try{
        cout << "Enter number that first matrix will elevate: ";
        int f;
        cin >> f;
        helper = (a ^ f);
        cout << "Elevated matrix:  " << endl << helper;
    } catch(char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void solve_double() {
    int n1, n2, m1, m2;
    cout << "Enter size of first matrix: ";
    cin >> n1 >> m1;
    double k;
    Matr<double> a(n1, m1);
    cout << "Enter elems of first matrix: ";
    cin >> a;
    a[0][0] = 0.1;
    cout << "Enter size of second matrix: ";
    cin >> n2 >> m2;
    Matr<double> b(n2, m2);
    cout << "Enter elems of second matrix: ";
    cin >> b;
    Matr<double> helper;
    try {
        helper = a + b;
        cout << "Sum of to matrix: " << endl << helper;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    cout << "Input a number for multiplication: ";
    cin >> k;
    helper = a * k;
    cout << "First matrix multiplied by number: " << endl << helper;
    try{
        helper = a * b;
        cout << "First matrix multiplied bu second matrix: " << endl << helper;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    helper = a.transp();
    cout << "Transposed matrix: " << endl << helper;
    try{
        cout << "Enter number that first matrix will elevate: ";
        int f;
        cin >> f;
        helper = (a ^ f);
        cout << "Elevated matrix:  " << endl << helper;
    } catch(char* msg) {
        cout << "Error: " << msg << endl;
    }
}

int main() {
    int n1, m1, n2, m2;
    cout << "Enter type of matrix(double or int): ";
    string answer;
    cin >> answer;
    if (answer == "int") {
        solve_int();
    } else {
        solve_double();
    }
}
