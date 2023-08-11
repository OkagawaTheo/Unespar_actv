import java.util.Scanner;

public class Medias {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.println("Informe a quantidade de alunos: ");
        int qtd = s.nextInt();

        double notas[] = new double[qtd];
        
        for(int i=0; i<notas.length;i++){
            System.out.println("Informe a " + (i+1) + "º nota:");
            notas[i] = s.nextDouble();
        }

        double soma = 0.0;
        for(int i=0; i<notas.length; i++){
            soma += notas[i];
        }
        
        System.out.printf("A média é %.2f\n",(soma/notas.length));
    }
}