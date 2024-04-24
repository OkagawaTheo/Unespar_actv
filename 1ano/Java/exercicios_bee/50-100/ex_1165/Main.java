import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int N = s.nextInt();
        int x, cont;
        for (int i = 0; i < N; i++) {
        	cont = 0;
        	x = s.nextInt();
        	for (int j = 2; j < x; j++) {
        		if (x % j == 0) cont++;
        	}
        	if (cont == 0) System.out.printf("%d eh primo\n",x);
        	else System.out.printf("%d nao eh primo\n",x);
        }
    }
    }
