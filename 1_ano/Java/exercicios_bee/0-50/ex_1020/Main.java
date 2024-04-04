import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int n = s.nextInt();
        int years = n/365;
        int months = n%365;
        int days = months%30;
        months = months/30;
        System.out.println(years+" ano(s)\n"+months+" mes(es)\n"+days+" dia(s)");
    }
}