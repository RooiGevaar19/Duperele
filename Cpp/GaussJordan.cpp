#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

template <typename T> class MyMatrix {
private:
    vector<vector<T> > matrix;
    unsigned rows;
    unsigned cols;

    T abs(T x) {
        return (x >= 0) ? x : -x;
    }

    public:
        // konstruktory
        MyMatrix(unsigned wiersz, unsigned kolumna, const T& x) {
            matrix.resize(wiersz);
            for (unsigned i=0; i<matrix.size(); i++) {
                matrix[i].resize(kolumna, x);
            }
            rows = wiersz;
            cols = kolumna;
        }
        MyMatrix(const MyMatrix<T>& pom) {
            matrix = pom.matrix;
            rows = pom.getRowCount();
            cols = pom.getColCount();
        }

        // destruktory
        virtual ~MyMatrix() {
            // nic XD
        }

        // przypisanie
        MyMatrix<T>& operator=(const MyMatrix<T>& pom) {
            if (&pom == this) return *this;
            unsigned new_rows = pom.getRowCount();
            unsigned new_cols = pom.getColCount();

            matrix.resize(new_rows);
            for (unsigned i=0; i<matrix.size(); i++) {
                matrix[i].resize(new_cols);
            }

            for (unsigned i=0; i<new_rows; i++) {
                for (unsigned j=0; j<new_cols; j++) {
                    matrix[i][j] = pom(i, j);
                }
            }
            rows = new_rows;
            cols = new_cols;
            return *this;
        }

        // dodawanie macierzy
        MyMatrix<T> operator+(const MyMatrix<T>& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    result(i,j) = this->matrix[i][j] + pom(i,j);
                }
            }
            return result;
        }
        MyMatrix<T>& operator+=(const MyMatrix<T>& pom) {
            unsigned rows = pom.getRowCount();
            unsigned cols = pom.getColCount();
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    this->matrix[i][j] += pom(i,j);
                }
            }
            return *this;
        }
        MyMatrix<T> operator-(const MyMatrix<T>& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    result(i,j) = this->matrix[i][j] - pom(i,j);
                }
            }
            return result;
        }
        MyMatrix<T>& operator-=(const MyMatrix<T>& pom) {
            unsigned rows = pom.getRowCount();
            unsigned cols = pom.getColCount();
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    this->matrix[i][j] -= pom(i,j);
                }
            }
            return *this;
        }
        MyMatrix<T> operator*(const MyMatrix<T>& pom) {
            unsigned rows = pom.getRowCount();
            unsigned cols = pom.getColCount();
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    for (unsigned k=0; k<rows; k++) {
                        result(i,j) += this->matrix[i][k] * pom(k,j);
                    }
                }
            }
            return result;
        }
        MyMatrix<T>& operator*=(const MyMatrix<T>& pom) {
            MyMatrix result = (*this) * pom;
            (*this) = result;
            return *this;
        }
        MyMatrix<T> transpose() {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    result(i,j) = this->matrix[j][i];
                }
            }
            return result;
        }

        // skalary
        MyMatrix<T> operator+(const T& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i = 0; i < rows; i++) {
                for (unsigned j = 0; j < cols; j++) {
                    result(i,j) = this->matrix[i][j] + pom;
                }
            }
            return result;
        }
        MyMatrix<T> operator-(const T& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i = 0; i < rows; i++) {
                for (unsigned j = 0; j < cols; j++) {
                    result(i,j) = this->matrix[i][j] - pom;
                }
            }
            return result;
        }
        MyMatrix<T> operator*(const T& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i = 0; i < rows; i++) {
                for (unsigned j = 0; j < cols; j++) {
                    result(i,j) = this->matrix[i][j] * pom;
                }
            }
            return result;
        }
        MyMatrix<T> operator/(const T& pom) {
            MyMatrix result(rows, cols, 0.0);
            for (unsigned i = 0; i < rows; i++) {
                for (unsigned j = 0; j < cols; j++) {
                    result(i,j) = this->matrix[i][j] / pom;
                }
            }
            return result;
        }

        // mnożenie macierzy przez wektor
        vector<T> operator*(const vector<T>& pom) {
            vector<T> result(pom.size(), 0.0);
            for (unsigned i=0; i<rows; i++) {
                for (unsigned j=0; j<cols; j++) {
                    result[i] = this->matrix[i][j] * pom[j];
                }
            }
            return result;
        }
        vector<T> diagonalVector() {
            vector<T> result(rows, 0.0);
            for (unsigned i=0; i<rows; i++) {
                result[i] = this->matrix[i][i];
            }
            return result;
        }

        // dostań się do poszczególnych elementóœ
        T& operator()(const unsigned& row, const unsigned& col) {
            return this->matrix[row][col];
        }
        const T& operator()(const unsigned& row, const unsigned& col) const {
            return this->matrix[row][col];
        }

        // gettery i settery do kolumn
        void setAt(unsigned row, unsigned col, const T& x) {
            this->matrix[row][col] = x;
        }

        T& getAt(unsigned row, unsigned col) {
            return this->matrix[row][col];
        }

        // zwróć liczbę wierszy/kolumn
        unsigned getRowCount() const {
            return this->rows;
        }
        unsigned getColCount() const {
            return this->cols;
        }

        // wyświetl
        void display() {
            for (int i = 0; i < getRowCount(); i++) {
                cout << "[ ";
                for (int j=0; j < getColCount(); j++) {
                    cout << setw(8) << getAt(i,j);
                }
                cout << " ]" << endl;
            }
        }

        // metoda Gauss-Jordan połowicznego wyboru (tylko wiersze)
        vector<T> solveGauss() {
            int n = getRowCount();
            for (int i = 0; i < n; i++) {
                // znajdź wiersz z maksymalnym elementem
                T maxEl = abs(matrix[i][i]);
                int maxRow = i;
                for (int k = i+1; k < n; k++) {
                    if (abs(matrix[k][i]) > maxEl) {
                        maxEl = abs(matrix[k][i]);
                        maxRow = k;
                    }
                }
                // zamień maksymalny wiersz z obecnym
                for (int k = i; k < n+1; k++) {
                    T pom = matrix[maxRow][k];
                    matrix[maxRow][k] = matrix[i][k];
                    matrix[i][k] = pom;
                }
                // wyprowadź zera przed obecnym wierszem
                for (int k = i+1; k < n; k++) {
                    T c = -matrix[k][i] / matrix[i][i];
                    for (int j = i; j < n+1; j++) {
                        if (i == j) {
                            matrix[k][j] = 0;
                        } else {
                            matrix[k][j] += c * matrix[i][j];
                        }
                    }
                }
            }
            // rozwiąż Ax = B za pomocą powstałej macierzy trójkątnej
            vector<T> x(n);
            for (int i=n-1; i>=0; i--) {
                x[i] = matrix[i][n] / matrix[i][i];
                for (int k=i-1;k>=0; k--) {
                    matrix[k][n] -= matrix[k][i] * x[i];
                }
            }
            return x;
        }
};


int main() {
    MyMatrix<double> mat1(10, 10, 1.0);
    MyMatrix<double> mat2(10, 10, 2.0);

    MyMatrix<double> mat3 = mat1 + mat2;

    mat3.display();
    cout << endl;

    for (int i = 0; (i < mat3.getRowCount() || i < mat3.getColCount()); i++) {
        mat3.setAt(i, i, (double)i);
    }
    mat3(2, 1) = 3.7;
    mat3.display();
    cout << endl;
    getchar();

//    { 2x + 5y = -4
//    {  x - 4y = 11
//
//    x = 3
//    y = -2

    MyMatrix<double> A(2, 3, 0.0);
    A(0, 0)= 2;
    A(0, 1)= 5;
    A(1, 0)= 1;
    A(1, 1)= -4;
    A(0, 2) = -4;
    A(1, 2) = 11;
    A.display();
    vector<double> x(2);
    x = A.solveGauss();
    A.display();
    cout << "[ ";
    for (int i = 0; i < 2; i++) cout << x[i] << " ";
    cout << "]";
    return 0;
}
