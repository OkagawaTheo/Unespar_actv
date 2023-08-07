import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int x = s.nextInt();
        int y = s.nextInt();
        int cont = 0;

        for (int i=1;i<y+1;i++){
            System.out.printf("%d ",i);
            cont++;
            if (cont == x){
                System.out.println();
                cont=0;
            }
        }

    }
}