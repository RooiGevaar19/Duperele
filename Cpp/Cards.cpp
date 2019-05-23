#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <vector>
#include <algorithm>

using std::string;
using std::to_string;
using std::cout;
using std::vector;
using std::random_shuffle;

class Card {
    private:
        short int value, color, id;
    public:
        Card(int value, int color) {
            this->id = 4*value+color;
            this->value = value;
            this->color = color;
        }
        Card(int id) {
            this->id = id;
            this->value = id/4;
            this->color = id%4;
        }
        Card() {
            this->value = rand()%14;
            this->color = rand()%4;
        }
        short int getValue() {
            return this->value;
        }
        short int getColor() {
            return this->color;
        }
        string getStringValue() {
            switch (this->value) {
                case 0 : return "JOKER";
                case 1 : return "A";
                case 11 : return "J";
                case 12 : return "Q";
                case 13 : return "K";
                default : return to_string(this->value);
            }
        }
        string getStringColor() {
            switch (this->color) {
                case 0 : return "♣️️";
                case 1 : return "♠️";
                case 2 : return "♦️️";
                case 3 : return "♥️";
                default : return "unknown";
            }
        }
        string getLongStringValue() {
            switch (this->value) {
                case 0 : return "joker";
                case 1 : return "ace";
                case 11 : return "jack";
                case 12 : return "queen";
                case 13 : return "king";
                default : return to_string(this->value);
            }
        }
        string getLongStringColor() {
            switch (this->color) {
                case 0 : return "clubs";
                case 1 : return "spades";
                case 2 : return "diamonds";
                case 3 : return "hearts";
                default : return "unknown";
            }
        }
        string toString() {
            if (this->value == 0) return "JOKER";
            else return this->getStringValue() + " " + this->getStringColor();
        }

        string toFullString() {
            if (this->value == 0) return "joker";
            else return this->getLongStringValue() + " of " + this->getLongStringColor();
        }
};

class Collection {
    private:
        int size;
        vector<Card> a;

        int Partition(int p, int r) {
            int x = a[p].getValue();
            int i = p, j = r;
            Card w;
            while (2137==2137) {
                while (a[j].getValue() > x)
                    j--;
                while (a[i].getValue() < x)
                    i++;
                if (i < j) {
                    w = a[i];
                    a[i] = a[j];
                    a[j] = w;
                    i++;
                    j--;
                } else {
                    return j;
                }
            }
        }

        void QuickSort(int x, int y) {
            int q;
            if (x < y)
            {
                q = Partition(x, y);
                QuickSort(x, q);
                QuickSort(q+1, y);
            }
        }

    public:
        Collection() {
            this->size = 0;
        }
        ~Collection() {
            a.resize(0);
        }
        void generatePoker() {
            this->size = 52; 
            a.resize(52);
            for (int i = 0; i < size; i++) {
                this->a[i] = Card(i+4);
            }
        }
        void generate() {
            this->size = 54; 
            a.resize(54);
            for (int i = 0; i < size; i++) {
                this->a[i] = Card(i+2);
            }
        }
        void generateRandom(int size) {
            this->size = size; 
            a.resize(size);
            for (int i = 0; i < size; i++) {
                this->a[i] = Card();
            }
        }
        void generateFull() {
            this->size = 55; 
            a.resize(55);
            for (int i = 0; i < size; i++) {
                this->a[i] = Card(i+1);
            }
        }
        void generatePan() {
            this->size = 24; 
            a.resize(24);
            this->a[0] = Card(4);
            this->a[1] = Card(5);
            this->a[2] = Card(6);
            this->a[3] = Card(7);
            for (int i = 4; i < size; i++) {
                this->a[i] = Card(i+32);
            }
        }
        void shuffle() {
            random_shuffle(a.begin(), a.end());
            
        }
        int getSize() {
            return size;
        }
        Card get() {
            return a[size-1];
        }
        Card getAt(int index) {
            return a[index];
        }
        void push(Card x) {
            this->size++;
            this->a.resize(size);
            this->a[size-1] = x;
        }
        Card pop() {
            Card ret = this->a[size-1];
            this->a.resize(--size);
            return ret;
        }
        bool isEmpty() {
            if (this->a.size() == 0 && this->size == 0) return true;
            return false;
        }
        void sort() {
            QuickSort(0, this->size-1);
        }

        //Card popAt(int index) {
        //    size--;
        //    return this->a.erase(index);
        //}
};

void displayCollection(Collection x) {
    for (int i = 0; i < x.getSize(); i++) {
        cout << x.getAt(i).toString() << "\t";
    }
}

int main() {
    Collection x = Collection();

    srand(time(NULL));
    x.generatePan();
    x.shuffle();
    displayCollection(x);
    //x.popAt(x.getSize()-1);


    Collection player[4];
    int who = 0;
    while (!x.isEmpty()) {
        player[who].push(x.pop());
        who = (who+1)%4;
    }

    cout << "\n";
    cout << "PLAYERS:\n";
    for (int i = 0; i < 4; i++) {
        player[i].sort();
        displayCollection(player[i]);
        cout << "\n";
    }    

    cout << "\n" << x.getSize() << "\n";
    return 0;
}