import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] x = new int[n];
        int menor = 0, posMenor = 0;
        for (int i = 0; i < n; i++) {
        	x[i] = s.nextInt();
        	if (i == 0) {
        		menor = x[i];
        		posMenor = i;
        	} else if (x[i] < menor) {
        		menor = x[i];
        		posMenor = i;
        	}
        }
        System.out.println("Menor valor: " + menor);
        System.out.println("Posicao: " + posMenor);
    }	
}
