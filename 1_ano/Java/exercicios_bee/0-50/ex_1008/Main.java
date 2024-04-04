import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        int num_func = s.nextInt();
        int num_horas = s.nextInt();
        float valor_hora = s.nextFloat();

        System.out.printf("NUMBER = %d\n",num_func);
        System.out.printf("SALARY = U$ %.2f\n",(num_horas * valor_hora));
    }
}