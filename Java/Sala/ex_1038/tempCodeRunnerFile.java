import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.println("Digite a quantidade: ");
        int qnt = s.nextInt();

        System.out.println("Digite o código: ");
        int cod = s.nextInt();

    switch (cod) {
        case 1:
            System.out.printf("Total: R$%.2f\n",(qnt * 4.00));
            break;
        case 2:
            System.out.printf("Total: R$%.2f\n",(qnt * 4.5));
            break;
        case 3:
            System.out.printf("Total: R$%.2f\n",(qnt * 5.00));
            break;
        case 4:
            System.out.printf("Total: R$%.2f\n",(qnt * 2.00));
            break;
        case 5:
            System.out.printf("Total: R$%.2f\n",(qnt * 1.50));
            break;
    }



    }
}