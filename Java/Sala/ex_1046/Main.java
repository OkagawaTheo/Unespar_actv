import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int start, end, duration = 0;

        start = s.nextInt();
        end = s.nextInt();

        if (start <= 24 && end <= 24 && start >= 0 && end >= 0) {
            if (end > start) {
                duration = end - start;
            } else if (end < start || end == start) {
                duration = (end - start) + 24;
            }
            System.out.printf("O JOGO DUROU %d HORA(S)\n",duration);
        }
    }
}