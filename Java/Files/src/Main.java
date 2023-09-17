import java.io.File;
import java.io.IOException;
import java.nio.Buffer;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

import classes.Aluno;
import classes.Curso;
import classes.Menu;

public class Main {
    public static void main(String[] args) throws IOException {
        int opt;
        Curso cursos[] = new Curso[2];
        cursos[0] = new Curso();
        cursos[0].nome = "Ciência da Computação";
        cursos[1] = new Curso();
        cursos[1].nome = "Administração";

        Menu menu = new Menu();
        Scanner s = new Scanner(System.in);

        File file = new File("/home/okagawatheo/Documents/unespar/Unespar_actv/Java/Files/src/mytxt.txt");

        if (!file.exists()) {
            file.createNewFile();
        }

       FileWriter fw = new FileWriter(file);
       BufferedWriter bw = new BufferedWriter(fw);  

        

        lb_loop: while (true) {
            System.out.println("O que deseja fazer? ");
            menu.show_menu();
            opt = Integer.parseInt(s.nextLine());
            switch (opt) {
                case 1:
                    Aluno al = new Aluno();

                    System.out.println("Digite o nome:");
                    al.nome = s.nextLine();
                    System.out.println("\nDigite o curso dentre as opções:");
                    for (int i=0;i<cursos.length;i++){ 
                        System.out.printf("[%d] - %s\n",i,cursos[i].nome);
                    }
                    
                    int id_curso = -1;
                    boolean flag_curso = false;
                    do {
                        if (flag_curso == true){
                            System.out.println("Digite um curso válido.");
                        }
                        id_curso = Integer.parseInt(s.nextLine());
                        flag_curso = true;
                    } while(id_curso <= 0 || id_curso > cursos.length);
                    al.curso = cursos[id_curso];

                    System.out.println("Digite a idade: ");
                    al.idade = Integer.parseInt(s.nextLine());

                    bw.append(al.getReg());
                    bw.newLine();
                    bw.flush();
                    bw.append(al.getReg());
                    System.out.println("\nAluno criado com sucesso.");
                case 9:
                    s.close();
                    break lb_loop;
            }

        }
    }

    
}
