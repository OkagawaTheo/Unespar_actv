import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int n;
        int maior = 0;
        int pos = 0;

        for (int i=0;i<100;i++){
            n = s.nextInt();
            if (n > maior){
                maior = n;
                pos = i;
            }
        }
    System.out.printf("%d\n",maior);
    System.out.printf("%d\n",pos+1);
}}