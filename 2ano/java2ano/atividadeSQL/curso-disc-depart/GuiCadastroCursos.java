import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GuiCadastroCursos extends JPanel {
    // Campos e botões
    private JTextField tfCodigo, tfNome;
    private JButton btGravar, btAlterar, btExcluir, btLocalizar, btCancelar;
    
    public GuiCadastroCursos() {
        inicializarComponentes();
    }

    private void inicializarComponentes() {
        setLayout(null);
        
        // Criação de rótulos
        JLabel labelCodigo = new JLabel("Código:");
        labelCodigo.setBounds(10, 10, 100, 20);
        JLabel labelNome = new JLabel("Nome do Curso:");
        labelNome.setBounds(10, 40, 100, 20);
        
        // Criação de campos de texto
        tfCodigo = new JTextField();
        tfCodigo.setBounds(120, 10, 200, 20);
        tfNome = new JTextField();
        tfNome.setBounds(120, 40, 200, 20);
        
        // Criação de botões
        btGravar = new JButton("Gravar");
        btGravar.setBounds(10, 80, 80, 30);
        btAlterar = new JButton("Alterar");
        btAlterar.setBounds(100, 80, 80, 30);
        btExcluir = new JButton("Excluir");
        btExcluir.setBounds(190, 80, 80, 30);
        btLocalizar = new JButton("Localizar");
        btLocalizar.setBounds(280, 80, 100, 30);
        btCancelar = new JButton("Cancelar");
        btCancelar.setBounds(390, 80, 100, 30);
        
        // Adiciona componentes ao painel
        add(labelCodigo);
        add(tfCodigo);
        add(labelNome);
        add(tfNome);
        add(btGravar);
        add(btAlterar);
        add(btExcluir);
        add(btLocalizar);
        add(btCancelar);
        
        // Adicionar eventos (implementação simples para fins de exemplo)
        definirEventos();
    }

    private void definirEventos() {
        btGravar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Lógica para gravar o curso
                JOptionPane.showMessageDialog(null, "Curso gravado!");
            }
        });
        // Adicione outros eventos para Alterar, Excluir, Localizar e Cancelar conforme necessário
    }
}
