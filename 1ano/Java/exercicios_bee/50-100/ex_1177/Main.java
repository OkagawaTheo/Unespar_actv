import java.util.Scanner;

public class Main{

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int[] n = new int[1000];
        int pos = 0;
        while (pos < 999) {
        	for (int j = 0; j < x; j++) {
        		if (pos > 999) break;
        		n[pos] = j;
        		pos++;
        	}
        }
        
        for (int i = 0; i < n.length; i++) {
            System.out.printf("n[%d] = %d\n",i,n[i]);
            
        }
        
    }
	
}