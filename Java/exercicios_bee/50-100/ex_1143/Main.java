import java.util.Scanner;
// import java.lang.Math;
public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int qtd = s.nextInt();

        for (double i=1;i<qtd+1;i++){
            System.out.printf("%.0f %.0f %.0f\n",i,(i*i),(i*i*i));
        }
    }
}