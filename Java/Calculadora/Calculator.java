import java.util.Scanner;

public class Calculator{
    public static void main(String args[]){

        Scanner s = new Scanner(System.in);
        Operations op = new Operations();
        
        int getOperation = 0;
        double num1, num2;

        System.out.println("\nCalculadora - Bem-vindo!");

        while (getOperation != 5){
            System.out.print("Digite o primeiro número: ");
            num1 = s.nextDouble();

            System.out.println("Digite o segundo número: ");
            num2 = s.nextFloat();
            
            System.out.print("\n[1] - adição\n[2] - subtração\n[3] - multiplicação\n[4] - divisão\n");
            System.out.print("\nDigite a operação: ");
            getOperation = s.nextInt();

            switch(getOperation) {
                case 1: //adição    
                    System.out.printf("Resultado = %f",op.sum(num1,num2));
                    break;
                
                case 2: //subtração
                    System.out.printf("Resultado = %f",op.minus(num1,num2));
                    break;

                case 3: //multiplicação
                    System.out.printf("Resultado = %f",op.mult(num1,num2));
                    break;

                case 4:
                    System.out.printf("Resultado = %f",op.div(num1,num2));
                    break;

                default:
                    System.out.println("Número inválido.");
                    break;
            }
        }
        s.close();      
    }
}

    

