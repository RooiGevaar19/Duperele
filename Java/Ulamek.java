public class Ulamek
{
    private int a;
    private int b;

    // konstruktory
    Ulamek(){
        a = 0;
        b = 1;
    }

    Ulamek(int x, int y){
        a = x;
        b = y;
    }

    // gettery/settery
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

    // pomoce
    private int nwd(int a, int b) {
        if (a == b) return a;
        else if (a > b) return nwd(a-b, b);
        else return nwd(a, b-a);
    }

    // operacje
    void skracaj() {
        a /= nwd(a, b);
        b /= nwd(a, b);
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
	int x = a;        
	a = a*u.b+b*u.a;
        b = x*b;
        skracaj();
    }
    void odejmij(Ulamek u){
	int x = a;
        a = a*u.b-b*u.a;
        b = x*b;
        skracaj();
    }

    // reprezentacje
    @Override
    public String toString() {
        return ""+this.a+"/"+this.b+"";
    }
    public float toFloat() {
        return ((float)(a))/((float)(b));
    }
    public double toDouble() {
        return ((double)(a))/((double)(b));
    }
    public int toInt() {
        return a/b;
    }
}
