import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        int n; //inicializado antes pra resolver bug do beecrowd de tempo limite
        Scanner s = new Scanner(System.in);
        

       while ((n=s.nextInt()) != 0){
            for (int i=1;i<n+1;i++){
                System.out.printf("%d ",i);
            }
            System.out.println();
       }
}}