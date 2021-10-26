#include <iostream>

using std::cout;
using std::endl;

struct coords {
    int x;
    int y;
};

//int length(int* v) {
//    return sizeof(v)/sizeof(v[0]);
//}

coords dejKoordyXY(int* v) {
    coords res;
    res.x = v[0];
    res.y = v[1];
    return res;
}

int main() {
    int a[4] = {2, 1, 3, 7};
    coords c = dejKoordyXY(a); 
	cout << "(" << c.x << ", " << c.y << ")" << endl;
	return 0;
}
