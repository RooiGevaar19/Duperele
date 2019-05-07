#include <iostream>

using namespace std;

int main() {
	int x = 8;
	for (int i = 1; i < x; i++) {
		if (x%i == 0) cout << x*i << endl;
		else cout << i << endl;
	}
	return 0;
}
