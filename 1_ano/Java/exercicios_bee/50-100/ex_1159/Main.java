import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int x = s.nextInt();
        int sum=0, cont=0;
        
        while (x != 0) {
        	cont = 0;
        	sum = 0;
        	while (cont < 5) {
        		if (x % 2 == 0) {
        			sum += x;
        			cont++;
        		}
        		x++;
        	}
        	System.out.println(sum);
        	x = s.nextInt();
        }
    }
	
}