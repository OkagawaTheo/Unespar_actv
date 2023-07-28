import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		float n1 = s.nextFloat();
		float n2 = s.nextFloat();
		float n3 = s.nextFloat();
		float n4 = s.nextFloat();
		
		float media = (n1 * 2f + n2 * 3f + n3 * 4f + n4 * 1f) / 10;
		
		System.out.printf("Media: %.1f\n", media);
		if (media >= 7f) {
			System.out.println("Aluno aprovado.");
		}
		else if (media < 5f) {
			System.out.println("Aluno reprovado.");
		}
		else {
			System.out.println("Aluno em exame.");
			float notaExame = s.nextFloat();
			System.out.printf("Nota do exame: %.1f\n", notaExame);
			float mediaFinal = (notaExame + media) / 2f;
			if (mediaFinal >= 5f) {
				System.out.println("Aluno aprovado.");
			}
			else {
				System.out.println("Aluno reprovado.");
			}
			System.out.printf("Media final: %.1f\n", mediaFinal);
		}
	}
}