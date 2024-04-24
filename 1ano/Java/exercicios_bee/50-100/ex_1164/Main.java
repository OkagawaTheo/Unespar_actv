import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int x, soma;
        for (int i = 0; i < n; i++) {
        	soma = 0;
        	x = s.nextInt();
        	for (int j = 1; j < x; j++) {
        		if (x % j == 0) soma += j;
        	}
        	if (soma == x) System.out.printf("%d eh perfeito\n",x);
        	else System.out.printf("%d nao eh perfeito\n",x);
        }
    }
}
