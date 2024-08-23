import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MovimentoCircular {

    private static final double k_e = 8.99e9;

    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculadora de Carga Elétrica");
        frame.setSize(500, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        frame.getContentPane().setBackground(new Color(30, 30, 30));

        JLabel tituloLabel = new JLabel("Cálculo de Carga Elétrica", JLabel.CENTER);
        tituloLabel.setBounds(50, 10, 400, 40);
        tituloLabel.setForeground(new Color(255, 255, 0));
        tituloLabel.setFont(new Font("Arial", Font.BOLD, 22));
        frame.add(tituloLabel);

        JLabel massaLabel = new JLabel("Massa do objeto (kg):");
        massaLabel.setBounds(50, 60, 200, 25);
        massaLabel.setForeground(Color.WHITE);
        massaLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(massaLabel);

        JTextField massaCampo = new JTextField();
        massaCampo.setBounds(250, 60, 150, 25);
        massaCampo.setBackground(new Color(60, 63, 65));
        massaCampo.setForeground(Color.WHITE);
        frame.add(massaCampo);

        JLabel velocidadeLabel = new JLabel("Velocidade (m/s):");
        velocidadeLabel.setBounds(50, 100, 200, 25);
        velocidadeLabel.setForeground(Color.WHITE);
        velocidadeLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(velocidadeLabel);

        JTextField velocidadeCampo = new JTextField();
        velocidadeCampo.setBounds(250, 100, 150, 25);
        velocidadeCampo.setBackground(new Color(60, 63, 65));
        velocidadeCampo.setForeground(Color.WHITE);
        frame.add(velocidadeCampo);

        JLabel raioLabel = new JLabel("Raio da órbita (m):");
        raioLabel.setBounds(50, 140, 200, 25);
        raioLabel.setForeground(Color.WHITE);
        raioLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(raioLabel);

        JTextField raioCampo = new JTextField();
        raioCampo.setBounds(250, 140, 150, 25);
        raioCampo.setBackground(new Color(60, 63, 65));
        raioCampo.setForeground(Color.WHITE);
        frame.add(raioCampo);

        JLabel cargaLabel = new JLabel("Carga do objeto (C):");
        cargaLabel.setBounds(50, 180, 200, 25);
        cargaLabel.setForeground(Color.WHITE);
        cargaLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(cargaLabel);

        JTextField cargaCampo = new JTextField();
        cargaCampo.setBounds(250, 180, 150, 25);
        cargaCampo.setBackground(new Color(60, 63, 65));
        cargaCampo.setForeground(Color.WHITE);
        frame.add(cargaCampo);

        JButton calcularBotao = new JButton("Descobrir Carga");
        calcularBotao.setBounds(175, 230, 150, 40);
        calcularBotao.setFont(new Font("Arial", Font.BOLD, 16));
        calcularBotao.setBackground(new Color(255, 215, 0));
        calcularBotao.setForeground(Color.BLACK);
        frame.add(calcularBotao);

        JPanel painelResultado = new JPanel();
        painelResultado.setBounds(50, 290, 400, 80);
        painelResultado.setBackground(new Color(50, 50, 50));
        painelResultado.setBorder(BorderFactory.createLineBorder(new Color(255, 215, 0), 2));
        frame.add(painelResultado);

        JLabel resultadoLabel = new JLabel("O valor da carga elétrica Q será exibido aqui.");
        resultadoLabel.setForeground(new Color(135, 206, 250));
        resultadoLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        painelResultado.add(resultadoLabel);

        calcularBotao.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double massa = Double.parseDouble(massaCampo.getText());
                    double velocidade = Double.parseDouble(velocidadeCampo.getText());
                    double raio = Double.parseDouble(raioCampo.getText());
                    double carga = Double.parseDouble(cargaCampo.getText());

                    double cargaNecessaria = (massa * velocidade * velocidade * raio) / (k_e * carga);

                    resultadoLabel.setText(String.format("A carga necessária é Q = %.4e C", cargaNecessaria));
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Por favor, insira valores válidos!", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setVisible(true);
    }
}
