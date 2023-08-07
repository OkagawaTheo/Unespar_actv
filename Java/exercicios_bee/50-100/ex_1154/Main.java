import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        double idade,soma=0,count=0;

        while ((idade = s.nextDouble()) > 0){
            soma += idade;
            count++;
        }

        System.out.printf("%.2f\n",soma/count);
        
        
        
    }
}
