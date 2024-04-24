import java.util.Scanner;
import java.util.Locale;

public class Main {
    public static void main(String args[]) {

        Locale.setDefault(Locale.US);
        Scanner s = new Scanner(System.in);

        double x1 = s.nextDouble();
        double y1 = s.nextDouble();
        double x2 = s.nextDouble();
        double y2 = s.nextDouble();

        double distanciaXY = Math.sqrt(Math.pow(x2-x1,2) + Math.pow(y2 - y1,2));


        System.out.printf("%.4f\n",distanciaXY);
    }
}