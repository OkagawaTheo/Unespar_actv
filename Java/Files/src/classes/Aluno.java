package classes;

public class Aluno {
    public String nome;
    int idade;
    Curso curso;

    String getReg(){return this.nome + ";" + this.idade + ";" + this.curso.nome;}
}
