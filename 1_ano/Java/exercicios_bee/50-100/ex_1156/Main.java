public class Main {
    public static void main(String[] args) {

        double n = 1;
    	int aux = 2;
    	for (int i = 3; i <= 39; i++) {
    		if (i % 2 == 1)  {
    			n += (double) i / aux;
        		aux *= 2.00;
    		}
    	}
    	System.out.printf("%.2f\n",n);
        
    }
}
