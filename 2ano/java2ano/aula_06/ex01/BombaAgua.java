public class BombaAgua {

    boolean status;

    void ligar(){
        this.status = true;
        System.out.println("Bomba Ligada");

    }
    void desligar(){
        this.status = false;
        System.out.println("Bomba Desligada.");
    }

    
    void intervaloBomba(){
        for(int i=10;i>0;i--){
            System.out.printf("Bomba ligada.Tempo restante: %d\n",i);
        }
        
    }

}
