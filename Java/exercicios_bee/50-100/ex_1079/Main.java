import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        for(int i=0;i<n;i++){
            double a = s.nextDouble();
            double b = s.nextDouble();
            double c = s.nextDouble();

            double media = (a*2 + b*3 + c*5) / 10;

            System.out.printf("%.1f\n",media);
        }
    }
}
