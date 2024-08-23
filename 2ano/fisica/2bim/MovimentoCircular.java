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

        JLabel titleLabel = new JLabel("Cálculo de Carga Elétrica", JLabel.CENTER);
        titleLabel.setBounds(50, 10, 400, 40);
        titleLabel.setForeground(new Color(255, 255, 0));
        titleLabel.setFont(new Font("Arial", Font.BOLD, 22));
        frame.add(titleLabel);

        JLabel massLabel = new JLabel("Massa do objeto (kg):");
        massLabel.setBounds(50, 60, 200, 25);
        massLabel.setForeground(Color.WHITE);
        massLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(massLabel);

        JTextField massField = new JTextField();
        massField.setBounds(250, 60, 150, 25);
        massField.setBackground(new Color(60, 63, 65));
        massField.setForeground(Color.WHITE);
        frame.add(massField);

        JLabel velocityLabel = new JLabel("Velocidade (m/s):");
        velocityLabel.setBounds(50, 100, 200, 25);
        velocityLabel.setForeground(Color.WHITE);
        velocityLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(velocityLabel);

        JTextField velocityField = new JTextField();
        velocityField.setBounds(250, 100, 150, 25);
        velocityField.setBackground(new Color(60, 63, 65));
        velocityField.setForeground(Color.WHITE);
        frame.add(velocityField);

        JLabel radiusLabel = new JLabel("Raio da órbita (m):");
        radiusLabel.setBounds(50, 140, 200, 25);
        radiusLabel.setForeground(Color.WHITE);
        radiusLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(radiusLabel);

        JTextField radiusField = new JTextField();
        radiusField.setBounds(250, 140, 150, 25);
        radiusField.setBackground(new Color(60, 63, 65));
        radiusField.setForeground(Color.WHITE);
        frame.add(radiusField);

        JLabel chargeLabel = new JLabel("Carga do objeto (C):");
        chargeLabel.setBounds(50, 180, 200, 25);
        chargeLabel.setForeground(Color.WHITE);
        chargeLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(chargeLabel);

        JTextField chargeField = new JTextField();
        chargeField.setBounds(250, 180, 150, 25);
        chargeField.setBackground(new Color(60, 63, 65));
        chargeField.setForeground(Color.WHITE);
        frame.add(chargeField);

        JButton calculateButton = new JButton("Descobrir Carga");
        calculateButton.setBounds(175, 230, 150, 40);
        calculateButton.setFont(new Font("Arial", Font.BOLD, 16));
        calculateButton.setBackground(new Color(255, 215, 0));
        calculateButton.setForeground(Color.BLACK);
        frame.add(calculateButton);

        JPanel resultPanel = new JPanel();
        resultPanel.setBounds(50, 290, 400, 80);
        resultPanel.setBackground(new Color(50, 50, 50));
        resultPanel.setBorder(BorderFactory.createLineBorder(new Color(255, 215, 0), 2));
        frame.add(resultPanel);

        JLabel resultLabel = new JLabel("O valor da carga elétrica Q será exibido aqui.");
        resultLabel.setForeground(new Color(135, 206, 250));
        resultLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        resultPanel.add(resultLabel);

        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double m = Double.parseDouble(massField.getText());
                    double v = Double.parseDouble(velocityField.getText());
                    double r = Double.parseDouble(radiusField.getText());
                    double q = Double.parseDouble(chargeField.getText());

                    double Q = (m * v * v * r) / (k_e * q);

                    resultLabel.setText(String.format("A carga necessária é Q = %.4e C", Q));
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Por favor, insira valores válidos!", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setVisible(true);
    }
}
