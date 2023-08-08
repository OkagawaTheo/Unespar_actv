import java.util.Scanner;

public class Main{
	
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        double x = s.nextDouble();
        double[] n = new double[100];
        n[0] = x;
        for (int i = 1; i < n.length; i++) {
        	n[i] = n[i - 1] / 2.0000;
        }
        for (int i = 0; i < n.length; i++) {
        	System.out.println(String.format("n[" + i + "] = %.4f", n[i]));
        }
    }
	
}