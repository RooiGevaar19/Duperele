public class SorterInt {
    //--------------------------------------------------------------------------
    // pomocnicze
    private static int ExtractMax(int[] T) {
        int s = T[0];
        for (int i = 1; i < T.length; i++) if (T[i] > s) s = T[i];
        return s;
    }

    private static int ExtractMinRange(int[] data, int x, int y) {
        int s = x;
        while (++x <= y)
    		if (data[x] < data[s]) s = x;
        return s;
    }

    private static void ShiftLeftRange(int[] data, int x, int y) {
        int pom = data[x];
        for (int i = x; i < y; i++) data[i] = data[i+1];
        data[y] = pom;
    }

    private static void ShiftingSortE(int[] data, int x, int y) {
        if (IsRangeSorted(data, x, y)) {
            return;
        } else {
            if (x == ExtractMinRange(data, x, y)) {
                ShiftingSortE(data, x+1, y);
            } else {
                ShiftLeftRange(data, x, y);
                ShiftingSortE(data, x, y);
            }
        }
    }

    static private int Partition(int[] tab, int p, int r) {
        int x = tab[p];
        int i = p, j = r, w;
        while (true) {
            while (tab[j] > x)
                j--;
            while (tab[i] < x)
                i++;
            if (i < j) {
                w = tab[i];
                tab[i] = tab[j];
                tab[j] = w;
                i++;
                j--;
            }
            else return j;
        }
    }

    static private void QuickSortE(int[] data, int x, int y) {
        int q;
        if (x < y) {
            q = Partition(data, x, y);
            QuickSortE(data, x, q);
            QuickSortE(data, q+1, y);
        }
    }

    private static boolean IsSorted(int[] data) {
        int count = data.length;
        while (--count >= 1)
    		if (data[count] < data[count - 1]) return false;
    	return true;
    }

    private static boolean IsRangeSorted(int[] data, int x, int y)
    {
    	while (++x <= y)
    		if (data[x] < data[x - 1]) return false;
    	return true;
    }

    private static void Shuffle(int[] data) {
    	int pom, rnd;
    	for (int i = 0; i < data.length; i++) {
    		rnd = (int)(Math.random()*(data.length));
    		pom = data[i];
    		data[i] = data[rnd];
    		data[rnd] = pom;
    	}
    }

    //--------------------------------------------------------------------------
    // sorty

    static public void doBubbleSort(int[] data) {
        for (int j = data.length-1; j >= 0; j--) {
            for (int i = 0; i < j; i++) {
                if (data[i] > data[i+1]) {
                    int pom = data[i];
                    data[i] = data[i+1];
                    data[i+1] = pom;
                }
            }
        }
    }

    static public void doQuickSort(int[] data) {
        QuickSortE(data, 0, data.length-1);
    }

    static public void doGravitySort(int[] T) {
        int n = T.length;
        int y = ExtractMax(T);
        int[][] S = new int[y][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < T[i]; j++) S[j][i] = 1;
            for (int j = T[i]; j < y; j++) S[j][i] = 0;
        }

        for (int i = 0; i < y; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (S[i][j] == 1) c++;
            }
            for (int j = n-1; j >= n-c; j--) S[i][j] = 1;
            for (int j = n-c-1; j >= 0; j--) S[i][j] = 0;
        }

        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < y; j++) {
                if (S[j][i] == 1) x++;
            }
            T[i] = x;
        }
    }

    public static void doBogoSort(int[] data) {
    	while (!IsSorted(data)) {
    		Shuffle(data);
    	}
    }

    public static void doShiftingSort(int[] data) {
        ShiftingSortE(data, 0, data.length-1);
    }


    //--------------------------------------------------------------------------
    // testowy main
//    public static void main(String[] args) {
//        //int[] t = {2, 1, 3, 7};
//        int[] t = {2, 1, 3, 7, 4, 8, 5, 9, 6, 0, 10};
//        SorterInt.doShiftingSort(t);
//        for (int i : t) System.out.print(""+i+"\t");
//        System.out.println();
//    }
}
