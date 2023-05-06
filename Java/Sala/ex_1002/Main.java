import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);    
        double pi = 3.14159;
    
        double raio = s.nextDouble();
        double area = pi * Math.pow(raio,2);
        System.out.printf("A=%.4f\n",area);        

    }
}