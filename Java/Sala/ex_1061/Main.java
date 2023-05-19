import java.util.Scanner;

public class Main {
    public static void main(String args[]){

        Scanner s = new Scanner(System.in);
        String string;
        int day_i, day_f, hour_i, hour_f, minute_i, minute_f, second_i, second_f;
        int day = 0, hour = 0, minute = 0, second = 0;
        boolean bool_h = false, bool_m = false, bool_s = false;



        string =s.next();
        day_i =s.nextInt();


        hour_i = s.nextInt();
        string = s.next();
        minute_i = s.nextInt();
        string = s.next();
        second_i = s.nextInt();


        string = s.next();
        day_f = s.nextInt();


        hour_f = s.nextInt();
        string = s.next();
        minute_f = s.nextInt();
        string = s.next();
        second_f = s.nextInt();

        if(hour_i > hour_f)
        bool_h = true;

        if(minute_i > minute_f)
        bool_m = true;

        if(second_i > second_f)
        bool_s = true;

        while(day_i != day_f)
        {
            day++;
            day_i++;
        }

        while(hour_i != hour_f)
        {
            hour++;
            hour_i++;
            if(hour_i == 25)
            hour_i = 1;
        }

        while(minute_i != minute_f)
        {
            minute++;
            minute_i++;
            if(minute_i == 61)
            minute_i = 1;
        }

        while(second_i != second_f)
        {
            second++;
            second_i++;
            if(second_i == 61)
            second_i = 1;
        }

        if(bool_h == true)
        day--;

        if(bool_m == true)
        hour--;

        if(bool_s == true)
        minute--;

        System.out.printf(day+" dia(s)\n");
        System.out.print(hour+" hora(s)\n");
        System.out.print(minute+" minuto(s)\n");
        System.out.print(second+" segundo(s)\n");

    }
 
}
