import java.sql.*;

public class CursoDAO {
    public Curso curso;
    public BD bd;
    private PreparedStatement statement;
    private ResultSet resultSet;
    private String men, sql;
    public static final byte INCLUSAO = 1;
    public static final byte ALTERACAO = 2;
    public static final byte EXCLUSAO = 3;

    public CursoDAO() {
        bd = new BD();
        curso = new Curso();
    }

    public boolean localizar(int codigo) {
        sql = "select * from cursos where codigo = ?";
        try {
            statement = bd.connection.prepareStatement(sql);
            statement.setInt(1, codigo);
            resultSet = statement.executeQuery();

            if (resultSet.next()) {
                curso.setCodigo(resultSet.getInt("codigo"));
                curso.setNome(resultSet.getString("nome"));
                curso.setCargaHoraria(resultSet.getInt("carga_horaria"));
                curso.setTipo(resultSet.getString("tipo"));
                curso.setModalidade(resultSet.getString("modalidade"));
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
                sql = "insert into cursos (codigo, nome, carga_horaria, tipo, modalidade) values (?, ?, ?, ?, ?)";
                statement = bd.connection.prepareStatement(sql);
                statement.setInt(1, curso.getCodigo());
                statement.setString(2, curso.getNome());
                statement.setInt(3, curso.getCargaHoraria());
                statement.setString(4, curso.getTipo());
                statement.setString(5, curso.getModalidade());

            } else if (operacao == ALTERACAO) {
                sql = "update cursos set nome = ?, carga_horaria = ?, tipo = ?, modalidade = ? where codigo = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, curso.getNome());
                statement.setInt(2, curso.getCargaHoraria());
                statement.setString(3, curso.getTipo());
                statement.setString(4, curso.getModalidade());
                statement.setInt(5, curso.getCodigo());

            } else if (operacao == EXCLUSAO) {
                sql = "delete from cursos where codigo = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setInt(1, curso.getCodigo());
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
