import java.util.Scanner;
import javax.swing.*;

public class Resistencia {
    Scanner s = new Scanner(System.in);
    int resistencia[];
    int qtdResistencias;
    int totalResistencia;
    int maior;
    int menor;
    
    int[] atribuirValorResistencia(){
        for(int i=0;i<qtdResistencias;i++){
            System.out.printf("Digite o valor da %dº resistencia: ",i+1);
            resistencia[i] = s.nextInt();
        }

        return resistencia;
    }   

    int somarResistencias(){
        for (int i=0;i<qtdResistencias;i++){
            this.totalResistencia += resistencia[i];
        }
        return this.totalResistencia;
    }

    int maiorResistencia(){
        int maior = resistencia[0]; //aux temporario

        for (int i=0;i<qtdResistencias;i++){
            if (resistencia[i] > maior) maior = resistencia[i];
        }
        return maior;
    }

    int menorResistencia(){
        int menor = resistencia[0]; //aux temporario

        for (int i=0;i<qtdResistencias;i++){
            if (resistencia[i] < menor) menor = resistencia[i];
        }
        return menor;
    }

    void showMsg(){
        this.maior = maiorResistencia();
        this.menor = menorResistencia();
        this.totalResistencia = somarResistencias();

        StringBuilder msg = new StringBuilder();
        msg.append("Valores das resistencias: ");
        for (int i=0;i<qtdResistencias;i++){
            msg.append(resistencia[i] + ",");
            }
        msg.append("\nMaior resistência: " + maior);
        msg.append("\nMenor resistência: " + menor);
        msg.append("\nSoma das resistências: " + totalResistencia);
        JOptionPane.showMessageDialog(null,msg.toString());
    }
     
}
