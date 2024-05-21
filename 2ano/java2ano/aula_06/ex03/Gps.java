import java.util.Scanner;

public class Gps{
    Scanner s = new Scanner(System.in);
    private String idioma;
    private String rota;

    public Gps(){
        this.idioma = "Portugues";
        this.rota = "Nenhuma definida";
    }
    public Gps(String rota){
        this.idioma = "Portugues";
        this.rota = rota;
    }

    public void definirRota(String rota){
        this.rota = rota;
        System.out.printf("Rota definida para: %s\n",this.rota);
    }
}