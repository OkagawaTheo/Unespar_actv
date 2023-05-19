import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        double temp = s.nextDouble();
        double vm = s.nextDouble();

        double tot_litros = (temp * vm) / 12;

        System.out.printf("%.3f\n",tot_litros);
    }
}