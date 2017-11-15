public class MyMatrix<T extends Number>
{
    private int row;
    private int col;
    private T[][] data;

    public MyMatrix(int x, int y) {
        //data = new T[x][y];
        data = (T[][]) new Number[x][y];
        this.row = x;
        this.col = y;
    }


    public T getAt(int x, int y) {
        return data[x][y];
    }

    public void setAt(int x, int y, T value) {
        data[x][y] = value;
    }

    public int getColCount() {
        return col;
    }

    public int getRowCount() {
        return row;
    }

    public String toStringMatrix() {
        String str = "";
        for (int j = 0; j < getColCount(); j++) {
            str += "[";
            for (int i = 0; i < getRowCount(); i++) {
                str += getAt(i, j)+"\t";
            }
            str += " ]\n";
        }
        return str;
    }

    public MyMatrix<T> addMatrix(MyMatrix<T> B) {
        MyMatrix<T> s = new MyMatrix<T>(this.getRowCount(), this.getColCount());
        if ((getColCount() == B.getColCount())&&(getRowCount() == B.getRowCount())) {
            for (int j = 0; j < getColCount(); j++) {
                for (int i = 0; i < getRowCount(); i++) {
                    s.setAt(i, j, (this.getAt(i,j) + B.getAt(i, j)));
                }
            }
        } else {
            s = this;
        }
        return s;
    }
}
