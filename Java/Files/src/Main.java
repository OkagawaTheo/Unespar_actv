import classes.Aluno;
import classes.Menu;

import java.util.Scanner;
import java.io.File;

public class Main {
    public static void main(String[] args) {
        Aluno al = new Aluno();
        Menu menu = new Menu();
        Scanner s = new Scanner(System.in);
        int opt;

        File file = new File(System.getProperty("java.class.path") + "/mytext.txt");

        System.out.println("O que deseja fazer? ");
        menu.show_menu();
        opt = Integer.parseInt(s.nextLine());

        lb_loop:
        while (true){
            switch (opt){
                case 9:
                    break lb_loop;
            }

        }
    }

}




