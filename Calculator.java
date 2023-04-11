import java.util.Scanner;

public class Calculator{
    public static void main(String args[]){

        Scanner s = new Scanner(System.in);
        Operations op = new Operations();


        int getOperation = 0;
        double num1, num2;


        System.out.println("\nCalculadora - Bem-vindo!");

        while (getOperation != 5){
            System.out.print("\nDigite o primeiro número: ");
            num1 = s.nextDouble();

            System.out.println("\nDigite o segundo número: ");
            num2 = s.nextFloat();
            
            System.out.print("\n[1] - adição\n[2] - subtração\n[3] - multiplicação\n[4] - divisão\n");
            System.out.print("\nDigite a operação: ");
            getOperation = s.nextInt();
            

            switch(getOperation) {
                case 1: //adição    
                    op.sum(num1,num2);
                    break;
                
                case 2: //subtração
                    op.minus(num1,num2);
                    break;

                case 3: //multiplicação
                    op.mult(num1,num2);
                    break;

                case 4:
                    op.div(num1,num2);
                    break;

                default:
                    System.out.println("Número inválido.");
                    break;
            }
        }
           
    }

    private static class Operations {
        
         double num1;
         double num2;
        
        private void sum(double num1, double num2){ //sum
            System.out.printf("\n%.2f + %.2f = %.2f\n",num1,num2,num1+num2);
        }

        private void minus(double num1, double num2){ //minus
            System.out.printf("\n%.2f - %.2f = %.2f\n",num1,num2,num1-num2);
        }

        private void mult(double num1, double num2){ //mult
            System.out.printf("\n%.2f x %.2f = %.2f\n",num1,num2,num1*num2);
        }

        private void div(double num1, double num2){
            System.out.printf("\n%.2f / %.2f = %.2f\n",num1,num2,num1/num2);
        }

    }
}

    

