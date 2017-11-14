#include <cstdio>
#include <cstring>
#include <iostream>

class Ulamek
{
    private:
    int a, b;

    int abs(int a) {
        return (a >= 0) ? a : (a*(-1)) ;
    }

    int nwd(int a, int b) {
        a = abs(a);
        b = abs(b);
        if (a == b) return a;
        else if (a > b) return nwd(a-b, b);
        else return nwd(a, b-a);
    }

    public:
    Ulamek(){
        a = 0;
        b = 1;
    }

    Ulamek(int x, int y){
        a = x;
        b = y;
    }

    int getLicznik(){
        return a;
    }
    int getMianownik(){
        return b;
    }
    void setLicznik(int x){
        a = x;
    }
    void setMianownik(int x){
        b = x;
    }

    void skracaj() {
        int x = nwd(a, b);
        a /= x;
        b /= x;
    }
    void mnoz(Ulamek u){
        a *= u.a;
        b *= u.b;
        skracaj();
    }
    void dziel(Ulamek u){
        a *= u.b;
        b *= u.a;
        skracaj();
    }
    void dodaj(Ulamek u){
        a = a*u.b+b*u.a;
        b = u.b*b;
        skracaj();
    }
    void odejmij(Ulamek u){
        a = a*u.b-b*u.a;
        b = u.b*b;
        skracaj();
    }

    //string toString() {
    //    return ""+this.a+"/"+this.b+"";
    //}
    float toFloat() {
        return ((float)(a))/((float)(b));
    }
    double toDouble() {
        return ((double)(a))/((double)(b));
    }
    int toInt() {
        return a/b;
    }
};

int main() {
	Ulamek a (1, 2);
	Ulamek b (1, 3);
	a.dziel(b);
	printf("%.2f", a.toFloat());
	return 0;
}
