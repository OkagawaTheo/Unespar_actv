import javax.swing.*;

public class Main {
    public static void main(String args[]) {
        String password;
        String login;
        int tentativas = 3;

        do {
            login = JOptionPane.showInputDialog("Login: ");
            password = JOptionPane.showInputDialog("Password: ");

            if (password.equals("java8")) {
                boolean flag = true;
            } else {
                tentativas--;
                if (tentativas > 0) {
                    JOptionPane.showMessageDialog(null, "Login ou senha incorretos. Tentativas restantes: " + tentativas);
                } else {
                    JOptionPane.showMessageDialog(null, "Número máximo de tentativas excedido.");
                    System.exit(0);
                }
            }
        } while (!password.equals("java8") && (!login.equals("java8")) && tentativas < 3);
        
        JOptionPane.showMessageDialog(null, "Logado com sucesso");
    }
}
