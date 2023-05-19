import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double a, b, c;
        double per, area_trap;

        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();

        if ((a + b) > c && (b + c) > a && (c + a) > b) { per = a + b + c;
            System.out.printf("Perimetro = %.1f\n", per);
        } else {
            area_trap = ((a + b) / 2) * c;
            System.out.printf("Area = %.1f\n", area_trap);
        }
    }
}