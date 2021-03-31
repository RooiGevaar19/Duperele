#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double f(int n) {
    return n*n;
}

double g(int n) {
    return sin(n);
}

double doDirichletConvolution(int k) {
    double sum = 0.0;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            sum += f(i) * g(k/i);
            cout << i << " " << k/i << endl;
        }
    }
    return sum;
}

double doDirichletConvolutionOptimized(int k) {
    double sum = 0.0;
    for (int i = 1; i*i <= k; i++) {
        if (k % i == 0) {
            sum += f(i) * g(k/i);
            if (i*i != k) sum += f(k/i) * g(i);
            cout << i << " " << k/i << endl;
        }
    }
    return sum;
}

int main() {
	cout << doDirichletConvolution(4) << endl;
    cout << doDirichletConvolutionOptimized(4) << endl;
    cout << doDirichletConvolution(250) << endl;
    cout << doDirichletConvolutionOptimized(250) << endl;
	return 0;
}
