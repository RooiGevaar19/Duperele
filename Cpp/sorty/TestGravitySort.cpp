#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

using std::string;
using std::cout;

class Timer
{
    public:
        Timer() { clock_gettime(CLOCK_REALTIME, &beg_); }

        double elapsed() {
            clock_gettime(CLOCK_REALTIME, &end_);
            return end_.tv_sec - beg_.tv_sec +
            (end_.tv_nsec - beg_.tv_nsec) / 1000000000.;
        }

        void reset() { clock_gettime(CLOCK_REALTIME, &beg_); }

    private:
        timespec beg_, end_;
};

int max(int T[], int n)
{
    int s = T[0];
    for (int i = 1; i < n; i++) if (T[i] > s) s = T[i];
    return s;
}

void NaiveGravitySort(int T[], int n)
{
    int y = max(T, n);
    int S[y][n];

    // zbuduj liczydlo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < T[i]; j++) S[j][i] = 1;
        for (int j = T[i]; j < y; j++) S[j][i] = 0;
    }

    // symuluj naiwnie grawitację (oblicz z góry i nadpisz stanem końcowym)
    for (int i = 0; i < y; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (S[i][j] == 1) c++;
        }
        for (int j = n-1; j >= n-c; j--) S[i][j] = 1;
        for (int j = n-c-1; j >= 0; j--) S[i][j] = 0;
    }

    // odczytaj matrycę
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < y; j++) {
            if (S[j][i] == 1) x++;
        }
        T[i] = x;
    }
}

void SimulationalGravitySort(int T[], int n)
{
    int y = max(T, n);
    int S[y][n];

    // zbuduj liczydlo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < T[i]; j++) S[j][i] = 1;
        for (int j = T[i]; j < y; j++) S[j][i] = 0;
    }

    // renderuj grawitacyjne spadki liczb na liczydle
    for (int i = 0; i < y; i++) {
        int flag = 1;
        for (int j = n-1; j >= 0; j--) {
            if (flag == 0) {
                break;
            } else if (S[i][j] == 1) {
                continue;
            } else {
                for (int k = j-1; k >= 0; k--) {
                    if (S[i][k] == 1) {
                        S[i][k] = 0;
                        S[i][j] = 1;
                        break;
                    } else if (k == 0) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
    }

    // odczytaj matrycę
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < y; j++) {
            if (S[j][i] == 1) x++;
        }
        T[i] = x;
    }

}

void fill_random(int* A, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++) A[i] = rand()%(128);
}

void copyTable(int* A, int* B, int n) {
    for (int i = 0; i < n; i++) B[i] = A[i];
}

string printTime(double td) {
    char buffer[50];
    if (fmod(td,60.0) < 10.0) sprintf(buffer, "%02.0f:%02.0f:0%02.6f", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    else sprintf(buffer, "%02.0f:%02.0f:%02.6f\n", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    string s(buffer);
    if (td < 0) s = "-" + s;
    return s;
}

double compare(int n) {
    double td1 = 0.0, td2 = 0.0;
    Timer t;
    int data1[n], data2[n]; 
    fill_random(data1, n);
    copyTable(data1, data2, n);
 
    t.reset();
    NaiveGravitySort(data1, n);
    td1 = t.elapsed();

    t.reset();
    SimulationalGravitySort(data2, n);
    td2 = t.elapsed();
    return td2 - td1;
}

int main()
{
    for (int n = 5; n <= 10240; n *= 2) {
        double res = 0.0;
        for (int i = 0; i < 10; i++) res += compare(n);
        res /= 10;
        cout << n << "\t" << printTime(res) << "\n";
    }    
    return 0;
}
