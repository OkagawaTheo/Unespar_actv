import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DisciplinaDAO {
    public Disciplina disciplina;
    public BD bd;
    private PreparedStatement statement;
    private ResultSet resultSet;
    private String men, sql;
    public static final byte INCLUSAO = 1;
    public static final byte ALTERACAO = 2;
    public static final byte EXCLUSAO = 3;

    public DisciplinaDAO() {
        bd = new BD();
        disciplina = new Disciplina();
    }

    public boolean localizar() {
        sql = "SELECT * FROM disciplinas WHERE id_disciplina = ?";
        try {
            statement = bd.connection.prepareStatement(sql);
            statement.setString(1, disciplina.getIdDisciplina());
            resultSet = statement.executeQuery();
            if (resultSet.next()) {
                disciplina.setIdDisciplina(resultSet.getString(1));
                disciplina.setIdCurso(resultSet.getString(2));
                disciplina.setNome(resultSet.getString(3));
                disciplina.setCargaHoraria(resultSet.getInt(4));
                disciplina.setAreaMateria(resultSet.getString(5));
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
                sql = "INSERT INTO disciplinas (id_disciplina, id_curso, nome, carga_horaria, area_materia) VALUES (?,?,?,?,?)";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, disciplina.getIdDisciplina());
                statement.setString(2, disciplina.getIdCurso());
                statement.setString(3, disciplina.getNome());
                statement.setInt(4, disciplina.getCargaHoraria());
                statement.setString(5, disciplina.getAreaMateria());
            } else if (operacao == ALTERACAO) {
                sql = "UPDATE disciplinas SET id_curso = ?, nome = ?, carga_horaria = ?, area_materia = ? WHERE id_disciplina = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, disciplina.getIdCurso());
                statement.setString(2, disciplina.getNome());
                statement.setInt(3, disciplina.getCargaHoraria());
                statement.setString(4, disciplina.getAreaMateria());
                statement.setString(5, disciplina.getIdDisciplina());
            } else if (operacao == EXCLUSAO) {
                sql = "DELETE FROM disciplinas WHERE id_disciplina = ?";
                statement = bd.connection.prepareStatement(sql);
                statement.setString(1, disciplina.getIdDisciplina());
            }
            if (statement.executeUpdate() == 0) {
                men = "Falha na operação!";
            }
        } catch (SQLException erro) {
            men = "Falha na operação: " + erro.toString();
        }
        return men;
    }
    
    public List<Disciplina> listar() {
        List<Disciplina> disciplinas = new ArrayList<>();
        sql = "SELECT * FROM disciplinas";
        try {
            statement = bd.connection.prepareStatement(sql);
            resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Disciplina d = new Disciplina();
                d.setIdDisciplina(resultSet.getString(1));
                d.setIdCurso(resultSet.getString(2));
                d.setNome(resultSet.getString(3));
                d.setCargaHoraria(resultSet.getInt(4));
                d.setAreaMateria(resultSet.getString(5));
                disciplinas.add(d);
            }
        } catch (SQLException erro) {
            men = "Falha na operação: " + erro.toString();
        }
        return disciplinas;
    }
}
