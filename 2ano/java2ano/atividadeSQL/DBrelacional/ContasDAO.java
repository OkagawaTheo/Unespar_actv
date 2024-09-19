import java.sql.*;

public class ContasDAO {
    public Contas conta;
    public BD bd;
    private PreparedStatement statement;
    private ResultSet resultSet;
    private String men, sql;
    public static final byte INCLUSAO = 1;
    public static final byte ALTERACAO = 2;
    public static final byte EXCLUSAO = 3;

    public ContasDAO() {
        bd = new BD();
        conta = new Contas();
    }

    public boolean localizar(int numero) {
        sql = "select * from contas where numero = ?";
        try {
            statement = bd.connection.prepareStatement(sql);
            statement.setInt(1, numero); // Substituí o 'getCodigo' por 'numero'
            resultSet = statement.executeQuery();

            if (resultSet.next()) {
                conta.setNumero(resultSet.getInt("numero"));
                conta.setTitular(resultSet.getString("titular"));
                conta.setSaldo(resultSet.getDouble("saldo"));
                conta.setTipo(resultSet.getString("tipo"));
                return true;
            } else {
                return false;
            }
        } catch (SQLException erro) {
            men = "Falha na operação " + erro.toString();
            return false;
        }
    }

    public String atualizar(int operacao) {
        men = "Operação realizada com sucesso!";
        try {
            if (operacao == INCLUSAO) {
                sql = "insert into contas (numero, titular, saldo, tipo) values (?, ?, ?, ?)";
                statement = bd.connection.prepareStatement(sql);
                statement.setInt(1, conta.getNumero());
                statement.setString(2, conta.getTitular());
                statement.setDouble(3, conta.getSaldo());
                statement.setString(4, conta.getTipo());

            } else if (operacao == ALTERACAO) {
                sql = "update contas set titular = ?, saldo = ?, tipo = ? where numero = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, conta.getTitular());
                statement.setDouble(2, conta.getSaldo());
                statement.setString(3, conta.getTipo());
                statement.setInt(4, conta.getNumero());

            } else if (operacao == EXCLUSAO) {
                sql = "delete from contas where numero = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setInt(1, conta.getNumero());
            }

            if (statement.executeUpdate() == 0) {
                men = "Falha na operação!";
            }
        } catch (SQLException erro) {
            men = "Falha na operação " + erro.toString();
        }
        return men;
    }
}
