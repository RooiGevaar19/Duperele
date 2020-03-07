#include <stdio.h>
#include <string.h>

int policz(char x[]) {
    int poziom = 0;
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == '(') poziom++;
        else if (x[i] == ')') poziom--;
        else return -1;
    }
    return poziom;
}
// 0 - napis jest poprawny
// ~0 - napis nie jest poprawny


int main() {
    int n;
    scanf("%i", &n);

    char* T[n];
    for (int i = 0; i < n; i++) {
    	scanf("%s", T[i]);
    }

    for (int i = 0; i < n; i++) {
        if (policz(T[i]) == 0) printf("TRUE\n");
        else printf("FALSE");
    }

    return 0;
}
