import java.sql.*;
public class ProdutosDAO {
    public Produtos produtos;
    public BD bd;
    private PreparedStatement statement;
    private ResultSet resultSet;
    private String men, sql;
    public static final byte INCLUSAO = 1;
    public static final byte ALTERACAO = 2;
    public static final byte EXCLUSAO =3;

    public ProdutosDAO() {
        bd = new BD ();
        produtos = new Produtos();
    }

    public boolean localizar() {
        sql = "select * from produto where codigo = ?";
        try {
            statement = bd.connection.prepareStatement(sql);
            statement.setString(1, produtos.getCodigo());
            resultSet = statement.executeQuery();
            resultSet.next();
            produtos.setCodigo(resultSet.getString(1));
            produtos.setDescricao(resultSet.getString(2));
            produtos.setPreco(resultSet.getString(3));

            return true;
        } catch (SQLException erro) {
            men = "Falha na operação " + erro.toString();
            return false;
        }
    }

    public String atualizar(int operacao) {
        men = "Operação realizada com sucesso!";
        try {
            if (operacao == INCLUSAO) {
                sql = "insert into produtos values (?,?,?)"; 								
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1,produtos.getCodigo());
                statement.setString(2,produtos.getDescricao());
                statement.setString(3,produtos.getPreco());


            } else if (operacao == ALTERACAO) {
                sql = "update produtos set codigo = ?, descricao = ?, preco = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1,produtos.getCodigo());
                statement.setString(2,produtos.getDescricao());
                statement.setString(3,produtos.getPreco());

            } else if (operacao == EXCLUSAO) {
                sql = "delete from produtos where codigo = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, produtos.getCodigo());
            }
            if (statement.executeUpdate() == 0) {
                men = "Falha na operacao!";
            }
        } catch (SQLException erro) {
            men = "Falha na operação " + erro.toString();
        }
        return men;
    }
}