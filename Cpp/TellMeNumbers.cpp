#include <iostream>
#include <cmath>

using namespace std;

string considerSmall(int number) {
    switch (number) {
        case 1 : return "one";
        case 2 : return "two";
        case 3 : return "three";
        case 4 : return "four";
        case 5 : return "five";
        case 6 : return "six";
        case 7 : return "seven";
        case 8 : return "eight";
        case 9 : return "nine";
        case 10 : return "ten";
        case 11 : return "eleven";
        case 12 : return "twelve";
        case 13 : return "thirteen";
        case 14 : return "fourteen";
        case 15 : return "fifteen";
        case 16 : return "sixteen";
        case 17 : return "seventeen";
        case 18 : return "eighteen";
        case 19 : return "nineteen";
        case 20 : return "twenty";
        case 30 : return "thirty";
        case 40 : return "forty";
        case 50 : return "fifty";
        case 60 : return "sixty";
        case 70 : return "seventy";
        case 80 : return "eighty";
        case 90 : return "ninety";
        default : return considerSmall(number-(number%10))+"-"+considerSmall(number%10);
    }
}

string considerHundreds(int number) {
    if (number < 100) return considerSmall(number);
    //else if (number == 100) return "hundred";
    else if (number%100 == 0) return considerSmall(number/100)+" hundred";
    else return considerSmall(number/100)+" hundred "+considerSmall(number%100);
}

string considerThousands(int number) {
    if (number < 1000) return considerHundreds(number);
    //else if (number == 1000) return "thousand";
    else if (number%1000 == 0) return considerHundreds(number/1000)+" thousand";
    else return considerHundreds(number/1000)+" thousand "+considerHundreds(number%1000);
}

string considerMillions(int number) {
    if (number < 1000000) return considerThousands(number);
    //else if (number == 1000000) return "million";
    else if (number%1000000 == 0) return considerHundreds(number/1000000)+" million";
    else return considerHundreds(number/1000000)+" million "+considerThousands(number%1000000);
}

string considerBillions(int number) {
    if (number < 1000000000) return considerMillions(number);
    //else if (number == 1000000000) return "billion";
    else if (number%1000000000 == 0) return considerHundreds(number/1000000)+" billion";
    else return considerHundreds(number/1000000000)+" billion "+considerMillions(number%1000000000);
}

string considerPositive(int number) {
    if (number < 100) return considerSmall(number);
    else if (number < 1000) return considerHundreds(number);
    else if (number < 1000000) return considerThousands(number);
    else if (number < 1000000000) return considerMillions(number);
    else return considerBillions(number);
}

string tellMeNumber(int number) {
    if (number < 0) {
        return "minus "+tellMeNumber(abs(number));
    } else if (number == 0) {
        return "zero";
    } else {
        //return to_string(number);
        return considerPositive(number);
    }
}

int main() {
    int number;
    cout << "Enter an integer (up to 2,147,483,647): ";
    cin >> number;
    cout << "The number is " << tellMeNumber(number) << ".\n";
    return 0;
}