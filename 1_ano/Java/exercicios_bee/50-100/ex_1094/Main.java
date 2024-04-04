import java.util.Scanner;

public class Main{

    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int total = 0;
        int qtd_casos,num;
        int c=0,r=0,s=0;
        String animal;
        

        qtd_casos = in.nextInt();

        for (int i=0;i<qtd_casos;i++){
            num = in.nextInt();
            animal = in.next().toLowerCase();
            
            if (animal.equals("r")){
                r += num;
            } 
            else if (animal.equals("s")){
                s += num;
            }
            if (animal.equals("c")){
                c += num;
            }
            
        }
        total = r+s+c;
        double percentualRatos = (r * 100.0) / total;
        double percentualSapos = (s * 100.0) / total;
        double percentualCoelhos = (c * 100.0) / total;

        System.out.printf("Total: %d cobaias\n",total);
        System.out.printf("Total de coelhos: %d\n",c);
        System.out.printf("Total de ratos: %d\n",r);
        System.out.printf("Total de sapos: %d\n",s);
        System.out.printf("Percentual de coelhos: %.2f %%\n",percentualCoelhos);
        System.out.printf("Percentual de ratos: %.2f %%\n",percentualRatos);
        System.out.printf("Percentual de sapos: %.2f %%\n",percentualSapos);


        
    }
}