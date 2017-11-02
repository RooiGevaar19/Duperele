#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#define MLD 1000000000.0

struct timespec tp0, tp1;

int a = 0;

int n = 10; // losowe dane - liczba elementow
//int n = 10; int data[10] = {2, 1, 3, 7, 1, 4, 8, 8, 5, 6}; // przykladowe dane


// stoper

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

// quicksort

int Partition(int tab[], int p, int r)
{
    int x = tab[p];
    int i = p, j = r, w;
    while (true)
    {
        while (tab[j] > x)
            j--;
        while (tab[i] < x)
            i++;
        if (i < j)
        {
            w = tab[i];
            tab[i] = tab[j];
            tab[j] = w;
            i++;
            j--;
        }
        else return j;
    }
}

static void QuickSort(int* data, int x, int y)
{
    printf("\n%12i|\t", a);
    for (int i = 0; i < n; i++) printf("%7i\t", data[i]);
    //printf("\n");
    a++;

    int q;
    if (x < y)
    {
        q = Partition(data, x, y); printf("    partition %i", q);
        QuickSort(data, x, q);
        QuickSort(data, q+1, y);
    }
}

void fill_random(int* A, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		//A[i] = rand()%(2048+1) - 1024;
        A[i] = rand()%(2048+1);
	}
}

int main()
{
    double td;

    int data[n]; fill_random(data, n); // dla przykladowych danych zakomentowac

    printf("Algorithm   | QUICK SORT (Partitioning LR)\n");
    printf("Author      | RooiGevaar19\n");
	printf("Table       |  \t");
	for (int i = 0; i < n; i++) printf("%7i\t", data[i]);
	getchar();
    printf("------------+----------"); for (int i = 1; i < n; i++) printf("--------"); //printf("\n");

    Timer t;
	t.reset();
    QuickSort(data, 0, n-1);
    td = t.elapsed();

    printf("\n------------+----------"); for (int i = 1; i < n; i++) printf("--------"); printf("\n");
    printf("Result      |  \t");
	for (int i = 0; i < n; i++) printf("%7i\t", data[i]);
	printf("\n");
	if (fmod(td,60.0) < 10.0) printf("Time        |          %02.0f:%02.0f:0%02.6f\n", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    else printf("Time        |          %02.0f:%02.0f:%02.6f\n", floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0));
    printf("Steps       |%18i\n", a-1);
	return 0;
}
