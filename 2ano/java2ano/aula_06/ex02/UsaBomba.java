import ex01.BombaAgua;

public class UsaBomba{
    public static void main(String args[]){
        BombaAgua bomba1 = new BombaAgua(); 
        bomba1.ligar();
        bomba1.intervaloBomba(5);
        bomba1.desligar();
    }
    
}
