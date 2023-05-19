import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int start_hour, start_minute, end_hour, end_minute;

        int hour = 0, minute = 0;

        start_hour = s.nextInt();
        start_minute = s.nextInt();
        end_hour = s.nextInt();
        end_minute = s.nextInt();


        if (start_hour >= 0 && start_hour <= 24 && end_hour >= 0
                && end_hour <= 24 && start_minute >= 0 && start_minute <= 60
                && end_minute >= 0 && end_minute <= 60) {
            
                if (end_minute > start_minute) {
                    minute = end_minute - start_minute;
                } else if (end_minute < start_minute) {
                    minute = end_minute - start_minute + 60;
                    end_hour = end_hour - 1;
                }
                if (end_hour >= start_hour) {
                    hour = end_hour - start_hour;
                } else if (end_hour < start_hour) {
                    hour = end_hour - start_hour + 24;
                }
                if (hour == 0 && minute == 0) {
                    hour = 24;
                }
        }
        System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)"hour,minute);
    }
}