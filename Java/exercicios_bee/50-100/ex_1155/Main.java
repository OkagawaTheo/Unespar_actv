import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double n = 1;

        for (int i=2;i<=100;i++){
            n += 1.00/i;
        }
        System.out.printf("%.2f\n",n);
        
    }
}
