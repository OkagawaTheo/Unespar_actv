import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int x = 60;
        int minute = n / x;
        int second = n % x;
        int hour = minute / x;
        minute = minute % x;
        System.out.println(hour + ":" + minute + ":" + second);
    }
}