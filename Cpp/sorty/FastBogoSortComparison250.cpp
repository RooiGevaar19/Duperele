#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

long long step = 0;
int count_test = 250;

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

static bool is_sorted(int* data, int x, int y)
{
	while (++x <= y)
		if (data[x] < data[x - 1]) return false;

	return true;
}

static int extract_min(int* data, int x, int y)
{
    int s = x;
    while (++x <= y)
		if (data[x] < data[s]) s = x;
    return s;
}

static void shuffle(int* data, int x, int y)
{
	int temp, rnd;
	for (int i = x; i <= y; ++i)
	{
		srand(time(NULL));
		rnd = x + rand()%(y-x+1);
		temp = data[i];
		data[i] = data[rnd];
		data[rnd] = temp;
	}
}

static void FastBogoSort(int* data, int x, int y)
{
    if (is_sorted(data, x, y)) {
        return;
    }
    else {
        step++;
        if (x == extract_min(data, x, y)) {
            FastBogoSort(data, x+1, y);
        } else {
            shuffle(data, x, y);
            FastBogoSort(data, x, y);
        }
    }
}

void fill_random(int* A, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = rand()%(2048+1);
	}
}

int main()
{
	int n = count_test;
	int data[n];

	printf("Algorithm   | FAST BOGOSORT (Comparison)\n");
	printf("Author      | RooiGevaar19");
	getchar();
	printf("------------+----------------------------------------------\n");
    printf(" n          | Time               | Number of steps\n");
    printf("------------+--------------------+-------------------------\n");

    for (int j = 1; j <= n; j++) {
        step = 0;
        fill_random(data, j);
        Timer t;
	    t.reset();
	    FastBogoSort(data, 0, j);
	    double td = t.elapsed();
        setlocale(LC_ALL,"");
        if (fmod(td,60.0) < 10.0) printf("%12i| %02.0f:%02.0f:0%02.9f |%'25llu\n", j, floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0), step);
        else printf("%12i| %02.0f:%02.0f:%02.9f |%'25llui\n", j, floor(td/3600.0), floor(fmod(td,3600.0)/60.0), fmod(td,60.0), step);
    }
	return 0;
}
