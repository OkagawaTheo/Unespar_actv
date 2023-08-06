import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        int x,y;

        while (((x = s.nextInt())!= 0) && ((y=s.nextInt())!= 0)){
            if (x > 0 && y > 0){
                System.out.println("primeiro");
            }
            else if (x > 0 && y < 0){
                System.out.println("quarto");
            }
            else if (x < 0 && y < 0){
                System.out.println("terceiro");
            }
            else {
                System.out.println("segundo");
            }
        }
    }
}

 