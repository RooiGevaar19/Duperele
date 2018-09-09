#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Fraction
{
    private:
        long long int a, b;

        long long int abs(long long int a) {
            return (a >= 0) ? a : (a*(-1)) ;
        }

        long long int nwd(long long int a, long long int b) {
            long long int xa = abs(a);
            long long int xb = abs(b);
            if (xa == xb) return xa;
            else if (xa > xb) return nwd(xa-xb, xb);
            else return nwd(xa, xb-xa);
        }

    public:
        // konstruktory
        Fraction(){
            a = 0;
            b = 1;
        }

        Fraction (double x) {
            a = DoubleToFraction(x).getNumerator();
            b = DoubleToFraction(x).getDenominator();
        }

        Fraction(int x){
            a = x;
            b = 1;
        }

        Fraction(long int x){
            a = x;
            b = 1;
        }

        Fraction(long long int x){
            a = x;
            b = 1;
        }

        Fraction(int x, int y){
            a = x;
            b = y;
        }

        Fraction(long int x, long int y){
            a = x;
            b = y;
        }

        Fraction(long long int x, long long int y){
            a = x;
            b = y;
        }

        // gettery i settery

        int getNumerator() {
            return a;
        }
        int getDenominator() {
            return b;
        }
        long int getNumerator() {
            return a;
        }
        long int getDenominator() {
            return b;
        }
        long long int getNumerator() {
            return a;
        }
        long long int getDenominator() {
            return b;
        }

        void setNumerator(int x) {
            a = x;
        }
        void setDenominator(int x) {
            b = x;
        }
        void setNumerator(long int x) {
            a = x;
        }
        void setDenominator(long int x) {
            b = x;
        }
        void setNumerator(long long int x) {
            a = x;
        }
        void setDenominator(long long int x) {
            b = x;
        }

        void reduce() {
            long long int x = nwd(a, b);
            a /= x;
            b /= x;
        }
        void multiply(Fraction u){
            a *= u.a;
            b *= u.b;
            reduce();
        }
        void divide(Fraction u){
            a *= u.b;
            b *= u.a;
            reduce();
        }
        void add(Fraction u){
            a = a*u.b+b*u.a;
            b = u.b*b;
            reduce();
        }
        void substract(Fraction u){
            a = a*u.b-b*u.a;
            b = u.b*b;
            reduce();
        }

        //string toString() {
        //    return strcat("", this->a, "/", this->b, "");
        //}
        float to_float() {
            return ((float)(a))/((float)(b));
        }
        double to_double() {
            return ((double)(a))/((double)(b));
        }
        int to_int() {
            return a/b;
        }
        long int to_long() {
            return a/b;
        }
        long long int to_longlong() {
            return a/b;
        }
        string to_string() {
            stringstream ss;
            ss << a << "/" << b;
            string s;
            ss >> s;
            return s;
        }

        // rozszerzone operacje
        Fraction operator=(Fraction pom) {
            if (&pom == this) return *this;
            a = pom.getNumerator();
            b = pom.getDenominator();
            return *this;
        }

        Fraction operator+(Fraction u) {
            Fraction result;
            result.setNumerator(a*u.b+b*u.a);
            result.setDenominator(u.b*b);
            result.reduce();
            return result;
        }

        Fraction operator-(Fraction u) {
            Fraction result;
            result.setNumerator(a*u.b-b*u.a);
            result.setDenominator(u.b*b);
            result.reduce();
            return result;
        }

        Fraction operator*(Fraction u) {
            Fraction result;
            result.setNumerator(a*u.a);
            result.setDenominator(u.b*b);
            result.reduce();
            return result;
        }

        Fraction operator/(Fraction u) {
            Fraction result;
            result.setNumerator(a*u.b);
            result.setDenominator(u.a*b);
            result.reduce();
            return result;
        }

        Fraction& operator*=(const Fraction& u) {
            this->a *= u.a;
            this->b *= u.b;
            this->reduce();
            return *this;
        }
        Fraction& operator/=(const Fraction& u) {
            this->a *= u.b;
            this->b *= u.a;
            this->reduce();
            return *this;
        }
        Fraction& operator+=(const Fraction& u) {
            this->a = a*u.b+b*u.a;
            this->b = u.b*b;
            this->reduce();
            return *this;
        }
        Fraction& operator-=(const Fraction& u) {
            this->a = a*u.b-b*u.a;
            this->b = u.b*b;
            this->reduce();
            return *this;
        }

        Fraction IntToFraction(int input) {
            Fraction result (input);
            return result;
        }

        Fraction LongToFraction(long input) {
            Fraction result (input);
            return result;
        }

        Fraction LongLongToFraction(long long input) {
            Fraction result (input);
            return result;
        }

        Fraction FloatToFraction(float input)
        {
            float integral = floor(input);
            float frac = input - integral;

            const long precision = 1000000000;

            long long gcd_ = nwd(round(frac * precision), precision);

            long long denominator = precision / gcd_;
            long long numerator = (round(frac * precision) / gcd_);


            Fraction result (numerator, denominator);
            result += IntToFraction((long long) integral);
            return result;
        }

        Fraction DoubleToFraction(double input)
        {
            double integral = floor(input);
            double frac = input - integral;

            const long precision = 1000000000;

            long long gcd_ = nwd(round(frac * precision), precision);

            long long denominator = precision / gcd_;
            long long numerator = (round(frac * precision) / gcd_);


            Fraction result (numerator, denominator);
            result += IntToFraction((long long) integral);
            return result;
        }
};

int main()
{
	Fraction a (0.5);
	Fraction b (1, 3);
	a /= b;
	printf("%.2f", a.to_float());
	return 0;
}
