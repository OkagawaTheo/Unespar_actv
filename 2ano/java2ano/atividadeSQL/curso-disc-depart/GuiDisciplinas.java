import javax.swing.*;
import java.awt.*;

public class GuiDisciplinas extends JPanel {
    public GuiDisciplinas(Container parent, JMenuBar menuBarPrincipal) {
        setLayout(new BorderLayout());
        JLabel label = new JLabel("Sistema de Disciplinas", JLabel.CENTER);
        add(label, BorderLayout.CENTER);
        // Outros componentes específicos do sistema de disciplinas podem ser adicionados aqui
    }
}
