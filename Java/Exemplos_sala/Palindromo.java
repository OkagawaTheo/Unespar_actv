public class Palindromo{
    public static void main(String args[]){
        int maior = 0;
        
        for (int i=100;i < 1000;i++){
            for(int j=100;j < 1000;j++){
                
                String str = Integer.toString(i*j);
                boolean flag = true;

                for (int k=0;k < str.length()/2;k++){
                    if (str.charAt(k) != str.charAt(str.length()-1-k)){
                        flag = false;
                    }
                }
                
                if (flag){
                    if (i*j > maior){
                        maior = i*j;
                    }

                }
            }
        }
        System.out.println(maior);



    }
}