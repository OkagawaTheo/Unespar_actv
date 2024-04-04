import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        double salario, new_salario, money_earned;
        int percentage;
        
        salario = s.nextDouble();

        if (salario >= 0.00 && salario <= 400.00) {
            percentage = 15;
            calc(salario, percentage);
        }
        else if (salario >= 400.01 && salario <= 800.00) {
            percentage = 12;
            calc(salario, percentage);
        }
        else if (salario >= 800.01 && salario <= 1200.00) {
            percentage = 10;
            calc(salario, percentage);
        }
        else if (salario >= 1200.01 && salario <= 2000.00) {
            percentage = 7;
            calc(salario, percentage);
        }else if (salario > 2000.00) {
            percentage = 4;
            calc(salario, percentage);
        }
    }

    private static void calc(double salario, int percentage) {

        double money_earned;
        double new_salario;

        money_earned = salario * (percentage / 100.00);
        new_salario = salario + money_earned;

        System.out.printf("Novo salario: %.2f\n", new_salario
);
        System.out.printf("Reajuste ganho: %.2f\n", money_earned);
        System.out.println("Em percentual: "+ percentage+" %");
    }
}