#include <cstdio>

int nwd(int a, int b) {
    if (a == b) return a;
    else if (a > b) return nwd(a-b, b);
    else return nwd(a, b-a);
}

int main() {
	printf("%i\n", nwd(36, 24));
	return 0;
}
