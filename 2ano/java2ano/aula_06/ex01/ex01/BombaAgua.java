package ex01;
public class BombaAgua {
    boolean status;

    public void ligar(){
        this.status = true;
        System.out.println("Bomba Ligada");

    }
    public void desligar(){
        this.status = false;
        System.out.println("Bomba Desligada.");
    }

    
    public void intervaloBomba(int tempo){
        for(int i=tempo;i>0;i--){
            System.out.printf("Bomba ligada.Tempo restante: %d\n",i);
        }
        
    }

}
