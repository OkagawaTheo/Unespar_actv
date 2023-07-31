public class Main{
    public static void main(String args[]) {
        int j = 7;
        for (int i=1;i<=9;i+=2){
            for (int k=j;k>=j-2;k--){
                System.out.printf("I=%d J=%d\n",i,k);
            }
            j += 2;
        }
    }
}