import javax.swing.*;
import java.awt.*;

public class GuiCursos extends JPanel {
    public GuiCursos(Container parent, JMenuBar menuBarPrincipal) {
        setLayout(new BorderLayout());
        JLabel label = new JLabel("Sistema de Cursos", JLabel.CENTER);
        add(label, BorderLayout.CENTER);
        // Outros componentes específicos do sistema de cursos podem ser adicionados aqui
    }
}
