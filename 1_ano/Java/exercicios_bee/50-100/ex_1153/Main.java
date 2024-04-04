import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int fat = 1;
        for (int i=1;i<n+1;i++){
            fat *= i;
            
        }
        System.out.println(fat);
    }
}
