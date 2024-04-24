import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int T = leitor.nextInt();
        int PA, PB, anos;
        double G1, G2;
        for (int i = 1; i <= T; i++) {
        	anos = 0;
        	PA = leitor.nextInt();
        	PB = leitor.nextInt();
        	G1 = leitor.nextDouble();
        	G2 = leitor.nextDouble();
        	while (PB >= PA) {
        		PA += (PA * G1) / 100;
        		PB += (PB * G2) / 100;
        		anos++;
        		if (anos > 100) {
        			break;
        		}
        	}
        	if (anos > 100) {
        		System.out.println("Mais de 1 seculo.");
        	} else {
        		System.out.println(anos + " anos.");
        	}
        }
    }
    }    

