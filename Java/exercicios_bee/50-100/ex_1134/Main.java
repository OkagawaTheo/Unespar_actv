import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int al=0,gas=0,die=0;
        boolean flag = true;

        while (flag){
            int code = s.nextInt();

            if (code >=1 && code <=3){
                if (code==1)al++;
                else if (code==2)gas++;
                else if(code==3)die++;
            }
            else if (code==4){
                System.out.println("MUITO OBRIGADO");
                System.out.printf("Alcool: %d\n",al);
                System.out.printf("Gasolina: %d\n",gas);
                System.out.printf("Diesel: %d\n",die);
                break;
            }
            
            
        }


    }
}