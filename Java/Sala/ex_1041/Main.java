import java.util.Scanner;

public class Main { 
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        double x = s.nextDouble();
        double y = s.nextDouble();

        if (x == 0 && y == 0) {
            System.out.println("Origem");
        } 
        else if (x == 0) {
            System.out.println("Eixo Y");
        } 
        else if (y == 0) {
            System.out.println("Eixo X");
        } 
        else if (y > 0 && x > 0) {
            System.out.println("Q1");
        } 
        else if (y > 0 && x < 0) {
            System.out.println("Q2");
        } 
        else if (y < 0 && x < 0) {
            System.out.println("Q3");
        } 
        else{
            System.out.println("Q4");
        }
    }
    
}