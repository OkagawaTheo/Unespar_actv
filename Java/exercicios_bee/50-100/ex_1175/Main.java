import java.util.Scanner;

public class Main{
public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    double[] a = new double[100];
    for (int i=0; i < a.length; i++) {
        a[i] = s.nextDouble();
    }
    for (int i=0; i < a.length; i++) {
        if (a[i] <= 10) System.out.println(String.format("a["+ i +"] = %.1f" , a[i]));
    }
}
}