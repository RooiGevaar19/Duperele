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
