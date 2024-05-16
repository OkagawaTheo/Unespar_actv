import ex01.BombaAgua;
public class Main{
    public static void main(String args[]){
        BombaAgua bomba = new BombaAgua();
        
        bomba.ligar();
        bomba.intervaloBomba(5);
        bomba.desligar();
    }

}