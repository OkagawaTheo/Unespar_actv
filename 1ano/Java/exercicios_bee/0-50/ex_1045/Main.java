import java.util.Scanner;

public class Main {
	
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
        
		double A = s.nextDouble();
		double B = s.nextDouble();
		double C = s.nextDouble();
		double x;
		
		if (B > A && B > C) {
			x = A;
			A = B;
			B = x;
		} else if (C > A) {
			x = A;
			A = C;
			C = x;
		}		
		if (A >= (B + C)) { 
			System.out.println("NAO FORMA TRIANGULO");
		} else {
			if (A*A == (B*B) + (C*C)) System.out.println("TRIANGULO RETANGULO");
			if (A*A > (B*B) + (C*C)) System.out.println("TRIANGULO OBTUSANGULO");
			if (A*A < (B*B) + (C*C)) System.out.println("TRIANGULO ACUTANGULO");
			if (A == B && A == C) System.out.println("TRIANGULO EQUILATERO");
			if ((A == B && A != C) || (A == C && A != B) || (B == C && B != A)) System.out.println("TRIANGULO ISOSCELES");
		}
	}
	
}