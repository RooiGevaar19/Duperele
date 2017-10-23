public class UlamekTest
{
    public static void main(String[] args) {
        Ulamek a = new Ulamek(1,3);
	a.dodaj(new Ulamek(1,2));
        System.out.println(""+a.toString());
    }
}
