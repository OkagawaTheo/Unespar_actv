package classes;

public class Aluno {
    public String nome;
    public int idade;
    public Curso curso;

    public String getReg(){return this.nome + ";" + this.idade + ";" + this.curso.nome;}

}
