import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int v[] = new int[12];

        v[0] = s.nextInt();

        for (int i=0;i<10;i++){            
            System.out.printf("N[%d] = %d\n",i,v[i]);
            int aux = v[i] * 2;
            v[i+1] = aux;
        }
    }
}
