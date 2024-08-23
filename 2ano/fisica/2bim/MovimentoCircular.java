import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Font;

public class MovimentoCircular {

    private static final double k_e = 8.99e9;

    public static void main(String[] args) {
        JFrame frame = new JFrame("Cálculo de Carga Q");
        frame.setSize(400, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel massLabel = new JLabel("Massa (kg):");
        massLabel.setBounds(30, 30, 100, 25);
        frame.add(massLabel);

        JTextField massField = new JTextField();
        massField.setBounds(150, 30, 150, 25);
        frame.add(massField);

        JLabel velocityLabel = new JLabel("Velocidade (m/s):");
        velocityLabel.setBounds(30, 70, 120, 25);
        frame.add(velocityLabel);

        JTextField velocityField = new JTextField();
        velocityField.setBounds(150, 70, 150, 25);
        frame.add(velocityField);

        JLabel radiusLabel = new JLabel("Raio (m):");
        radiusLabel.setBounds(30, 110, 100, 25);
        frame.add(radiusLabel);

        JTextField radiusField = new JTextField();
        radiusField.setBounds(150, 110, 150, 25);
        frame.add(radiusField);

        JLabel chargeLabel = new JLabel("Carga q (C):");
        chargeLabel.setBounds(30, 150, 100, 25);
        frame.add(chargeLabel);

        JTextField chargeField = new JTextField();
        chargeField.setBounds(150, 150, 150, 25);
        frame.add(chargeField);

        JButton calculateButton = new JButton("Calcular Q");
        calculateButton.setBounds(120, 200, 150, 40);
        calculateButton.setFont(new Font("Arial", Font.BOLD, 16));
        frame.add(calculateButton);

        JLabel resultLabel = new JLabel("Q (C):");
        resultLabel.setBounds(30, 260, 300, 25);
        resultLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        frame.add(resultLabel);

        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double m = Double.parseDouble(massField.getText());
                    double v = Double.parseDouble(velocityField.getText());
                    double r = Double.parseDouble(radiusField.getText());
                    double q = Double.parseDouble(chargeField.getText());

                    double Q = (m * v * v * r) / (k_e * q);

                    resultLabel.setText(String.format("Q (C): %.4e", Q));
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Por favor, insira valores válidos!", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setVisible(true);
    }
}
