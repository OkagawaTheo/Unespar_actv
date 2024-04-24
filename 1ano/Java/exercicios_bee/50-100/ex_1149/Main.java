import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int a = s.nextInt();
        int n = s.nextInt();
        int soma=0;

        while (n <= 0){
            n = s.nextInt();
        }

        for (int i=1;i<=n;i++){
            soma += a;
            a++;
        }
        System.out.println(soma);
    }
}
