#include <eigen3/Eigen/Dense>
#include <iostream>
#include <iomanip>

using namespace Eigen;
using namespace std;

template<typename typek> class MyMatrix
{
    private:
        int row, col;   // x - rows, y - columns
        //typek** data;
        typek **data = new typek*[col];
    public:
        MyMatrix(int x, int y) {
            //data = new typek[x][y];
            for(int i = 0; i < y; i++) {
                data[i] = new typek[x];
                row = x;
                col = y;
            }
        }
        ~MyMatrix() {
            //delete data;
            cout << "destructing" << endl;
            for(int i = 0; i < col; i++) {
                delete [] data[i];
            }
            delete [] data;
            cout << "destruction" << endl;
        }

        typek getAt(int x, int y) {
            return data[x][y];
        }

        void setAt(int x, int y, typek value) {
            data[x][y] = value;
        }

        int getColCount() {
            return col;
        }

        int getRowCount() {
            return row;
        }

        void display() {
            for (int j = 0; j < getColCount(); j++) {
                cout << "[ ";
                for (int i = 0; i < getRowCount(); i++) {
                    cout << setw(16) << getAt(i, j);
                }
                cout << " ]\n";
            }
        }

        void addMatrix(MyMatrix<typek> B) {
            if ((getColCount() == B.getColCount())&&(getRowCount() == B.getRowCount())) {
                for (int j = 0; j < getColCount(); j++) {
                    for (int i = 0; i < getRowCount(); i++) {
                        this->setAt(i, j, (this->getAt(i,j) + B.getAt(i, j)));
                    }
                }
            }
        }
};

int main()
{
    // eigen
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    cout << "Here is the matrix m:\n" << m << endl;
    VectorXd v(2);
    v(0) = 4;
    v(1) = v(0) - 1;
    cout << "Here is the vector v:\n" << v << endl;
    cout << endl;

    // mymatrix;
    MyMatrix<double> a(2,2);
    a.setAt(0, 0, 3);
    a.setAt(1, 0, 2.5);
    a.setAt(0, 1, -1);
    a.setAt(1, 1, (a.getAt(1,0) + a.getAt(0,1)));

    MyMatrix<double> b(2,2);
    b.setAt(0, 0, 3);
    b.setAt(1, 0, 2.5);
    b.setAt(0, 1, -1);
    b.setAt(1, 1, (b.getAt(1,0) + b.getAt(0,1)));

    getchar();
    cout << "A:" << endl;
    a.display();
    cout << "B:" << endl;
    b.display();

    getchar();
    cout << "A = A+B:" << endl;
    a.addMatrix(b);
    a.display();

    getchar();
    return 0;
}
