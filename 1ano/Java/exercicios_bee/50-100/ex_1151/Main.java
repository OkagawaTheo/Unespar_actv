import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int at = 1;
        int ant = 0;
        int prox;
        int n = s.nextInt();

        for (int i=1;i<=n;i++){

            if (i == n){
                System.out.println(ant);
            }
            else{
                System.out.print(ant + " "); //printf nao é aceito
                prox = ant + at;
                ant = at;
                at = prox;
            }
        }
    }
}
