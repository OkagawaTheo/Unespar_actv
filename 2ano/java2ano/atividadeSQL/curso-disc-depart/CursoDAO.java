import java.sql.*;
import java.util.ArrayList;
import java.util.List;

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

    public boolean localizar() {
        sql = "SELECT * FROM cursos WHERE id_curso = ?";
        try {
            statement = bd.connection.prepareStatement(sql);
            statement.setString(1, curso.getIdCurso());
            resultSet = statement.executeQuery();
            if (resultSet.next()) {
                curso.setIdCurso(resultSet.getString(1));
                curso.setNome(resultSet.getString(2));
                curso.setCargaHoraria(resultSet.getInt(3));
                curso.setTipo(resultSet.getString(4));
                curso.setModalidade(resultSet.getString(5));
                curso.setDeptoCodigo(resultSet.getString(6)); // chave estrangeira
                return true;
            }
        } catch (SQLException erro) {
            men = "Falha na operação: " + erro.toString();
        }
        return false;
    }

    public String atualizar(int operacao) {
        men = "Operação realizada com sucesso!";
        try {
            if (operacao == INCLUSAO) {
                sql = "INSERT INTO cursos (id_curso, nome, carga_horaria, tipo, modalidade, depto_codigo) VALUES (?,?,?,?,?,?)";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, curso.getIdCurso());
                statement.setString(2, curso.getNome());
                statement.setInt(3, curso.getCargaHoraria());
                statement.setString(4, curso.getTipo());
                statement.setString(5, curso.getModalidade());
                statement.setString(6, curso.getDeptoCodigo());
            } else if (operacao == ALTERACAO) {
                sql = "UPDATE cursos SET nome = ?, carga_horaria = ?, tipo = ?, modalidade = ?, depto_codigo = ? WHERE id_curso = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, curso.getNome());
                statement.setInt(2, curso.getCargaHoraria());
                statement.setString(3, curso.getTipo());
                statement.setString(4, curso.getModalidade());
                statement.setString(5, curso.getDeptoCodigo());
                statement.setString(6, curso.getIdCurso());
            } else if (operacao == EXCLUSAO) {
                sql = "DELETE FROM cursos WHERE id_curso = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, curso.getIdCurso());
            }
            if (statement.executeUpdate() == 0) {
                men = "Falha na operação!";
            }
        } catch (SQLException erro) {
            men = "Falha na operação: " + erro.toString();
        }
        return men;
    }
    
    public List<Curso> listar() {
        List<Curso> cursos = new ArrayList<>();
        sql = "SELECT * FROM cursos";
        try {
            statement = bd.connection.prepareStatement(sql);
            resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Curso c = new Curso();
                c.setIdCurso(resultSet.getString(1));
                c.setNome(resultSet.getString(2));
                c.setCargaHoraria(resultSet.getInt(3));
                c.setTipo(resultSet.getString(4));
                c.setModalidade(resultSet.getString(5));
                c.setDeptoCodigo(resultSet.getString(6));
                cursos.add(c);
            }
        } catch (SQLException erro) {
            men = "Falha na operação: " + erro.toString();
        }
        return cursos;
    }
}
