import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int qtd = s.nextInt();
        int x = 1;
        for (int i=0;i<qtd;i++){
            for (int k=0;k<3;k++){
                System.out.printf("%d ",x);
                x++;
            }
            System.out.println("PUM");
            x++;
        }
    }
}