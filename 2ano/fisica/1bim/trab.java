import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class trab extends JFrame {

    private static final double GRAVIDADE = 9.8; 
    private static final double MASSA_ELO = 0.1; 
    private static final double ALTURA_ELO = 0.1; 

    private JTextField alturaField;
    private JTextField numeroElosField;
    private JTextField forcaMaximaField;

    private JTextField massaTotalEloField;
    private JTextField massaCargaField;

    public trab() {
        setTitle("Calculadora de Puxar Corrente");
        setSize(600, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(1, 2));


        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(4, 2));
        
        inputPanel.add(new JLabel("Altura (m):"));
        alturaField = new JTextField();
        inputPanel.add(alturaField);
        
        inputPanel.add(new JLabel("Número de Elos:"));
        numeroElosField = new JTextField();
        numeroElosField.setEditable(false);
        inputPanel.add(numeroElosField);
        
        inputPanel.add(new JLabel("Força Máxima (N):"));
        forcaMaximaField = new JTextField();
        inputPanel.add(forcaMaximaField);
        
        JButton calculateButton = new JButton("Calcular");
        calculateButton.addActionListener(new CalculateButtonListener());
        inputPanel.add(calculateButton);
        
        JPanel outputPanel = new JPanel();
        outputPanel.setLayout(new GridLayout(1, 2));
        
        outputPanel.add(new JLabel("Massa Total dos Elos (kg):"));
        massaTotalEloField = new JTextField();
        massaTotalEloField.setEditable(false);
        outputPanel.add(massaTotalEloField);
        
        outputPanel.add(new JLabel("Massa da Carga (kg):"));
        massaCargaField = new JTextField();
        massaCargaField.setEditable(false);
        outputPanel.add(massaCargaField);
        
        add(inputPanel);
        add(outputPanel);
    }

    private class CalculateButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                double altura = Double.parseDouble(alturaField.getText());
                int numeroElos = (int) (altura / ALTURA_ELO);
                int forcaMaxima = Integer.parseInt(forcaMaximaField.getText());

                double massaTotalElo = numeroElos * MASSA_ELO;
                double massaCarga = calcularMassaCarga(forcaMaxima, numeroElos);

                numeroElosField.setText(String.valueOf(numeroElos));
                massaTotalEloField.setText(String.format("%.2f", massaTotalElo));
                massaCargaField.setText(String.format("%.2f", massaCarga));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(trab.this, "Por favor, insira valores válidos.", "Erro de Formato", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private double calcularMassaCarga(int forcaMaxima, int numeroElos) {
        double massaTotalElo = numeroElos * MASSA_ELO;
        double forcaElos = massaTotalElo * GRAVIDADE;
        return (forcaMaxima - forcaElos) / GRAVIDADE;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new trab().setVisible(true);
            }
        });
    }
}
