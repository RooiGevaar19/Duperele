#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>

int n = 10;

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

void SimulationalGravitySort(int T[], int n)
{
    int y = max(T, n);
    int S[y][n];

    // zbuduj liczydlo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < T[i]; j++) S[j][i] = 1;
        for (int j = T[i]; j < y; j++) S[j][i] = 0;
    }

    //printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; j++) {
            printf("%i", S[j][i]);
        }
        printf("\n");
    }

    // symuluj naiwnie grawitację (oblicz z góry i nadpisz stanem końcowym)
    for (int i = 0; i < y; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (S[i][j] == 1) {
                continue;
            } else {
                for (int k = j-1; k >= 0; k--) {
                    if (S[i][k] == 1) {
                        S[i][k] = 0;
                        S[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }


    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; j++) {
            printf("%i", S[j][i]);
        }
        printf("\n");
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

int main()
{
    double td;

    int data[n]; fill_random(data, n); // dla przykladowych danych zakomentowac

    printf("Algorithm   | GRAVITY SORT (Simulational)\n");
    printf("Author      | RooiGevaar19\n");
	printf("Table       |  \t");
	for (int i = 0; i < n; i++) printf("%7i\t", data[i]);
	getchar();
    printf("------------+----------"); for (int i = 1; i < n; i++) printf("--------"); printf("\n");

    Timer t;
	t.reset();
    SimulationalGravitySort(data, n);
    td = t.elapsed();

    printf("------------+----------"); for (int i = 1; i < n; i++) printf("--------"); printf("\n");
    printf("Result      |  \t");
	for (int i = 0; i < n; i++) printf("%7i\t", data[i]);
	printf("\n");
	if (fmod(td,60.0) < 10.0) printf("Time        |          %02.0f:%02.0f:0%02.6f\n", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    else printf("Time        |          %02.0f:%02.0f:%02.6f\n", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    //printf("Steps       |%18i\n", a-1);
    return 0;
}
