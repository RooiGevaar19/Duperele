#include <iostream>

#define TYP long long int

using namespace std;

void pause() {
	printf("Press ENTER to continue...");
	while( getchar() != '\n' ) { } 
	getchar();
}

bool isPrime(TYP x) {
    if (x < 2) return false;
    for (TYP i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

TYP test(TYP n, TYP x) {
    
    if ((x <= n-1) && (isPrime(x)) && (isPrime(n-x))) return x; // znaleźliśmy x z rozkładu x+y = n
    else if (x >= n-1) return -1; // wtedy hipoteza dla n jest nieprawdziwa
    else if (x == 2) return test(n, x+1); // szukaj dalej (przeskocz na liczby nieparzyste)
    else return test(n, x+2); // szukaj dalej (dalej to tylko szukaj po nieparzystych)
}

int main() {
    TYP n;           
    cin >> n;
    TYP result = test(n, 2);
    if (result == -1) {
        cout<<"No primes of x,y found that match n = x + y" << endl;
    } else {
        cout << n << " = " << result << " + " << n-result << endl;
    }
    pause();
    return 0;
}