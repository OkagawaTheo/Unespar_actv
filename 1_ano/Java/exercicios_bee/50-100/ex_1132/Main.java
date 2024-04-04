import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int x,y,soma=0;
        x = s.nextInt();
        y = s.nextInt();

        if (x>y){
            for (int i=y;i<=x;i++){
                if (i % 13 != 0) soma += i;
            }
        }

        if (y>x){
            for (int i=x;i<=y;i++){
                if (i % 13 != 0) soma += i;
            }
        }
        
        System.out.printf("%d\n",soma);

    }
}