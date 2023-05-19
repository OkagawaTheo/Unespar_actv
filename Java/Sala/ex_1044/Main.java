import java.util.Scanner;

public class Main {
    public static void main(String[] args){ 
        Scanner s = new Scanner(System.in);

        int A, B;
        
        A = s.nextInt();
        B = s.nextInt();
        
        if (B % A == 0 || A % B == 0) {
        System.out.print("Sao Multiplos\n");
        }
        else {
        System.out.print("Nao sao Multiplos\n");
        }
    } 
}
