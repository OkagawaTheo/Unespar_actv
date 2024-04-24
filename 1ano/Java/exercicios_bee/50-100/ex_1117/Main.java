import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nv = 0;
        double media = 0.0;
        boolean flag = true;
        
        while (flag){
            double n1 = s.nextDouble();

            if (n1 < 0 || n1 > 10){
                System.out.println("nota invalida");
                continue;
            }
            else {
                media += n1;
                nv++;

                if (nv == 2){
                    flag = false;
                }
            }
        }

        System.out.printf("media = %.2f\n",media/2);

    }
}