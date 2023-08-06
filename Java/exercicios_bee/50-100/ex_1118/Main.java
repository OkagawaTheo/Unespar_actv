import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nv = 0;
        double media = 0.0;
        boolean flag = true;
        double n1;
        
        while (flag){
            n1 = s.nextDouble();

            if (n1 < 0 || n1 > 10){
                System.out.println("nota invalida");
                continue;
            }
            else {
                media += n1;
                nv++;

                if (nv == 2){
                    System.out.printf("media = %.2f\n",media/2);

                    System.out.println("novo calculo (1-sim 2-nao)");
                    int repeat = s.nextInt();
                    
                    if (repeat == 1){
                        media = 0;
                        nv = 0;
                        continue;
                    }
                    else if (repeat == 2){
                        flag = false;
                    } 

                    else {
                        System.out.println("novo calculo (1-sim 2-nao)");
                        repeat = s.nextInt();

                        if(repeat == 1){
                            nv = 0;
                            media = 0;
                            continue;
                        }
    
                        else if(repeat == 2){
                            flag = false;
                        }
                    }
                }
            }
        }

        s.close();

    }
}