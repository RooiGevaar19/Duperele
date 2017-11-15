public class MyMatrixTest {
    public static void main(String[] args) {
        MyMatrix<double> a = new MyMatrix<double>(2,2);
        a.setAt(0, 0, 3);
        a.setAt(1, 0, 2.5);
        a.setAt(0, 1, -1);
        a.setAt(1, 1, (a.getAt(1,0) + a.getAt(0,1)));

        MyMatrix<double> b = MyMatrix<double>(2,2);
        b.setAt(0, 0, 3);
        b.setAt(1, 0, 2.5);
        b.setAt(0, 1, -1);
        b.setAt(1, 1, (b.getAt(1,0) + b.getAt(0,1)));

        System.out.println();
        System.out.println(a.display());
        System.out.println(b.display());

        a = a.addMatrix(b);
        System.out.println(a.display());
    }
}
