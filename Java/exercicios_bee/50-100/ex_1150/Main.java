import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int x = s.nextInt();
        int z = s.nextInt();
        int soma=0,c=0;

        while (z <= x){
            z = s.nextInt();
        }
        while (soma < z){
            soma += x;
            c++;
            x++;
        }
        System.out.println(c);
        
    }
}
