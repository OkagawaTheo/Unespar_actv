import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        // -b + sqrt(delta) / 2*a
        float a = s.nextFloat();
        float b = s.nextFloat();
        float c = s.nextFloat();
    
        double delta = Math.pow(b,2) - (4*a*c);

        double x1 = (-b + Math.sqrt(delta)) / (2*a);
        double x2 = (-b - Math.sqrt(delta)) / (2*a);


        System.out.printf("R1 = %f\n",x1);
        if (delta < 0){
            System.out.println("Impossivel calcular");
        } else{
            System.out.printf("R2 = %f\n",x2);        
        }
    
    }

    
}