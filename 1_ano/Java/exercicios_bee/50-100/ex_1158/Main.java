import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int x, y;
        int sum=0, cont=0;

        for (int i = 0; i < n; i++) {
        	cont = 0;
        	sum = 0;
        	x = s.nextInt();
        	y = s.nextInt();
        	while (cont < y) {
        		if (x % 2 != 0) {
        			sum += x;
        			cont++;
        		}
        		x++;
        	}
        	System.out.println(sum);
    }
}
}