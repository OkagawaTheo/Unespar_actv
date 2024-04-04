import java.util.Scanner;
public class Main{
public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		double[] w = new double[100];
		
		for (int aux = 0; aux < 100; aux++)
			w[aux]=s.nextDouble();
		
		for (int i = 0; i < 100; i++)
			if (w[i] <= 10.0)
				System.out.printf("A[%d] = %.1f\n",i,w[i]);
}
}