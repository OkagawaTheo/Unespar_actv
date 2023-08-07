import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int inter = 0;
        int gremio = 0;
        boolean flag = true;
        int ng,cont=1; 
        int v_inter = 0,v_gremio=0,empate=0;

        while (flag){
            inter = s.nextInt();
            gremio = s.nextInt();

            if (inter > gremio)v_inter++;
            else if (gremio > inter)v_gremio++;
            else empate++;
            
            System.out.println("Novo grenal (1-sim 2-nao)");
            ng = s.nextInt();

            if (ng == 1){
                cont++;
                continue;
            }

            else if (ng == 2){
                System.out.printf("%d grenais\n",cont);
                System.out.printf("Inter:%d\n",v_inter);
                System.out.printf("Gremio:%d\n",v_gremio);
                System.out.printf("Empates:%d\n",empate);
                if (v_inter > v_gremio)System.out.println("Inter venceu mais");
                else if (v_inter == v_gremio)System.out.println("Nao houve vencedor");
                else System.out.println("Gremio venceu mais");
                break;
            
            }
        
            

    }
}
}