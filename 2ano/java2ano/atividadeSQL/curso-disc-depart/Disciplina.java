public class Disciplina {
    private String idDisciplina;
    private String idCurso; // chave estrangeira
    private String nome;
    private int cargaHoraria;
    private String areaMateria;

    public String getIdDisciplina() {
        return idDisciplina;
    }

    public void setIdDisciplina(String idDisciplina) {
        this.idDisciplina = idDisciplina;
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

    public String getAreaMateria() {
        return areaMateria;
    }

    public void setAreaMateria(String areaMateria) {
        this.areaMateria = areaMateria;
    }
}
