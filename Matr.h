#ifndef CLASSES_MATR_H
#define CLASSES_MATR_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>

class Matr {
    int n, m;
    vector<vector<T>> matr;
public:
    Matr();
    Matr(vector<vector<T>>);
    Matr(int n_, int m_);
    pair<int, int>  size() const {return {n, m}; };
    Matr operator+(Matr&);
    Matr operator*(T);
    Matr operator*(Matr&);
    Matr operator^(int a);
    Matr<T> transp();
    vector<T>& operator[](int i) { return matr[i]; };
    const vector<T>& operator[](int i) const { return matr[i]; };
    template<typename Type> friend istream& operator>> (istream&, Matr<Type>&);
    template<typename Type> friend ostream& operator<< (ostream&, Matr<Type>&);
};

template<typename T>
Matr<T>::Matr(vector<vector<T>> vect) {
    n = vect.size();
    m = vect[0].size();
    matr = vect;
}

template<typename T>
Matr<T>::Matr() {

}

template<typename T>
Matr<T>::Matr(int n_, int m_) {
    n = n_;
    m = m_;
    vector<vector<T>> res(n, vector<T>(m));
    matr = res;
}

template<typename T>
Matr<T> Matr<T>::operator+(Matr& a) {
    if (a.size().first != n || a.size().second != m)
        throw "Try sum matrix with different sizes";
    vector<vector<T>> res(n, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matr[i][j] + a[i][j];
        }
    }
    return Matr(res);
}

template<typename T>
Matr<T> Matr<T>::operator*(T k) {
    vector<vector<T>> res(n, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res [i][j] = matr[i][j] * k;
        }
    }
    return Matr(res);
}

template<typename T>
T DotProduct (vector<T>& a, vector<T>& b) {
    T sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

template<typename T>
Matr<T> Matr<T>::operator*(Matr<T>& a) {
    if (a.size().first != m)
        throw "Try multiplying with sizes n * m and p * q but m should be equal p";
    vector<vector<T>> res(n, vector<T>(a.size().second));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a.size().second; j++) {
            vector<T> b;
            for (int i = 0; i < a.size().first; i++) {
                b.push_back(a[i][j]);
            }
            res[i][j] = DotProduct(matr[i], b);
        }
    }
    return Matr(res);
}

template<typename T>
Matr<T> pow(Matr<T> matr, int k) {
    if (k == 0) {
        vector<vector<T>> res(matr.size().first, vector<T>(matr.size().second));
        for (int i = 0; i < matr.size().first; i++) {
            for (int j = 0; j < matr.size().second; j++) {
                if (i == j) {
                    res[i][j] = 1;
                } else {
                    res[i][j] = 0;
                }
            }
        }
        return Matr(res);
    } else {
        if (k % 2 == 0) {
            Matr<T> res1 = pow(matr, k / 2);
            return res1 * res1;
        } else {
            return pow(matr, k - 1) * matr;
        }
    }
}

template<typename T>
Matr<T> Matr<T>::operator^(int k) {
    if (n != m)
        throw "Can`t elevate not square matrix";
    return pow(Matr(matr), k);
}

template<typename T>
ostream& operator<<(ostream& out, Matr<T>& a) {
    for (int i = 0; i < a.size().first; i++) {
        for (int j = 0; j < a.size().second; j++) {
            T ex = a[i][j];
            out << ex << ' ';
        }
        out << endl;
    }
    return out;
}

template<typename T>
istream &operator>>(istream& in, Matr<T>& a) {
    for (int i = 0; i < a.size().first; i++) {
        for (int j = 0; j < a.size().second; j++) {
            in >> a[i][j];
        }
    }
    return in;
}

template<typename T>
Matr<T> Matr<T>::transp() {
    vector<vector<T>> res(m, vector<T>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][i] = matr[i][j];
        }
    }
    return Matr(res);
}

#endif //CLASSES_MATR_H
