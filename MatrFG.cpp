#include <iostream>
#include "Matr.h"
#include <string>

using namespace std;

int main() {
    int n1, m1, n2, m2;
    cout << "Which type matrix will conclude double or int?";
    string answer;
    cin >> answer;
    cout << "Enter size of first matrix: ";
    cin >> n1 >> m1;
    if (answer == "double") {
        Matr<double> a(n1, m1);
        double k;
    } else{
        int k;
        Matr<int> a(n1, m1);
    }
    cout << "Enter elems of first matrix: ";
    cin >> a;
    cout << "Enter size of second matrix: ";
    cin >> n2 >> m2;
    if (answer == "double") {
        Matr<double> b(n2, m2);
    } else{
        Matr<int> b(n2, m2);
    }
    cout << "Enter elems of second matrix: ";
    cin >> b;
    try {
        cout << "Sum of to matrix " << a + b << endl;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    cout << "Input a number for multiplication";
    cin >> k;
    cout << "First matrix multiplied by number " << a * k << endl;
    try{
        cout << "First matrix multiplied bu second matrix" << a * b << endl;
    } catch (char* msg) {
        cerr << "Error: " << msg << endl;
    }
    cout << "Transposed matrix" << a.transp() << endl;
    try{
        cout << "Enter number that first matrix will elevate: ";
        int f;
        cin >> f;
        cout << "Elevated matrix " << a ^ f << endl;
    } catch(char* msg) {
        cout << "Error: " << msg << endl;
    }
}
