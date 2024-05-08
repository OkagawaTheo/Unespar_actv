import javax.swing.JOptionPane;

public class Alunos {

    String notas_string[];
    Float notas[];
    float media;

    Float[] receberNotas(){
        notas_string = new String[5]; 
        notas = new Float[5]; 

        for (int i = 0; i < 5; i++) {
            notas_string[i] = JOptionPane.showInputDialog("Digite a nota do aluno " + (i + 1));
            notas[i] = Float.parseFloat(notas_string[i]); 
        }
        return notas;
    }

    
    void ordenarDecrescente(){
        for (int i = 0; i < notas.length - 1; i++) {
            for (int j = i + 1; j < notas.length; j++) {
                if (notas[i] < notas[j]) {
                    float temp = notas[i];
                    notas[i] = notas[j];
                    notas[j] = temp;
                }
            }
        }
    }

    float calcularMedia() {
        float soma = 0;
        for (Float nota : notas) {
            soma += nota;
        }
        this.media = soma / notas.length;
        return media;
    }
    
    void printar(){
        System.out.printf("Media das notas: %f",this.media);
    }
    
}
