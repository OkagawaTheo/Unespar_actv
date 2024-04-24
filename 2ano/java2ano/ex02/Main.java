import java.util.Scanner;


public class Main{
    public static void main(String args[]){
        Resistencia r = new Resistencia();
        Scanner s = new Scanner(System.in);

        System.out.println("Quantas resistencias quer cadastrar? ");
        r.qtdResistencias = s.nextInt();
        r.resistencia = new int[r.qtdResistencias];

        r.atribuirValorResistencia();
        
        r.showMsg();

    }
}