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
    //-------------------------
    public interface MatmaDlaUlomow<A extends Number> {
        public A add(A a, A b);
        public A sub(A a, A b);
        public A mul(A a, A b);
    }

    public class DoubleMaths implements MatmaDlaUlomow<double> {
        public double add(double a, double b) {
            return a+b;
        }
        public double sub(double a, double b) {
            return a-b;
        }
        public double mul(double a, double b) {
            return a*b;
        }
    }

    public class TMaths implements MatmaDlaUlomow<T> {
        public T add(T a, T b) {
            return a+b;
        }
        public T sub(T a, T b) {
            return a-b;
        }
        public T mul(T a, T b) {
            return a*b;
        }
    }

//    public class GenericClass<? extends Number>{
//    public Integer add(? x, ? y){
//        if(x instance of Integer && y instance of Integer){
//            //Do your math with Integer class methods help
//            //Return here
//        }
//        return (Interger)null;
//    }
//}

    //-------------------------
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
                    s.setAt(i, j, MatmaDlaUlomow.add(this.getAt(i,j), B.getAt(i, j)));
                }
            }
        } else {
            s = this;
        }
        return s;
    }
}
