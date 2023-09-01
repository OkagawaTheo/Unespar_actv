import java.util.Scanner;

public class Teste{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        Aluno aluno1 = new Aluno();

        System.out.println("Digite um nome para o aluno: ");
        aluno1.nome = s.nextLine();

        System.out.println("Digite a idade: ");
        aluno1.idade = Integer.parseInt(s.nextLine());
        
        System.out.println("Digite o curso: ");
        aluno1.curso = s.nextLine();

        aluno1.estudar();

    }
}
