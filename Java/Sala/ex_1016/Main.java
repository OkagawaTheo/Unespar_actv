import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        int x = s.nextInt();

        int temp = (60 * x) / 30;

        System.out.printf("%d minutos\n",temp);
    }
}