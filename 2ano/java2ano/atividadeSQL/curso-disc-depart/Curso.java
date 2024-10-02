import java.util.ArrayList;
import java.util.List;

public class Curso {
    private String idCurso;
    private String nome;
    private int cargaHoraria;
    private String tipo;
    private String modalidade;
    private String deptoCodigo; // chave estrangeira
    private List<Disciplina> disciplinas; // lista de disciplinas

    public Curso() {
        disciplinas = new ArrayList<>();
    }

    public String getIdCurso() {
        return idCurso;
    }

    public void setIdCurso(String idCurso) {
        this.idCurso = idCurso;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCargaHoraria() {
        return cargaHoraria;
    }

    public void setCargaHoraria(int cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getModalidade() {
        return modalidade;
    }

    public void setModalidade(String modalidade) {
        this.modalidade = modalidade;
    }

    public String getDeptoCodigo() {
        return deptoCodigo;
    }

    public void setDeptoCodigo(String deptoCodigo) {
        this.deptoCodigo = deptoCodigo;
    }

    public List<Disciplina> getDisciplinas() {
        return disciplinas;
    }

    public void addDisciplina(Disciplina disciplina) {
        disciplinas.add(disciplina);
    }

    public void removeDisciplina(Disciplina disciplina) {
        disciplinas.remove(disciplina);
    }
}
