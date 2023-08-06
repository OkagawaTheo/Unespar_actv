import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int qtd = s.nextInt();

        for (int i=0;i<qtd;i++){
            double x = s.nextDouble();
            double y = s.nextDouble();
            
            if (y != 0){
                System.out.printf("%.1f\n",x/y);
            }
            else {
                System.out.println("divisao impossivel");
            }

            
        }
    }
}