import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        // -b + sqrt(delta) / 2*a
        double a = s.nextFloat();
        double b = s.nextFloat();
        double c = s.nextFloat();
        double delta = Math.pow(b,2) - (4*a*c);


        double x1 = (-b + Math.sqrt(delta)) / (2*a);
        double x2 = (-b - Math.sqrt(delta)) / (2*a);

        if (delta > 0 && a != 0){
        System.out.printf("R1 = %.5f\n",x1);        
        System.out.printf("R2 = %.5f\n",x2);        
        } else{
            System.out.println("Impossivel calcular");
        }
        
    
    }

    
}