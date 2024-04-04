import java.util.Scanner;

public class Main{
	
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        for (int j = 0; j < x; j++) {
        	int N = s.nextInt();
            long anterior = 0, atual = 1, proximo;
	        for (int i=0; i < N; i++) {
	        	proximo = anterior + atual;
	        	anterior = atual;
	        	atual = proximo;
	        }
	        System.out.println("Fib("+ N +") = " + anterior);
        }
    }
	
}