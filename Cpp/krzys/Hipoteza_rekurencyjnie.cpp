#include <iostream>

using namespace std;

void pause() {
	printf("Press any key to continue...");
	while( getchar() != '\n' ) { } 
	getchar();
}

bool isPrime(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int test(int n, int x) {
    
    if (x > 1 && (isPrime(x)) && (isPrime(n-x))) return x; // znaleźliśmy x z rozkładu x+y = n
    else if (x <= 1) return -1; // hipoteza jest nieprawdziwa
    else return test(n, x-1); // szukaj dalej
}

int main() {
    int n;           
    cin >> n;
    int result = test(n, n-2);
    if (result == -1) {
        cout<<"No primes of x,y found that match n = x + y" << endl;
    } else {
        cout << "n = " << result << " + " << n-result << endl;
    }
    pause();
    return 0;
}