
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class GuiCadastroProdutos extends JFrame {
    JLabel label1, label2, label3;
    JButton btGravar, btAlterar, btExcluir, btNovo, btLocalizar, btCancelar, btSair;
    static JTextField tfCodigo,tfDescricao,tfPreco;
    private ProdutosDAO produtos;

    public static void main(String[] args) {
        JFrame janela = new GuiCadastroProdutos();
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setVisible(true);
    }

    public GuiCadastroProdutos() {
        inicializarComponentes();
        definirEventos();
    }

    public void inicializarComponentes() {
        setLayout(new FlowLayout(FlowLayout.LEFT));
        setBounds(200, 200, 630, 100);
        setTitle("Cadastramento de produtos");
        label1 = new JLabel("Código");
        label2 = new JLabel("Descrição");
        label3 = new JLabel("Preço");
        tfCodigo = new JTextField(8);
        tfDescricao = new JTextField(25);
        tfPreco = new JTextField(10);
        //btGravar = new JButton(null, new Imagelcon("gravar.gif"));
        btGravar = new JButton("Gravar");
        btGravar.setToolTipText("Gravar");
        //btAlterar = new JButton(null, new Imagelcon("alterar.gif"));
        btAlterar = new JButton ("Alterar");
        btAlterar.setToolTipText("Alterar");
        //btExcluir = new JButton(null, new Imagelcon("excluir.gif"));
        btExcluir = new JButton("Excluir");
        btExcluir.setToolTipText("Excluir");
        //btLocalizar = new JButton(null, new Imagelcon("localizar.png"));
        btLocalizar = new JButton("Localizar");
        btLocalizar.setToolTipText("Localizar");
        //btNovo = new JButton(null, new Imagelcon("novo.gif"));
        btNovo = new JButton("Novo");
        btNovo.setToolTipText("Novo");
        //btCancelar = new JButton(null, new Imagelcon("cancelar.gif"));
        btCancelar = new JButton("Cancelar");
        btCancelar.setToolTipText("Cancelar");
        //btSair = new JButton(null, new Imagelcon("sair.png"));
        btSair = new JButton("Sair");
        btSair.setToolTipText("Sair");
        add(label1);
        add(tfCodigo);
        add(label2);
        add(tfDescricao);
        add(label3);
        add(tfPreco);
        add(btNovo);
        add(btLocalizar);
        add(btGravar);
        add(btAlterar);
        add(btExcluir);
        add(btCancelar);
        add(btSair);
        setResizable(false);
        setBotoes(true, true, false, false, false,false);
        produtos = new ProdutosDAO();
        if (!produtos.bd.getConnection()) {
            JOptionPane.showMessageDialog(null, "Falha na conexão, o sistema será fechado!");
            System.exit(0);
        }
    }

    public void definirEventos () {
        btSair.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                produtos.bd.close();
                System.exit(0);
            }
        });

        btNovo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                limparCampos();
                setBotoes(false, false, true, false, false, true);
            }
        });

        btCancelar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                limparCampos();
            }
        });

        btGravar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (tfCodigo.getText().equals("")) {
                    JOptionPane.showMessageDialog(null, "O campo código não pode ser vazio!");
                    tfCodigo.requestFocus();
                    return;
                }
                if (tfDescricao.getText().equals("")) {
                    JOptionPane.showMessageDialog(null, "O campo descrição não pode ser vazio!");
                    tfDescricao.requestFocus();
                    return;
                }
                if (tfPreco.getText().equals("")) {
                    JOptionPane.showMessageDialog(null, "O campo preço não pode ser vazio!");
                    tfPreco.requestFocus();
                    return;
                }
                produtos.produtos.setCodigo(tfCodigo.getText());
                produtos.produtos.setDescricao(tfDescricao.getText());
                produtos.produtos.setPreco(tfPreco.getText());
                JOptionPane.showMessageDialog(null, produtos.atualizar(ProdutosDAO.INCLUSAO));
                limparCampos();
            }
        });

        btAlterar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                produtos.produtos.setCodigo(tfCodigo.getText());
                produtos.produtos.setDescricao(tfDescricao.getText());
                produtos.produtos.setPreco(tfPreco.getText());
                JOptionPane.showMessageDialog(null, produtos.atualizar(ProdutosDAO.ALTERACAO));
                limparCampos();
            }
        });
        btExcluir.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                produtos.produtos.setCodigo(tfCodigo.getText());
                produtos.localizar();
                int n = JOptionPane.showConfirmDialog(null, produtos.produtos.getDescricao(), " Excluir o produtos?",
                        JOptionPane.YES_NO_OPTION);
                if (n == JOptionPane.YES_OPTION) {
                    JOptionPane.showMessageDialog(null, produtos.atualizar(ProdutosDAO.EXCLUSAO));
                    limparCampos();
                }
            }
        });

        btLocalizar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                atualizarCampos();
            }
        });
    }

    public void limparCampos() {
        tfCodigo.setText("");
        tfDescricao.setText("");
        tfPreco.setText("");
        tfCodigo.requestFocus();
        setBotoes(true, true, false, false, false, false);
    }

    public void atualizarCampos() {
        produtos.produtos.setCodigo(tfCodigo.getText());
        if (produtos.localizar()) {
            tfCodigo.setText(produtos.produtos.getCodigo());
            tfDescricao.setText(produtos.produtos.getDescricao());
            tfPreco.setText(produtos.produtos.getPreco());
            setBotoes(true, true, false, true, true, true);
        } else {
            JOptionPane.showMessageDialog(null, "produtos não encontrado!");
            limparCampos();
        }
    }
    public void setBotoes(boolean bNovo, boolean bLocalizar, boolean bGravar, boolean bAlterar,
                          boolean bExcluir, boolean bCancelar) {
        btNovo.setEnabled(bNovo);
        btLocalizar.setEnabled(bLocalizar);
        btGravar.setEnabled(bGravar);
        btAlterar.setEnabled(bAlterar);
        btExcluir.setEnabled(bExcluir);
        btCancelar.setEnabled(bCancelar);
    }

}